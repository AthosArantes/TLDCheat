#include "cheat.h"
#include "distormx/distormx.h"
#include "fmt/format.h"
#include <algorithm>
#include <memory>

std::unique_ptr<Game::Cheat> gCheat;

namespace Game
{
	Cheat::Cheat() = default;

	Cheat::~Cheat()
	{
		SetSteadyCamera(false);
		RemoveHooks();
	}

	void Cheat::UpdateRVA(void* hmodule)
	{
		// You can get updated offsets using ill2cppdumper

		_Encoding_get_UTF8 = (char*)hmodule + 0xEFD2A0;
		_String_CreateStringFromEncoding = (char*)hmodule + 0x9A4790;
		_Input_GetKey = (char*)hmodule + 0x1092A00;
		_Input_GetKeyUp = (char*)hmodule + 0x1092A50;
		_Input_GetKeyDown = (char*)hmodule + 0x1092AA0;
		_GameManager_UpdateNotPaused = (char*)hmodule + 0x15CA200;
		_PlayerManager_DoPositionCheck = (char*)hmodule + 0x15799A0;
		_Panel_HUD_Update = (char*)hmodule + 0x16ABED0;
		_Panel_HUD_ShowSubtitlesForced = (char*)hmodule + 0x16B05B0;
		_Panel_HUD_HideSubtitles = (char*)hmodule + 0x16B09B0;
		_HUDManager_ShouldHideCrossHairs = (char*)hmodule + 0x1A86840;
		_BodyDamage_GetChanceKill = (char*)hmodule + 0x1CAA880;
		_Inventory_ProcessItems = (char*)hmodule + 0x17EC3C0;
		_Utils_GetTotalWeightKG = (char*)hmodule + 0x1A2E3D0;
		_GearItem_Degrade = (char*)hmodule + 0x1CD4460;
		_KeroseneLampItem_ReduceFuel = (char*)hmodule + 0x1803880;
		_PlayerMovement_GetSnowDepthMovementMultiplier = (char*)hmodule + 0x17B3AF0;
		_vpFPSWeapon_SetDisableAimBreathing = (char*)hmodule + 0x1FFBC00;
		_vpFPSWeapon_SetDisableAimSway = (char*)hmodule + 0x1FFBC90;
		_vpFPSWeapon_SetDisableAimStamina = (char*)hmodule + 0x1FFBD20;
		_vpFPSWeapon_SetDisableAimShake = (char*)hmodule + 0x1FFBDB0;
		_vpFPSWeapon_SetDisableDepthOfField = (char*)hmodule + 0x1FFBE40;
		_vpFPSCamera_SetDisableAmbientSway = (char*)hmodule + 0x1D99040;
		_Panel_Inventory_Update = (char*)hmodule + 0x16C87D0;
		_Panel_Inventory_MarkDirty = (char*)hmodule + 0x16CBCB0;
		_Panel_Inventory_IsEnabled = (char*)hmodule + 0x16CBCF0;
		_Panel_Inventory_GetCurrentlySelectedGearItem = (char*)hmodule + 0x16CFD10;
	}

