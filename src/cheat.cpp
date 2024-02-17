#include "cheat.h"
#include "GameAssembly.h"
#include <distormx/distormx.h>

#include <cstddef>
#include <algorithm>
#include <memory>
#include <string>

namespace TLDCheat
{
	static bool InventoryPanelEnabled = false;

	static bool steadyCamera = false;
	static bool placeAnywhere = false;
	static bool oneHitKill = false;
	static bool unlimitedLampFuel = false;
	static bool enableFlashlight = false;
	static bool allowRevolverAimMove = false;

	static bool speedHack = false;
	static float playerSpeedMultiplier = 1.0f;

	// ==========================================================================================
	void ShowMessage(std::string_view message)
	{
		(*GameAssembly.HUDMessage_TypeInfo.ptr)->static_fields->m_CurrentMessage = nullptr;
		GameAssembly.HUDMessage_AddMessage(GameAssembly.String_CreateStringFromEncoding(message.data(), message.size(), GameAssembly.Encoding_get_UTF8()), true, true);
	}

	// ==========================================================================================
	void GameManager_Update(GameManager_o* game_manager)
	{
		// Call the original update of the game
		GameAssembly.GameManager_UpdateNotPaused(game_manager);

		if (InventoryPanelEnabled) {
			return;
		}

		// Steady camera
		if (GameAssembly.Input_GetKeyDown(UnityEngine::KeyCode::Keypad0)) {
			steadyCamera = !steadyCamera;
			ShowMessage(steadyCamera ? u8"Steady camera enabled" : u8"Steady camera disabled");
		}

		// Place anywhere
		if (GameAssembly.Input_GetKeyDown(UnityEngine::KeyCode::Keypad1)) {
			placeAnywhere = !placeAnywhere;
			ShowMessage(placeAnywhere ? u8"Collision between items disabled" : u8"Collision between items enabled");
		}

		// Toggle one-hit kill
		if (GameAssembly.Input_GetKeyDown(UnityEngine::KeyCode::Keypad2)) {
			oneHitKill = !oneHitKill;
			ShowMessage(oneHitKill ? u8"One-hit kill activated" : u8"One-hit kill deactivated");
		}

		// Unlimited lamp fuel
		if (GameAssembly.Input_GetKeyDown(UnityEngine::KeyCode::Keypad3)) {
			unlimitedLampFuel = !unlimitedLampFuel;
			ShowMessage(unlimitedLampFuel ? u8"Unlimited lamp fuel activated" : u8"Unlimited lamp fuel deactivated");
		}

		// Enable flashlight everywhere
		if (GameAssembly.Input_GetKeyDown(UnityEngine::KeyCode::Keypad4)) {
			enableFlashlight = !enableFlashlight;
			ShowMessage(enableFlashlight ? u8"Flashlight enabled" : u8"Flashlight deactivated");
		}

		// Enable revolver aim movement
		if (GameAssembly.Input_GetKeyDown(UnityEngine::KeyCode::Keypad5)) {
			allowRevolverAimMove = !allowRevolverAimMove;
			ShowMessage(allowRevolverAimMove ? u8"Movement while aiming Revolver enabled" : u8"Movement while aiming Revolver disabled");
		}

		// Speedhack
		if (GameAssembly.Input_GetKeyDown(UnityEngine::KeyCode::Keypad9)) {
			speedHack = !speedHack;
			ShowMessage(speedHack ? u8"Speedhack enabled" : u8"Speedhack disabled");
		}

		if (speedHack) {
			int offset = static_cast<int>(GameAssembly.Input_GetKeyDown(UnityEngine::KeyCode::KeypadPlus)) - static_cast<int>(GameAssembly.Input_GetKeyDown(UnityEngine::KeyCode::KeypadMinus));
			if (offset != 0) {
				playerSpeedMultiplier = std::clamp(playerSpeedMultiplier + static_cast<float>(offset), 1.0f, 10.0f);

				std::string buffer;
				{
					const char* fmt = "Speedhack set to %dx";
					int szbuf = snprintf(nullptr, 0, fmt, static_cast<int>(playerSpeedMultiplier));
					buffer.resize(szbuf + 1);
					snprintf(buffer.data(), szbuf, fmt, static_cast<int>(playerSpeedMultiplier));
				}
				ShowMessage(buffer);
			}
		}
	}

