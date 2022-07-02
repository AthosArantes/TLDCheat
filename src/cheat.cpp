#include "cheat.h"
#include "TLD.h"

#include "distormx/distormx.h"
#include <il2cppdump/il2cpp.h>

#include <cstddef>
#include <algorithm>
#include <memory>
#include <string>

// ==========================================================================================
void* (*_Encoding_get_UTF8)();
System_String_o* (*_String_CreateStringFromEncoding)(const char* bytes, uint32_t size, void* encoding);

InterfaceManager_o* (*_InterfaceManager_GetInstance)();
GameManager_o* (*_GameManager_GetInstance)();

bool(*_Input_GetKey)(TLD::KeyCode);
bool(*_Input_GetKeyUp)(TLD::KeyCode);
bool(*_Input_GetKeyDown)(TLD::KeyCode);

void(*_vpFPSWeapon_SetDisableAimBreathing)(bool);
void(*_vpFPSWeapon_SetDisableAimSway)(bool);
void(*_vpFPSWeapon_SetDisableAimStamina)(bool);
void(*_vpFPSWeapon_SetDisableAimShake)(bool);
void(*_vpFPSWeapon_SetDisableDepthOfField)(bool);

void(*_GearManager_DestroyNextUpdate)(GearItem_o*, bool);
void(*_GearManager_DestroyMarkedObjects)();
void(*_GearManager_Update)();
void(*_GearManager_UpdateAll)();

TLD::PlayerControlMode(*_PlayerManager_GetControlMode)(PlayerManager_o*);
void(*_PlayerManager_SetControlMode)(PlayerManager_o*, TLD::PlayerControlMode);
GearItem_o* (*_PlayerManager_InstantiateItemInPlayerInventory)(PlayerManager_o*, GearItem_o*, int32_t numUnits, bool enableNotificationFlag);
bool(*_Panel_Inventory_IsEnabled)(Panel_Inventory_o*);
void(*_Panel_Inventory_MarkDirty)(Panel_Inventory_o*);
void(*_Panel_Subtitles_ShowSubtitlesForced)(Panel_Subtitles_o*, System_String_o*, float duration);

void(*_GameManager_UpdateNotPaused)(GameManager_o*);
bool(*_HUDManager_ShouldHideCrossHairs)(HUDManager_o*);
uint32_t(*_PlayerManager_DoPositionCheck)(PlayerManager_o*);
int32_t(*_BodyDamage_GetChanceKill)(BodyDamage_o*, TLD::BodyPart, TLD::BodyDamageWeapon);
void(*_KeroseneLampItem_ReduceFuel)(KeroseneLampItem_o*, float hoursBurned);
bool(*_FlashlightItem_IsLit)(FlashlightItem_o*);
float(*_FlashlightItem_GetNormalizedCharge)(FlashlightItem_o*);
float(*_PlayerMovement_GetSnowDepthMovementMultiplier)(PlayerMovement_o*);

template <typename T>
void SetFunctionPointer(T& ptrVar, void* hmodule, intptr_t rva)
{
	ptrVar = reinterpret_cast<T>(static_cast<char*>(hmodule) + rva);
}

// ==========================================================================================
namespace Cheat
{
	bool steadyCamera {};
	bool alwaysShowCrosshair {};
	bool placeAnywhere {};
	bool oneHitKill {};
	bool unlimitedLampFuel {};
	bool enableFlashlight {};
	bool allowRevolverAimMove {};

	bool speedHack {};
	float playerSpeedMultiplier {1.0f};

	/*
	bool neverDegradeItems {};
	bool unlimitedBackpack {};
	bool unlimitedStorage {};
	bool fullMapSurvey {};
	*/

	bool shouldUpdateGearManager {};

	void SetSteadyCamera(bool steady)
	{
		_vpFPSWeapon_SetDisableAimBreathing(steady);
		_vpFPSWeapon_SetDisableAimSway(steady);
		_vpFPSWeapon_SetDisableAimStamina(steady);
		_vpFPSWeapon_SetDisableAimShake(steady);
		_vpFPSWeapon_SetDisableDepthOfField(steady);
	};