	void Cheat::InstallHooks()
	{
		// Hook the main game loop
		distormx_hook((void**)&_GameManager_UpdateNotPaused, (void*)static_cast<void (*)(GameManager*)>([](GameManager* game_manager)
		{
			gCheat->OnUpdate(game_manager);
		}));

		// Always show crosshair
		distormx_hook((void**)&_HUDManager_ShouldHideCrossHairs, (void*)static_cast<bool (*)(HUDManager*)>([](HUDManager* hud_manager) -> bool
		{
			if (gCheat->alwaysShowCrosshair)
			{
				hud_manager->m_CrosshairAlpha = 1.0f;
				return false;
			}
			return gCheat->_HUDManager_ShouldHideCrossHairs(hud_manager);
		}));

		// One-hit kill
		distormx_hook((void**)&_BodyDamage_GetChanceKill, (void*)static_cast<int32_t(*)(BodyDamage*, BodyPart, BodyDamage::Weapon)>([](BodyDamage* damage, BodyPart part, BodyDamage::Weapon weapon) -> int32_t
		{
			if (gCheat->oneHitKill)
			{
				return 100;
			}
			return gCheat->_BodyDamage_GetChanceKill(damage, part, weapon);
		}));

		// Never degrade
		distormx_hook((void**)&_GearItem_Degrade, (void*)static_cast<void (*)(GearItem*, float)>([](GearItem* item, float hp)
		{
			if (!gCheat->neverDegradeItems)
			{
				gCheat->_GearItem_Degrade(item, hp);
			}
		}));

		// Unlimited backpack
		distormx_hook((void**)&_Inventory_ProcessItems, (void*)static_cast<void (*)(Inventory*)>([](Inventory* inventory)
		{
			gCheat->_Inventory_ProcessItems(inventory);
			if (gCheat->unlimitedBackpack)
			{
				inventory->m_TotalWeight = 0.0f;
			}
		}));

		// Unlimited storage
		distormx_hook((void**)&_Utils_GetTotalWeightKG, (void*)static_cast<float (*)(List<GearItem>*)>([](List<GearItem>* items) -> float
		{
			if (gCheat->unlimitedStorage)
			{
				return 0.0f;
			}
			return gCheat->_Utils_GetTotalWeightKG(items);
		}));

		// Unlimited lamp fuel
		distormx_hook((void**)&_KeroseneLampItem_ReduceFuel, (void*)static_cast<void (*)(KeroseneLampItem*, float)>([](KeroseneLampItem* lamp, float hours_burned)
		{
			volatile float fuel = lamp->m_CurrentFuelLiters;
			gCheat->_KeroseneLampItem_ReduceFuel(lamp, hours_burned);
			if (gCheat->unlimitedLampFuel)
			{
				lamp->m_CurrentFuelLiters = fuel;
			}
		}));

		// Speed-cheat
		distormx_hook((void**)&_PlayerMovement_GetSnowDepthMovementMultiplier, (void*)static_cast<float (*)(PlayerMovement*)>([](PlayerMovement* /*movement*/) -> float
		{
			return gCheat->playerSpeed;
		}));

		// Place item anywhere
		distormx_hook((void**)&_PlayerManager_DoPositionCheck, (void*)static_cast<MeshLocationCategory(*)(PlayerManager*)>([](PlayerManager* player_manager) -> MeshLocationCategory
		{
			MeshLocationCategory status = gCheat->_PlayerManager_DoPositionCheck(player_manager);
			if (gCheat->placeAnywhere)
			{
				status = MeshLocationCategory::Valid;
			}
			return status;
		}));

		// ==========================================================================================
		// The hooks below are exclusively used to retrieve specific object pointers

		distormx_hook((void**)&_Panel_HUD_Update, (void*)static_cast<void(*)(Panel_HUD*)>([](Panel_HUD* panel)
		{
			gCheat->panelHUD = panel;
			gCheat->_Panel_HUD_Update(panel);
		}));

		distormx_hook((void**)&_Panel_Inventory_Update, (void*)static_cast<void(*)(Panel_Inventory*)>([](Panel_Inventory* panel)
		{
			gCheat->panelInventory = panel;
			gCheat->_Panel_Inventory_Update(panel);
		}));
	}

	void Cheat::RemoveHooks()
	{
		distormx_unhook(&_GameManager_UpdateNotPaused);
		distormx_unhook(&_HUDManager_ShouldHideCrossHairs);
		distormx_unhook(&_BodyDamage_GetChanceKill);
		distormx_unhook(&_GearItem_Degrade);
		distormx_unhook(&_Inventory_ProcessItems);
		distormx_unhook(&_Utils_GetTotalWeightKG);
		distormx_unhook(&_PlayerMovement_GetSnowDepthMovementMultiplier);
		distormx_unhook(&_PlayerManager_DoPositionCheck);
		distormx_unhook(&_Panel_HUD_Update);
		distormx_unhook(&_Panel_Inventory_Update);
		distormx_destroy();
	}