	void Panel_Inventory_Update(Panel_Inventory_o* panel_inventory)
	{
		// Call original panel inventory update
		GameAssembly.Panel_Inventory_Update(panel_inventory);

		GameManager_o* const game_manager = GameAssembly.GameManager_Instance();
		PlayerManager_o* const player_manager = game_manager->klass->static_fields->m_PlayerManager;

		InventoryPanelEnabled = GameAssembly.Panel_Inventory_IsEnabled(panel_inventory);
		if (!InventoryPanelEnabled) {
			return;
		}

		// Make sure an item is selected
		InventoryGridItem_o* selectedGridItem = nullptr;
		{
			InventoryGridItem_array* const items = panel_inventory->fields.m_TableItems;
			const int32_t index = panel_inventory->fields.m_SelectedItemIndexVal;
			if (items && index < items->max_length) {
				selectedGridItem = items->m_Items[index];
			}
		}
		if (!selectedGridItem) {
			return;
		}

		// Determine action to be performed on the selected item
		int modifier = static_cast<int>(GameAssembly.Input_GetKeyDown(UnityEngine::KeyCode::KeypadPlus)) - static_cast<int>(GameAssembly.Input_GetKeyDown(UnityEngine::KeyCode::KeypadMinus));
		bool repair = GameAssembly.Input_GetKeyDown(UnityEngine::KeyCode::KeypadMultiply);
		bool destroy = GameAssembly.Input_GetKeyDown(UnityEngine::KeyCode::Delete);

		if (modifier == 0 && !repair && !destroy) {
			return;
		}

		GearItem_o* const gearItem = selectedGridItem->fields.m_GearItem;

		// Worn-out items can't be repaired, it becomes buggy.
		if (gearItem->fields.m_WornOut) {
			return;
		}

		if (TLD_Gear_GearItemData_o* item_data = gearItem->fields.m_GearItemData; repair && item_data) {
			gearItem->fields.m_CurrentHP = item_data->fields.m_MaxHP;
		}

		if (modifier) {
			LiquidItem_o* const liquidItem = gearItem->fields.m_LiquidItem;
			StackableItem_o* const stackableItem = gearItem->fields.m_StackableItem;

			if (liquidItem) {
				const float capacity = liquidItem->fields.m_LiquidCapacityLiters;
				float& liters = liquidItem->fields.m_LiquidLiters;

				if (modifier > 0 && liters >= capacity) {
					// Clone this item if reached it's limit
					GameAssembly.PlayerManager_InstantiateItemInPlayerInventory(player_manager, gearItem, 1, false);

				} else {
					liters += capacity * 0.1f * static_cast<float>(modifier);
					if (liters > capacity) {
						liters = capacity;
					} else if (liters <= 0.0f) {
						destroy = true;
					}
				}

			} else if (stackableItem) {
				int32_t& units = stackableItem->fields.m_Units;
				units += modifier;

				if (units <= 0) {
					destroy = true;
				}

			} else {
				// Clone other items
				if (modifier > 0) {
					GameAssembly.PlayerManager_InstantiateItemInPlayerInventory(player_manager, gearItem, 1, false);
				}
			}
		}

		if (destroy) {
			GameAssembly.GearManager_DestroyNextUpdate(gearItem, true);
		}
		GameAssembly.Panel_Inventory_MarkDirty(panel_inventory);
	}

	uint32_t PlayerManager_DoPositionCheck(PlayerManager_o* player_manager)
	{
		uint32_t state = GameAssembly.PlayerManager_DoPositionCheck(player_manager);
		if (placeAnywhere && state == static_cast<uint32_t>(TLD::MeshLocationCategory::InvalidTooClose)) {
			state = static_cast<uint32_t>(TLD::MeshLocationCategory::Valid);
		}
		return state;
	}

	void PlayerManager_SetControlMode(PlayerManager_o* player_manager, TLD::PlayerControlMode mode)
	{
		if (allowRevolverAimMove && mode == TLD::PlayerControlMode::AimRevolver) {
			return;
		}
		GameAssembly.PlayerManager_SetControlMode(player_manager, mode);
	}

	int32_t BodyDamage_GetChanceKill(BodyDamage_o* bodyDamage, TLD::BodyPart bodyPart, TLD::BodyDamageWeapon damageWeapon)
	{
		int32_t chance = GameAssembly.BodyDamage_GetChanceKill(bodyDamage, bodyPart, damageWeapon);
		if (oneHitKill) {
			chance = 100;
		}
		return chance;
	}

	void KeroseneLampItem_ReduceFuel(TLD_Gear_KeroseneLampItem_o* lamp, float hoursBurned)
	{
		const float prevFuel = lamp->fields.m_CurrentFuelLiters;
		GameAssembly.KeroseneLampItem_ReduceFuel(lamp, hoursBurned);
		if (unlimitedLampFuel) {
			lamp->fields.m_CurrentFuelLiters = prevFuel;
		}
	}