	void GameManager_Update(GameManager_o* game_manager)
	{
		// Call the original update of the game
		_GameManager_UpdateNotPaused(game_manager);

		InterfaceManager_o* const interface_manager = _InterfaceManager_GetInstance();
		Panel_Inventory_o* const panel_inventory = interface_manager->klass->static_fields->m_Panel_Inventory;
		Panel_Subtitles_o* const panel_subtitles = interface_manager->klass->static_fields->m_Panel_Subtitles;
		PlayerManager_o* const player_manager = game_manager->klass->static_fields->m_PlayerManager;
		vp_FPSCamera_o* const fps_camera = game_manager->klass->static_fields->m_vpFPSCamera;

		if (shouldUpdateGearManager)
		{
			_GearManager_Update();
			_Panel_Inventory_MarkDirty(panel_inventory);
			shouldUpdateGearManager = false;
		}
		if (allowRevolverAimMove)
		{
			TLD::PlayerControlMode mode = _PlayerManager_GetControlMode(player_manager);
			if (mode == TLD::PlayerControlMode::AimRevolver)
			{
				_PlayerManager_SetControlMode(player_manager, TLD::PlayerControlMode::Normal);
			}
		}

		auto ShowMessage = [panel_subtitles](std::string_view message) -> void
		{
			_Panel_Subtitles_ShowSubtitlesForced(panel_subtitles, _String_CreateStringFromEncoding(message.data(), message.size(), _Encoding_get_UTF8()), 4.0f);
		};

		// Inventory cheats
		if (_Panel_Inventory_IsEnabled(panel_inventory))
		{
			InventoryGridItem_array* const items = panel_inventory->fields.m_TableItems;
			const int32_t index = panel_inventory->fields.m_SelectedItemIndexVal;

			if (index < items->max_length)
			{
				InventoryGridItem_o* const selectedGridItem = items->m_Items[index];

				// Actions with selected item
				if (selectedGridItem)
				{
					GearItem_o* const selectedItem = selectedGridItem->fields.m_GearItem;
					StackableItem_o* const stackable = selectedItem->fields.m_StackableItem;
					LiquidItem_o* const liquid = selectedItem->fields.m_LiquidItem;
					bool panelDirty = false;
					bool destroyItem = false;

					const bool shiftDown = _Input_GetKey(TLD::KeyCode::LeftShift);

					// Repair item
					if (_Input_GetKeyDown(TLD::KeyCode::KeypadMultiply))
					{
						if (!selectedItem->fields.m_WornOut)
						{
							selectedItem->fields.m_CurrentHP = selectedItem->fields.m_MaxHP;
							panelDirty = true;
						}
					}

					if (_Input_GetKeyDown(TLD::KeyCode::Insert))
					{
						_PlayerManager_InstantiateItemInPlayerInventory(player_manager, selectedItem, 1, false);
						panelDirty = true;
					}
					else if (_Input_GetKeyDown(TLD::KeyCode::Delete))
					{
						destroyItem = true;
					}
					else if (_Input_GetKeyDown(TLD::KeyCode::KeypadPlus))
					{
						if (stackable)
						{
							++(stackable->fields.m_Units);
							panelDirty = true;
						}
						else if (liquid)
						{
							const float capacity = liquid->fields.m_LiquidCapacityLiters;
							float& liters = liquid->fields.m_LiquidLiters;
							liters += capacity * 0.1f;
							if (liters > capacity)
							{
								liters = capacity;
							}
							panelDirty = true;
						}
					}
					else if (_Input_GetKeyDown(TLD::KeyCode::KeypadMinus))
					{
						if (stackable)
						{
							--(stackable->fields.m_Units);
							panelDirty = true;
						}
						else if (liquid)
						{
							const float capacity = liquid->fields.m_LiquidCapacityLiters;
							float& liters = liquid->fields.m_LiquidLiters;
							liters -= capacity * 0.1f;
							if (liters < 0.0f)
							{
								destroyItem = true;
							}
							else
							{
								panelDirty = true;
							}
						}
					}

					if (destroyItem)
					{
						_GearManager_DestroyNextUpdate(selectedItem, true);
						shouldUpdateGearManager = true;
					}
					else if (panelDirty)
					{
						_Panel_Inventory_MarkDirty(panel_inventory);
					}
				}
			}
			return;
		}

		// Quickly disable all cheats
		if (_Input_GetKeyDown(TLD::KeyCode::End))
		{
			steadyCamera = false;
			alwaysShowCrosshair = false;
			placeAnywhere = false;
			oneHitKill = false;
			unlimitedLampFuel = false;
			enableFlashlight = false;

			SetSteadyCamera(false);

			ShowMessage(u8"Disabled all cheats");
			return;
		}

		/* Increase weapon stats
		{
			vp_FPSWeapon_o* const weapon = fps_camera->fields.m_CurrentWeapon;
			if (weapon)
			{
				GunItem_o* const gunItem = weapon->fields.m_GunItem;
				if (gunItem)
				{
					gunItem->fields.m_AccuracyRange = 100.0f;
					gunItem->fields.m_FiringRateSeconds = 0.25f;
					gunItem->fields.m_SwayValue = 0.0f;
					gunItem->fields.m_SwayIncreasePerSecond = 0.0f;
					gunItem->fields.m_SwayDecreasePerSecond = 0.0f;
				}
			}
		}
		//*/

		// Steady camera cheat
		if (_Input_GetKeyDown(TLD::KeyCode::Keypad0))
		{
			steadyCamera = !steadyCamera;
			SetSteadyCamera(steadyCamera);
			ShowMessage(steadyCamera ? u8"Steady camera activated" : u8"Steady camera deactivated");
		}

		// Toggle crosshairs
		if (_Input_GetKeyDown(TLD::KeyCode::Keypad1))
		{
			alwaysShowCrosshair = !alwaysShowCrosshair;
			ShowMessage(alwaysShowCrosshair ? u8"Crosshair always visible" : u8"Crosshair not always visible");
		}

		// Place anywhere cheat
		if (_Input_GetKeyDown(TLD::KeyCode::Keypad2))
		{
			placeAnywhere = !placeAnywhere;
			ShowMessage(placeAnywhere ? u8"Collision between items disabled" : u8"Collision between items enabled");
		}

		// Toggle one-hit kill cheat
		if (_Input_GetKeyDown(TLD::KeyCode::Keypad3))
		{
			oneHitKill = !oneHitKill;
			ShowMessage(oneHitKill ? u8"One-hit kill activated" : u8"One-hit kill deactivated");
		}

		// Unlimited lamp fuel cheat
		if (_Input_GetKeyDown(TLD::KeyCode::Keypad4))
		{
			unlimitedLampFuel = !unlimitedLampFuel;
			ShowMessage(unlimitedLampFuel ? u8"Unlimited lamp fuel activated" : u8"Unlimited lamp fuel deactivated");
		}

		// Enable flashlight everywhere
		if (_Input_GetKeyDown(TLD::KeyCode::Keypad5))
		{
			enableFlashlight = !enableFlashlight;
			ShowMessage(enableFlashlight ? u8"Flashlight enabled" : u8"Flashlight deactivated");
		}

		// Enable revolver aim movement
		if (_Input_GetKeyDown(TLD::KeyCode::Keypad6))
		{
			allowRevolverAimMove = !allowRevolverAimMove;
			ShowMessage(allowRevolverAimMove ? u8"Movement while aiming Revolver enabled" : u8"Movement while aiming Revolver disabled");
		}

		// Speedhack
		if (_Input_GetKeyDown(TLD::KeyCode::Keypad9))
		{
			speedHack = !speedHack;
			ShowMessage(speedHack ? u8"Speedhack enabled" : u8"Speedhack deactivated");
		}

		if (speedHack)
		{
			int offset = static_cast<int>(_Input_GetKeyDown(TLD::KeyCode::KeypadPlus)) - static_cast<int>(_Input_GetKeyDown(TLD::KeyCode::KeypadMinus));
			if (offset != 0)
			{
				playerSpeedMultiplier = std::clamp(playerSpeedMultiplier + static_cast<float>(offset), 1.0f, 10.0f);

				const char* fmt = "Speedhack set to %fX";
				int szbuf = snprintf(nullptr, 0, fmt, playerSpeedMultiplier);
				std::string msg(szbuf + 1, '0');
				snprintf(msg.data(), szbuf, fmt, playerSpeedMultiplier);

				ShowMessage(msg);
			}
		}
	}

