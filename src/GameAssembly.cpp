#include "GameAssembly.h"

GameAssemblyModule GameAssembly {};

void GameAssemblyModule::Initialize(void* baseAddress)
{
#define ADD_MODULE_ADDRESS(v) \
	v.ptr = reinterpret_cast<typename decltype(v)::value_type>((size_t)v.ptr + (size_t)baseAddress)

	ADD_MODULE_ADDRESS(Encoding_get_UTF8);
	ADD_MODULE_ADDRESS(String_CreateStringFromEncoding);

	ADD_MODULE_ADDRESS(Input_GetKey);
	ADD_MODULE_ADDRESS(Input_GetKeyDown);
	ADD_MODULE_ADDRESS(Input_GetKeyUp);

	ADD_MODULE_ADDRESS(GameManager_Instance);

	ADD_MODULE_ADDRESS(HUDMessage_TypeInfo);
	ADD_MODULE_ADDRESS(HUDMessage_AddMessage);

	ADD_MODULE_ADDRESS(GearManager_DestroyNextUpdate);
	ADD_MODULE_ADDRESS(GearManager_DestroyMarkedObjects);
	ADD_MODULE_ADDRESS(GearManager_Update);
	ADD_MODULE_ADDRESS(GearManager_UpdateAll);

	ADD_MODULE_ADDRESS(PlayerManager_GetControlMode);
	ADD_MODULE_ADDRESS(PlayerManager_SetControlMode);
	ADD_MODULE_ADDRESS(PlayerManager_InstantiateItemInPlayerInventory);

	ADD_MODULE_ADDRESS(Panel_Inventory_IsEnabled);
	ADD_MODULE_ADDRESS(Panel_Inventory_MarkDirty);
	ADD_MODULE_ADDRESS(Panel_Inventory_Update);

	ADD_MODULE_ADDRESS(GameManager_UpdateNotPaused);
	ADD_MODULE_ADDRESS(PlayerManager_DoPositionCheck);
	ADD_MODULE_ADDRESS(BodyDamage_GetChanceKill);
	ADD_MODULE_ADDRESS(KeroseneLampItem_ReduceFuel);

	ADD_MODULE_ADDRESS(FlashlightItem_IsLit);
	ADD_MODULE_ADDRESS(FlashlightItem_GetNormalizedCharge);

	ADD_MODULE_ADDRESS(PlayerMovement_GetSnowDepthMovementMultiplier);

#undef ADD_MODULE_ADDRESS
}
