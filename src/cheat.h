#pragma once

#include "TLD.h"
#include "utils.h"
#include <string>

namespace Game
{
	constexpr float MaxPlayerSpeedMultiplier = 10.0f;

	enum class InventoryItemAction
	{
		Increment,
		Decrement,
		Repair
	};

	class Cheat
	{
	public:
		Cheat();
		~Cheat();

		static void Initialize(void* hmodule);
		static void Release();

	private:
		void UpdateRVA(void* hmodule);
		void InstallHooks();
		void RemoveHooks();

		// Main game loop
		void OnUpdate(GameManager* gm);

		// Display a message in the top-center of the screen.
		void ShowMessage(std::string_view message);

		// Set camera stability, also disables DoF while aiming with a weapon.
		void SetSteadyCamera(bool steady);

		bool IsInventoryOpen();
		// Change the selected inventory item
		void ChangeInventoryItem(InventoryItemAction action);

		bool GetKey(KeyCode key);
		bool GetKeyDown(KeyCode key);
		bool GetKeyUp(KeyCode key);

	private:
		bool alwaysShowCrosshair {};
		bool oneHitKill {};
		bool neverDegradeItems {};
		bool steadyCamera {};
		bool unlimitedBackpack {};
		bool unlimitedStorage {};
		bool unlimitedLampFuel {};
		bool placeAnywhere {};
		bool fullMapSurvey {};
		float playerSpeed {1.0f};

		// Panel_Inventory is a static member of InterfaceManager,
		// since the game doesn't have a static function to retrieve the Panel_Inventory instance
		// we have to hook Panel_Inventory::Update() and update this pointer.
		// Same thing for other panels.

		Panel_Inventory* panelInventory {};
		Panel_HUD* panelHUD {};
		Panel_Map* panelMap {};

		// ------------------------------------------------------------------------------------------
		function<Encoding* ()> _Encoding_get_UTF8; // Encoding* Encoding::UTF8()
		function<String* (const char*, uint32_t, Encoding*)> _String_CreateStringFromEncoding; // String* String::CreateStringFromEncoding(byte* bytes, int byte_length, Encoding* encoding)
		function<bool(KeyCode)> _Input_GetKey; // bool Input::GetKey(KeyCode key)
		function<bool(KeyCode)> _Input_GetKeyUp; // bool Input::GetKeyUp(KeyCode key)
		function<bool(KeyCode)> _Input_GetKeyDown; // bool Input::GetKeyDown(KeyCode key)
		method<GameManager, void()> _GameManager_UpdateNotPaused; // void GameManager::UpdateNotPaused()
		method<PlayerManager, MeshLocationCategory()> _PlayerManager_DoPositionCheck; // MeshLocationCategory PlayerManager::DoPositionCheck()
		method<HUDManager, bool()> _HUDManager_ShouldHideCrossHairs; // bool HUDManager::ShouldHideCrossHairs()
		method<BodyDamage, int32_t(BodyPart, BodyDamage::Weapon)> _BodyDamage_GetChanceKill; // int BodyDamage::GetChanceKill(BodyPart body_part, BodyDamage::Weapon weapon)
		method<Inventory, void()> _Inventory_ProcessItems; // void Inventory::ProcessItems()
		function<float(List<GearItem>*)> _Utils_GetTotalWeightKG; // float Utils::GetTotalWeightKG(List<GearItem>*)
		method<GearItem, void(float)> _GearItem_Degrade; // void GearItem::Degrade(float hp)
		method<KeroseneLampItem, void(float)> _KeroseneLampItem_ReduceFuel; // void KeroseneLampItem::ReduceFuel(float hours_burned)
		method<PlayerMovement, float()> _PlayerMovement_GetSnowDepthMovementMultiplier; // float PlayerMovement::GetSnowDepthMovementMultiplier()
		function<void(bool)> _vpFPSWeapon_SetDisableAimBreathing; // void vpFPSWeapon::SetDisableAimBreathing(bool enable)
		function<void(bool)> _vpFPSWeapon_SetDisableAimSway; // void vpFPSWeapon::SetDisableAimSway(bool enable)
		function<void(bool)> _vpFPSWeapon_SetDisableAimStamina; // void vpFPSWeapon::SetDisableAimStamina(bool enable)
		function<void(bool)> _vpFPSWeapon_SetDisableAimShake; // void vpFPSWeapon::SetDisableAimShake(bool enable)
		function<void(bool)> _vpFPSWeapon_SetDisableDepthOfField; // void vpFPSWeapon::SetDisableDepthOfField(bool enable)
		function<void(bool)> _vpFPSCamera_SetDisableAmbientSway; // void vpFPSCamera::SetDisableAmbientSway(bool enable)
		method<Panel_Inventory, void()> _Panel_Inventory_Update; // void Panel_Inventory::Update()
		method<Panel_Inventory, void()> _Panel_Inventory_MarkDirty; // void Panel_Inventory::MarkDirty()
		method<Panel_Inventory, bool()> _Panel_Inventory_IsEnabled; // bool Panel_Inventory::IsEnabled()()
		method<Panel_Inventory, GearItem* ()> _Panel_Inventory_GetCurrentlySelectedGearItem; // GearItem* Panel_Inventory::GetCurrentlySelectedGearItem()
		method<Panel_HUD, void()> _Panel_HUD_Update; // void Panel_HUD::Update()
		method<Panel_HUD, void(String*)> _Panel_HUD_ShowSubtitlesForced; // void Panel_HUD::ShowSubtitlesForced(string text)
		method<Panel_HUD, void(float)> _Panel_HUD_HideSubtitles; // void Panel_HUD::HideSubtitles(float seconds_to_hide)
		method<Panel_Map, void()> _Panel_Map_Update; // void Panel_Map::Update()
		method<Panel_Map, void(SurveyType)> _Panel_Map_DoDetailSurvey; // void Panel_Map::DoDetailSurvey(SurveyType survey_type)
	};
}