	bool HUDManager_ShouldHideCrossHairs(HUDManager_o* hud_manager)
	{
		bool state = _HUDManager_ShouldHideCrossHairs(hud_manager);
		if (alwaysShowCrosshair)
		{
			hud_manager->fields.m_CrosshairAlpha = 1.0f;
			state = false;
		}
		return state;
	}

	uint32_t PlayerManager_DoPositionCheck(PlayerManager_o* player_manager)
	{
		uint32_t state = _PlayerManager_DoPositionCheck(player_manager);
		if (placeAnywhere && state == static_cast<uint32_t>(TLD::MeshLocationCategory::InvalidTooClose))
		{
			state = static_cast<uint32_t>(TLD::MeshLocationCategory::Valid);
		}
		return state;
	}

	int32_t BodyDamage_GetChanceKill(BodyDamage_o* bodyDamage, TLD::BodyPart bodyPart, TLD::BodyDamageWeapon damageWeapon)
	{
		int32_t chance = _BodyDamage_GetChanceKill(bodyDamage, bodyPart, damageWeapon);
		if (oneHitKill)
		{
			chance = 100;
		}
		return chance;
	}

	void KeroseneLampItem_ReduceFuel(KeroseneLampItem_o* lamp, float hoursBurned)
	{
		const float prevFuel = lamp->fields.m_CurrentFuelLiters;
		_KeroseneLampItem_ReduceFuel(lamp, hoursBurned);
		if (unlimitedLampFuel)
		{
			lamp->fields.m_CurrentFuelLiters = prevFuel;
		}
	}