	void Cheat::OnUpdate(GameManager* gm)
	{
		// Call the original update of the game
		_GameManager_UpdateNotPaused(gm);

		// Unhook everything and shutdown the cheat
		if (GetKeyDown(KeyCode::End))
		{
			ShowMessage(u8"Shutting down cheat");
			Release();
			return;
		}

		if (IsInventoryOpen())
		{
			if (GetKeyDown(KeyCode::KeypadPlus))
			{
				ChangeInventoryItem(InventoryItemAction::Increment);
			}
			if (GetKeyDown(KeyCode::KeypadMinus))
			{
				ChangeInventoryItem(InventoryItemAction::Decrement);
			}
			if (GetKeyDown(KeyCode::KeypadMultiply) && IsInventoryOpen())
			{
				ChangeInventoryItem(InventoryItemAction::Repair);
			}
			return;
		}

		// Increase/Decrease player speed.
		if (GetKeyDown(KeyCode::KeypadPlus) || GetKeyDown(KeyCode::KeypadMinus))
		{
			float newSpeed = playerSpeed + (GetKeyDown(KeyCode::KeypadMinus) ? -1.0f : 1.0f);
			newSpeed = std::clamp(newSpeed, 1.0f, MaxPlayerSpeedMultiplier);

			if (newSpeed != playerSpeed)
			{
				playerSpeed = newSpeed;
				ShowMessage(fmt::format(u8"Movement speed set to {:d}x", (int)newSpeed));
			}
		}

		// Toggle crosshairs
		if (GetKeyDown(KeyCode::Keypad0))
		{
			alwaysShowCrosshair = !alwaysShowCrosshair;
			ShowMessage(alwaysShowCrosshair ? u8"Crosshair always visible" : u8"Crosshair not always visible");
		}

		// Toggle one-hit kill cheat
		if (GetKeyDown(KeyCode::Keypad1))
		{
			oneHitKill = !oneHitKill;
			ShowMessage(oneHitKill ? u8"One-hit kill activated" : u8"One-hit kill deactivated");
		}

		// Toggle never-degrade items cheat
		if (GetKeyDown(KeyCode::Keypad2))
		{
			neverDegradeItems = !neverDegradeItems;
			ShowMessage(neverDegradeItems ? u8"Items never degrade" : u8"Items will degrade");
		}

		// Steady camera cheat
		if (GetKeyDown(KeyCode::Keypad3))
		{
			steadyCamera = !steadyCamera;
			SetSteadyCamera(steadyCamera);
			ShowMessage(steadyCamera ? u8"Steady camera activated" : u8"Steady camera deactivated");
		}

		// Unlimited backpack cheat
		if (GetKeyDown(KeyCode::Keypad4))
		{
			unlimitedBackpack = !unlimitedBackpack;
			ShowMessage(unlimitedBackpack ? u8"Unlimited backpack activated" : u8"Unlimited backpack deactivated");
		}

		// Unlimited storage cheat
		if (GetKeyDown(KeyCode::Keypad5))
		{
			unlimitedStorage = !unlimitedStorage;
			ShowMessage(unlimitedStorage ? u8"Unlimited storage activated" : u8"Unlimited storage deactivated");
		}

		// Unlimited lamp fuel cheat
		if (GetKeyDown(KeyCode::Keypad6))
		{
			unlimitedLampFuel = !unlimitedLampFuel;
			ShowMessage(unlimitedLampFuel ? u8"Unlimited lamp fuel activated" : u8"Unlimited lamp fuel deactivated");
		}

		// Place anywhere cheat
		if (GetKeyDown(KeyCode::Keypad7))
		{
			placeAnywhere = !placeAnywhere;
			ShowMessage(placeAnywhere ? u8"Place item anywhere activated" : u8"Place item anywhere deactivated");
		}
	}

