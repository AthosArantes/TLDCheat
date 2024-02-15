#pragma once

#include <il2cppdump/il2cpp.h>
#include "il2cpp_utils.h"
#include "GameConstants.h"

struct GameAssemblyModule
{
	void Initialize(void* baseAddress);

	il2cpp::function<System_Text_Encoding_o*> Encoding_get_UTF8 {0x220BED0};
	il2cpp::function<System_String_o*, const char* /*bytes*/, uint32_t /*size*/, System_Text_Encoding_o*> String_CreateStringFromEncoding {0x21EC030};

	il2cpp::function<bool, unsigned /*keyCode*/> Input_GetKey {0x32E1570};
	il2cpp::function<bool, unsigned /*keyCode*/> Input_GetKeyDown {0x32E16B0};
	il2cpp::function<bool, unsigned /*keyCode*/> Input_GetKeyUp {0x32E1610};

	//il2cpp::function<InterfaceManager_o*> InterfaceManager_GetInstance {0xBBB710};
	il2cpp::function<GameManager_o*> GameManager_Instance {0xB54CB0};
	
	il2cpp::object<HUDMessage_c**> HUDMessage_TypeInfo {0x414EBB0};
	il2cpp::function<void, System_String_o*, bool /*highPriority*/, bool /*ignoreOverlayActive*/> HUDMessage_AddMessage {0x8A7320};

	il2cpp::function<void, GearItem_o*, bool> GearManager_DestroyNextUpdate {0xB69C50};
	il2cpp::function<void> GearManager_DestroyMarkedObjects {0xB69D60};
	il2cpp::function<void> GearManager_Update {0xB69F20};
	il2cpp::function<void> GearManager_UpdateAll {0xB6A090};

	il2cpp::function<TLD::PlayerControlMode, PlayerManager_o*> PlayerManager_GetControlMode {0xBDB400};
	il2cpp::function<void, PlayerManager_o*, TLD::PlayerControlMode> PlayerManager_SetControlMode {0xBDB480};
	il2cpp::function<GearItem_o*, PlayerManager_o*, GearItem_o*, int32_t /*numUnits*/, bool /*enableNotificationFlag*/> PlayerManager_InstantiateItemInPlayerInventory {0xC069D0};
	
	il2cpp::function<bool, Panel_Inventory_o*> Panel_Inventory_IsEnabled {0x9CA650};
	il2cpp::function<void, Panel_Inventory_o*> Panel_Inventory_MarkDirty {0x9CA610};
	il2cpp::function<void, Panel_Inventory_o*> Panel_Inventory_Update {0x9C7210};

	il2cpp::function<void, GameManager_o*> GameManager_UpdateNotPaused {0xB59030};
	il2cpp::function<uint32_t, PlayerManager_o*> PlayerManager_DoPositionCheck {0xC0CBE0};
	il2cpp::function<int32_t, BodyDamage_o*, TLD::BodyPart, TLD::BodyDamageWeapon> BodyDamage_GetChanceKill {0x5819F0};
	il2cpp::function<void, TLD_Gear_KeroseneLampItem_o*, float /*hoursBurned*/> KeroseneLampItem_ReduceFuel {0x10BD5A0};

	il2cpp::function<bool, FlashlightItem_o*> FlashlightItem_IsLit {0x7A19A0};
	il2cpp::function<float, FlashlightItem_o*> FlashlightItem_GetNormalizedCharge {0x7A1900};

	il2cpp::function<float, PlayerMovement_o*> PlayerMovement_GetSnowDepthMovementMultiplier {0xCFB1B0};
};

extern GameAssemblyModule GameAssembly;