	bool FlashlightItem_IsLit(FlashlightItem_o* flashlight)
	{
		bool lit = _FlashlightItem_IsLit(flashlight);
		if (enableFlashlight)
		{
			lit = (flashlight->fields.m_State != (int32_t)TLD::FlashlightState::Off);
		}
		return lit;
	}

	float FlashlightItem_GetNormalizedCharge(FlashlightItem_o* flashlight)
	{
		float charge = _FlashlightItem_GetNormalizedCharge(flashlight);
		if (enableFlashlight)
		{
			charge = 1.0f;
		}
		return charge;
	}

	float PlayerMovement_GetSnowDepthMovementMultiplier(PlayerMovement_o* player_movement)
	{
		float mult = _PlayerMovement_GetSnowDepthMovementMultiplier(player_movement);
		if (speedHack)
		{
			mult = playerSpeedMultiplier;
		}
		return mult;
	}
}

// ==========================================================================================
void InitializeCheat(void* gModule)
{
	SetFunctionPointer(_Encoding_get_UTF8, gModule, 0x282AAD0);
	SetFunctionPointer(_String_CreateStringFromEncoding, gModule, 0x2347C70);

	SetFunctionPointer(_InterfaceManager_GetInstance, gModule, 0x13CCDF0);
	SetFunctionPointer(_GameManager_GetInstance, gModule, 0xEDE9C0);

	SetFunctionPointer(_Input_GetKey, gModule, 0xE00430);
	SetFunctionPointer(_Input_GetKeyUp, gModule, 0xE00480);
	SetFunctionPointer(_Input_GetKeyDown, gModule, 0xE004D0);

	SetFunctionPointer(_vpFPSWeapon_SetDisableAimBreathing, gModule, 0x193C1C0);
	SetFunctionPointer(_vpFPSWeapon_SetDisableAimSway, gModule, 0x193C250);
	SetFunctionPointer(_vpFPSWeapon_SetDisableAimStamina, gModule, 0x193C2E0);
	SetFunctionPointer(_vpFPSWeapon_SetDisableAimShake, gModule, 0x193C370);
	SetFunctionPointer(_vpFPSWeapon_SetDisableDepthOfField, gModule, 0x193C400);

	SetFunctionPointer(_GearManager_DestroyNextUpdate, gModule, 0x159D280);
	SetFunctionPointer(_GearManager_DestroyMarkedObjects, gModule, 0x159D3F0);
	SetFunctionPointer(_GearManager_Update, gModule, 0x159D5C0);
	SetFunctionPointer(_GearManager_UpdateAll, gModule, 0x159D720);

	SetFunctionPointer(_PlayerManager_GetControlMode, gModule, 0xE763C0);
	SetFunctionPointer(_PlayerManager_SetControlMode, gModule, 0xE76490);
	SetFunctionPointer(_PlayerManager_InstantiateItemInPlayerInventory, gModule, 0xE49D20);
	SetFunctionPointer(_Panel_Inventory_IsEnabled, gModule, 0x1126B90);
	SetFunctionPointer(_Panel_Inventory_MarkDirty, gModule, 0x1126B50);
	SetFunctionPointer(_Panel_Subtitles_ShowSubtitlesForced, gModule, 0xFD4E80);

	SetFunctionPointer(_GameManager_UpdateNotPaused, gModule, 0xEE56E0);
	SetFunctionPointer(_HUDManager_ShouldHideCrossHairs, gModule, 0x148A5C0);
	SetFunctionPointer(_PlayerManager_DoPositionCheck, gModule, 0xE5C730);
	SetFunctionPointer(_BodyDamage_GetChanceKill, gModule, 0x12F7500);
	SetFunctionPointer(_KeroseneLampItem_ReduceFuel, gModule, 0x103FDD0);
	SetFunctionPointer(_FlashlightItem_IsLit, gModule, 0x109FF10);
	SetFunctionPointer(_FlashlightItem_GetNormalizedCharge, gModule, 0x109FE40);
	SetFunctionPointer(_PlayerMovement_GetSnowDepthMovementMultiplier, gModule, 0x10720E0);

	// Install hooks
	// ==========================================================================================
	distormx_hook(reinterpret_cast<void**>(&_GameManager_UpdateNotPaused), &Cheat::GameManager_Update);
	distormx_hook(reinterpret_cast<void**>(&_HUDManager_ShouldHideCrossHairs), &Cheat::HUDManager_ShouldHideCrossHairs);
	distormx_hook(reinterpret_cast<void**>(&_PlayerManager_DoPositionCheck), &Cheat::PlayerManager_DoPositionCheck);
	distormx_hook(reinterpret_cast<void**>(&_BodyDamage_GetChanceKill), &Cheat::BodyDamage_GetChanceKill);
	distormx_hook(reinterpret_cast<void**>(&_KeroseneLampItem_ReduceFuel), &Cheat::KeroseneLampItem_ReduceFuel);
	distormx_hook(reinterpret_cast<void**>(&_FlashlightItem_IsLit), &Cheat::FlashlightItem_IsLit);
	distormx_hook(reinterpret_cast<void**>(&_FlashlightItem_GetNormalizedCharge), &Cheat::FlashlightItem_GetNormalizedCharge);
	distormx_hook(reinterpret_cast<void**>(&_PlayerMovement_GetSnowDepthMovementMultiplier), &Cheat::PlayerMovement_GetSnowDepthMovementMultiplier);
}

void ReleaseCheat()
{
	// Remove hooks
	distormx_unhook(&_GameManager_UpdateNotPaused);
	distormx_unhook(&_HUDManager_ShouldHideCrossHairs);
	distormx_unhook(&_PlayerManager_DoPositionCheck);
	distormx_unhook(&_BodyDamage_GetChanceKill);
	distormx_unhook(&_KeroseneLampItem_ReduceFuel);
	distormx_unhook(&_FlashlightItem_IsLit);
	distormx_unhook(&_FlashlightItem_GetNormalizedCharge);
	distormx_unhook(&_PlayerMovement_GetSnowDepthMovementMultiplier);
	distormx_destroy();

	_GameManager_UpdateNotPaused = nullptr;
	_HUDManager_ShouldHideCrossHairs = nullptr;
	_PlayerManager_DoPositionCheck = nullptr;
	_BodyDamage_GetChanceKill = nullptr;
	_KeroseneLampItem_ReduceFuel = nullptr;
	_FlashlightItem_IsLit = nullptr;
	_FlashlightItem_GetNormalizedCharge = nullptr;
	_PlayerMovement_GetSnowDepthMovementMultiplier = nullptr;
}