	void Cheat::ShowMessage(std::string_view message)
	{
		if (!panelHUD)
		{
			return;
		}

		// Get a default UTF-8 encoding
		Encoding* utf8 = _Encoding_get_UTF8();

		// Create a managed string
		String* str = _String_CreateStringFromEncoding(message.data(), message.length(), utf8);

		// Display it
		_Panel_HUD_ShowSubtitlesForced(panelHUD, str);
		_Panel_HUD_HideSubtitles(panelHUD, 1.0f);
	}

	void Cheat::SetSteadyCamera(bool steady)
	{
		_vpFPSWeapon_SetDisableAimBreathing(steady);
		_vpFPSWeapon_SetDisableAimSway(steady);
		_vpFPSWeapon_SetDisableAimStamina(steady);
		_vpFPSWeapon_SetDisableAimShake(steady);
		_vpFPSWeapon_SetDisableDepthOfField(steady);
		_vpFPSCamera_SetDisableAmbientSway(steady);
	}

	bool Cheat::IsInventoryOpen()
	{
		return panelInventory && _Panel_Inventory_IsEnabled(panelInventory);
	}

	void Cheat::ChangeInventoryItem(InventoryItemAction action)
	{
		GearItem* item = _Panel_Inventory_GetCurrentlySelectedGearItem(panelInventory);
		if (!item)
		{
			return;
		}

		switch (action)
		{
			case InventoryItemAction::Increment: [[fallthrough]];
			case InventoryItemAction::Decrement:
			{
				int32_t inverse = (action == InventoryItemAction::Decrement) ? -1 : 1;

				if (StackableItem* stackable = item->m_StackableItem)
				{
					int32_t& units = stackable->m_Units;
					units += (GetKey(KeyCode::LeftShift) ? 5 : 1) * inverse;
					units = std::max(units, 0);
				}
				else if (WaterSupply* water = item->m_WaterSupply)
				{
					float& amount = water->m_VolumeInLiters;
					amount += (GetKey(KeyCode::LeftShift) ? 1.0f : 0.5f) * inverse;
					amount = std::max(amount, 0.0f);
				}
				else if (LiquidItem* liquid = item->m_LiquidItem)
				{
					float& amount = liquid->m_LiquidLiters;
					amount += (GetKey(KeyCode::LeftShift) ? 0.5f : 0.1f) * inverse;
					amount = std::clamp(amount, 0.0f, liquid->m_LiquidCapacityLiters);
				}
				else if (KeroseneLampItem* lamp = item->m_KeroseneLampItem)
				{
					float& fuel = lamp->m_CurrentFuelLiters;
					fuel += (GetKey(KeyCode::LeftShift) ? 0.5f : 0.1f) * inverse;
					fuel = std::clamp(fuel, 0.0f, lamp->m_MaxFuelLiters);
				}

				_Panel_Inventory_MarkDirty(panelInventory);
				break;
			}
			case InventoryItemAction::Repair:
			{
				item->m_CurrentHP = item->m_MaxHP;
				item->m_WornOut = false;
				_Panel_Inventory_MarkDirty(panelInventory);
				break;
			}
		}
	}

	bool Cheat::GetKey(KeyCode key)
	{
		return _Input_GetKey(key);
	}

	bool Cheat::GetKeyDown(KeyCode key)
	{
		return _Input_GetKeyDown(key);
	}

	bool Cheat::GetKeyUp(KeyCode key)
	{
		return _Input_GetKeyUp(key);
	}

	void Cheat::Initialize(void* hmodule)
	{
		if (gCheat)
		{
			return;
		}
		gCheat = std::make_unique<Cheat>();
		gCheat->UpdateRVA(hmodule);
		gCheat->InstallHooks();
	}

	void Cheat::Release()
	{
		gCheat.reset();
	}
}