	bool FlashlightItem_IsLit(FlashlightItem_o* flashlight)
	{
		return enableFlashlight ? (flashlight->fields.m_State != (int32_t)TLD::FlashlightState::Off) : GameAssembly.FlashlightItem_IsLit(flashlight);
	}

	float FlashlightItem_GetNormalizedCharge(FlashlightItem_o* flashlight)
	{
		return enableFlashlight ? 1.0f : GameAssembly.FlashlightItem_GetNormalizedCharge(flashlight);
	}

	float PlayerMovement_GetSnowDepthMovementMultiplier(PlayerMovement_o* player_movement)
	{
		return speedHack ? playerSpeedMultiplier : GameAssembly.PlayerMovement_GetSnowDepthMovementMultiplier(player_movement);
	}

	void vp_FPSCamera_DoSwaying(vp_FPSCamera_o* camera, UnityEngine_Vector3_o* velocity)
	{
		if (!steadyCamera) {
			GameAssembly.vp_FPSCamera_DoSwaying(camera, velocity);
		}
	}

	void vp_FPSCamera_DoBob(vp_FPSCamera_o* camera, float speed, float time)
	{
		if (!steadyCamera) {
			GameAssembly.vp_FPSCamera_DoBob(camera, speed, time);
		}
	}

	UnityEngine_Vector2_o vp_FPSCamera_RandomSway(vp_FPSCamera_o* camera, float speed, float time)
	{
		UnityEngine_Vector2_o sway = GameAssembly.vp_FPSCamera_RandomSway(camera, speed, time);
		if (steadyCamera) {
			sway.fields.x = 0.0f;
			sway.fields.y = 0.0f;
		}
		return sway;
	}

	// ==========================================================================================
	void Initialize()
	{
		// Install hooks
		distormx_hook(reinterpret_cast<void**>(&GameAssembly.GameManager_UpdateNotPaused), &GameManager_Update);
		distormx_hook(reinterpret_cast<void**>(&GameAssembly.Panel_Inventory_Update), &Panel_Inventory_Update);
		distormx_hook(reinterpret_cast<void**>(&GameAssembly.PlayerManager_DoPositionCheck), &PlayerManager_DoPositionCheck);
		distormx_hook(reinterpret_cast<void**>(&GameAssembly.PlayerManager_SetControlMode), &PlayerManager_SetControlMode);
		distormx_hook(reinterpret_cast<void**>(&GameAssembly.BodyDamage_GetChanceKill), &BodyDamage_GetChanceKill);
		distormx_hook(reinterpret_cast<void**>(&GameAssembly.KeroseneLampItem_ReduceFuel), &KeroseneLampItem_ReduceFuel);
		distormx_hook(reinterpret_cast<void**>(&GameAssembly.FlashlightItem_IsLit), &FlashlightItem_IsLit);
		distormx_hook(reinterpret_cast<void**>(&GameAssembly.FlashlightItem_GetNormalizedCharge), &FlashlightItem_GetNormalizedCharge);
		distormx_hook(reinterpret_cast<void**>(&GameAssembly.PlayerMovement_GetSnowDepthMovementMultiplier), &PlayerMovement_GetSnowDepthMovementMultiplier);
		distormx_hook(reinterpret_cast<void**>(&GameAssembly.vp_FPSCamera_DoSwaying), &vp_FPSCamera_DoSwaying);
		distormx_hook(reinterpret_cast<void**>(&GameAssembly.vp_FPSCamera_DoBob), &vp_FPSCamera_DoBob);
		distormx_hook(reinterpret_cast<void**>(&GameAssembly.vp_FPSCamera_RandomSway), &vp_FPSCamera_RandomSway);
	}

	void Release()
	{
		// Remove hooks
		distormx_unhook(&GameAssembly.GameManager_UpdateNotPaused);
		distormx_unhook(&GameAssembly.Panel_Inventory_Update);
		distormx_unhook(&GameAssembly.PlayerManager_DoPositionCheck);
		distormx_unhook(&GameAssembly.PlayerManager_SetControlMode);
		distormx_unhook(&GameAssembly.BodyDamage_GetChanceKill);
		distormx_unhook(&GameAssembly.KeroseneLampItem_ReduceFuel);
		distormx_unhook(&GameAssembly.FlashlightItem_IsLit);
		distormx_unhook(&GameAssembly.FlashlightItem_GetNormalizedCharge);
		distormx_unhook(&GameAssembly.PlayerMovement_GetSnowDepthMovementMultiplier);
		distormx_unhook(&GameAssembly.vp_FPSCamera_DoSwaying);
		distormx_unhook(&GameAssembly.vp_FPSCamera_DoBob);
		distormx_unhook(&GameAssembly.vp_FPSCamera_RandomSway);
		distormx_destroy();
	}
}
