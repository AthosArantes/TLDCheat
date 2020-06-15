#pragma once

#include <stdint.h>

namespace Game
{
	enum class KeyCode : uint32_t
	{
		None = 0,
		Backspace = 8,
		Delete = 127,
		Tab = 9,
		Clear = 12,
		Return = 13,
		Pause = 19,
		Escape = 27,
		Space = 32,
		Keypad0 = 256,
		Keypad1 = 257,
		Keypad2 = 258,
		Keypad3 = 259,
		Keypad4 = 260,
		Keypad5 = 261,
		Keypad6 = 262,
		Keypad7 = 263,
		Keypad8 = 264,
		Keypad9 = 265,
		KeypadPeriod = 266,
		KeypadDivide = 267,
		KeypadMultiply = 268,
		KeypadMinus = 269,
		KeypadPlus = 270,
		KeypadEnter = 271,
		KeypadEquals = 272,
		UpArrow = 273,
		DownArrow = 274,
		RightArrow = 275,
		LeftArrow = 276,
		Insert = 277,
		Home = 278,
		End = 279,
		PageUp = 280,
		PageDown = 281,
		F1 = 282,
		F2 = 283,
		F3 = 284,
		F4 = 285,
		F5 = 286,
		F6 = 287,
		F7 = 288,
		F8 = 289,
		F9 = 290,
		F10 = 291,
		F11 = 292,
		F12 = 293,
		F13 = 294,
		F14 = 295,
		F15 = 296,
		Alpha0 = 48,
		Alpha1 = 49,
		Alpha2 = 50,
		Alpha3 = 51,
		Alpha4 = 52,
		Alpha5 = 53,
		Alpha6 = 54,
		Alpha7 = 55,
		Alpha8 = 56,
		Alpha9 = 57,
		Exclaim = 33,
		DoubleQuote = 34,
		Hash = 35,
		Dollar = 36,
		Percent = 37,
		Ampersand = 38,
		Quote = 39,
		LeftParen = 40,
		RightParen = 41,
		Asterisk = 42,
		Plus = 43,
		Comma = 44,
		Minus = 45,
		Period = 46,
		Slash = 47,
		Colon = 58,
		Semicolon = 59,
		Less = 60,
		Equals = 61,
		Greater = 62,
		Question = 63,
		At = 64,
		LeftBracket = 91,
		Backslash = 92,
		RightBracket = 93,
		Caret = 94,
		Underscore = 95,
		BackQuote = 96,
		A = 97,
		B = 98,
		C = 99,
		D = 100,
		E = 101,
		F = 102,
		G = 103,
		H = 104,
		I = 105,
		J = 106,
		K = 107,
		L = 108,
		M = 109,
		N = 110,
		O = 111,
		P = 112,
		Q = 113,
		R = 114,
		S = 115,
		T = 116,
		U = 117,
		V = 118,
		W = 119,
		X = 120,
		Y = 121,
		Z = 122,
		LeftCurlyBracket = 123,
		Pipe = 124,
		RightCurlyBracket = 125,
		Tilde = 126,
		Numlock = 300,
		CapsLock = 301,
		ScrollLock = 302,
		RightShift = 303,
		LeftShift = 304,
		RightControl = 305,
		LeftControl = 306,
		RightAlt = 307,
		LeftAlt = 308,
		LeftCommand = 310,
		LeftApple = 310,
		LeftWindows = 311,
		RightCommand = 309,
		RightApple = 309,
		RightWindows = 312,
		AltGr = 313,
		Help = 315,
		Print = 316,
		SysReq = 317,
		Break = 318,
		Menu = 319,
		Mouse0 = 323,
		Mouse1 = 324,
		Mouse2 = 325,
		Mouse3 = 326,
		Mouse4 = 327,
		Mouse5 = 328,
		Mouse6 = 329,
		JoystickButton0 = 330,
		JoystickButton1 = 331,
		JoystickButton2 = 332,
		JoystickButton3 = 333,
		JoystickButton4 = 334,
		JoystickButton5 = 335,
		JoystickButton6 = 336,
		JoystickButton7 = 337,
		JoystickButton8 = 338,
		JoystickButton9 = 339,
		JoystickButton10 = 340,
		JoystickButton11 = 341,
		JoystickButton12 = 342,
		JoystickButton13 = 343,
		JoystickButton14 = 344,
		JoystickButton15 = 345,
		JoystickButton16 = 346,
		JoystickButton17 = 347,
		JoystickButton18 = 348,
		JoystickButton19 = 349,
		Joystick1Button0 = 350,
		Joystick1Button1 = 351,
		Joystick1Button2 = 352,
		Joystick1Button3 = 353,
		Joystick1Button4 = 354,
		Joystick1Button5 = 355,
		Joystick1Button6 = 356,
		Joystick1Button7 = 357,
		Joystick1Button8 = 358,
		Joystick1Button9 = 359,
		Joystick1Button10 = 360,
		Joystick1Button11 = 361,
		Joystick1Button12 = 362,
		Joystick1Button13 = 363,
		Joystick1Button14 = 364,
		Joystick1Button15 = 365,
		Joystick1Button16 = 366,
		Joystick1Button17 = 367,
		Joystick1Button18 = 368,
		Joystick1Button19 = 369,
		Joystick2Button0 = 370,
		Joystick2Button1 = 371,
		Joystick2Button2 = 372,
		Joystick2Button3 = 373,
		Joystick2Button4 = 374,
		Joystick2Button5 = 375,
		Joystick2Button6 = 376,
		Joystick2Button7 = 377,
		Joystick2Button8 = 378,
		Joystick2Button9 = 379,
		Joystick2Button10 = 380,
		Joystick2Button11 = 381,
		Joystick2Button12 = 382,
		Joystick2Button13 = 383,
		Joystick2Button14 = 384,
		Joystick2Button15 = 385,
		Joystick2Button16 = 386,
		Joystick2Button17 = 387,
		Joystick2Button18 = 388,
		Joystick2Button19 = 389,
		Joystick3Button0 = 390,
		Joystick3Button1 = 391,
		Joystick3Button2 = 392,
		Joystick3Button3 = 393,
		Joystick3Button4 = 394,
		Joystick3Button5 = 395,
		Joystick3Button6 = 396,
		Joystick3Button7 = 397,
		Joystick3Button8 = 398,
		Joystick3Button9 = 399,
		Joystick3Button10 = 400,
		Joystick3Button11 = 401,
		Joystick3Button12 = 402,
		Joystick3Button13 = 403,
		Joystick3Button14 = 404,
		Joystick3Button15 = 405,
		Joystick3Button16 = 406,
		Joystick3Button17 = 407,
		Joystick3Button18 = 408,
		Joystick3Button19 = 409,
		Joystick4Button0 = 410,
		Joystick4Button1 = 411,
		Joystick4Button2 = 412,
		Joystick4Button3 = 413,
		Joystick4Button4 = 414,
		Joystick4Button5 = 415,
		Joystick4Button6 = 416,
		Joystick4Button7 = 417,
		Joystick4Button8 = 418,
		Joystick4Button9 = 419,
		Joystick4Button10 = 420,
		Joystick4Button11 = 421,
		Joystick4Button12 = 422,
		Joystick4Button13 = 423,
		Joystick4Button14 = 424,
		Joystick4Button15 = 425,
		Joystick4Button16 = 426,
		Joystick4Button17 = 427,
		Joystick4Button18 = 428,
		Joystick4Button19 = 429,
		Joystick5Button0 = 430,
		Joystick5Button1 = 431,
		Joystick5Button2 = 432,
		Joystick5Button3 = 433,
		Joystick5Button4 = 434,
		Joystick5Button5 = 435,
		Joystick5Button6 = 436,
		Joystick5Button7 = 437,
		Joystick5Button8 = 438,
		Joystick5Button9 = 439,
		Joystick5Button10 = 440,
		Joystick5Button11 = 441,
		Joystick5Button12 = 442,
		Joystick5Button13 = 443,
		Joystick5Button14 = 444,
		Joystick5Button15 = 445,
		Joystick5Button16 = 446,
		Joystick5Button17 = 447,
		Joystick5Button18 = 448,
		Joystick5Button19 = 449,
		Joystick6Button0 = 450,
		Joystick6Button1 = 451,
		Joystick6Button2 = 452,
		Joystick6Button3 = 453,
		Joystick6Button4 = 454,
		Joystick6Button5 = 455,
		Joystick6Button6 = 456,
		Joystick6Button7 = 457,
		Joystick6Button8 = 458,
		Joystick6Button9 = 459,
		Joystick6Button10 = 460,
		Joystick6Button11 = 461,
		Joystick6Button12 = 462,
		Joystick6Button13 = 463,
		Joystick6Button14 = 464,
		Joystick6Button15 = 465,
		Joystick6Button16 = 466,
		Joystick6Button17 = 467,
		Joystick6Button18 = 468,
		Joystick6Button19 = 469,
		Joystick7Button0 = 470,
		Joystick7Button1 = 471,
		Joystick7Button2 = 472,
		Joystick7Button3 = 473,
		Joystick7Button4 = 474,
		Joystick7Button5 = 475,
		Joystick7Button6 = 476,
		Joystick7Button7 = 477,
		Joystick7Button8 = 478,
		Joystick7Button9 = 479,
		Joystick7Button10 = 480,
		Joystick7Button11 = 481,
		Joystick7Button12 = 482,
		Joystick7Button13 = 483,
		Joystick7Button14 = 484,
		Joystick7Button15 = 485,
		Joystick7Button16 = 486,
		Joystick7Button17 = 487,
		Joystick7Button18 = 488,
		Joystick7Button19 = 489,
		Joystick8Button0 = 490,
		Joystick8Button1 = 491,
		Joystick8Button2 = 492,
		Joystick8Button3 = 493,
		Joystick8Button4 = 494,
		Joystick8Button5 = 495,
		Joystick8Button6 = 496,
		Joystick8Button7 = 497,
		Joystick8Button8 = 498,
		Joystick8Button9 = 499,
		Joystick8Button10 = 500,
		Joystick8Button11 = 501,
		Joystick8Button12 = 502,
		Joystick8Button13 = 503,
		Joystick8Button14 = 504,
		Joystick8Button15 = 505,
		Joystick8Button16 = 506,
		Joystick8Button17 = 507,
		Joystick8Button18 = 508,
		Joystick8Button19 = 509
	};

	enum class SelectedTableEnum : uint32_t
	{
		InventoryTable = 0,
		ContainerTable = 1
	};

	enum class GearTypeEnum : uint32_t
	{
		Food = 0,
		Clothing = 1,
		Material = 2,
		Tool = 3,
		Other = 4,
		FirstAid = 5,
		Firestarting = 6,
	};

	enum class GearScarcityEnum : uint32_t
	{
		Common = 0,
		Uncommon = 1,
		Rare = 2,
		Unique = 3,
		Story = 4
	};

	enum class GearStartCondition : uint32_t
	{
		Random = 0,
		Perfect = 1,
		High = 2,
		Medium = 3,
		Low = 4
	};

	enum class GearMovementSound : uint32_t
	{
		None = 0,
		General = 1,
		Metal = 2,
		Water = 3,
		Wood = 4
	};

	enum class GearDummyType : uint32_t
	{
		None = 0,
		Rabbit = 1,
		Body = 2
	};

	enum class BodyPart : uint32_t
	{
		head = 0,
		torso = 1,
		hips = 2,
		limb = 3,
		neck = 4,
		numLimbs = 5
	};

	enum class GearLiquidTypeEnum : uint32_t
	{
		Water = 0,
		Gasoline = 1,
		Kerosene = 2,
		Antiseptic = 3
	};

	enum class LiquidQuality : uint32_t
	{
		Potable = 0,
		NonPotable = 1
	};

	enum class MeshLocationCategory : uint32_t
	{
		Valid,
		ValidOutOfRange,
		ValidOutOfRangeFar,
		Invalid,
		InvalidNotWithinRequiredVolume,
		InvalidTooWindy,
		InvalidOnWood,
		InvalidOnStraw,
		InvalidMustBeOnSnow,
		InvalidOnTopOfAnotherDecal,
		InvalidNoPaintCans,
		InvalidTooClose,
		InvalidInAir,
		InvalidIndoors,
		InvalidTooManyPlacedDecals
	};

	enum class SurveyType : uint32_t
	{
		Charcoal,
		RockCache,
		SprayPaint
	};

	// ==========================================================================================

	template <typename T>
	struct List;

	template <typename K, typename V>
	struct Dictionary;

	struct Encoding;
	struct String;

	struct HUDMessage;
	struct AmmoItem;
	struct AmmoCasingItem;
	struct ArrowItem;
	struct BearSpearItem;
	struct Bed;
	struct BodyHarvestItem;
	struct BodyHarvest;
	struct BowItem;
	struct BreakDownItem;
	struct CanOpeningItem;
	struct CarryableBody;
	struct CarryingCapacityBuff;
	struct CharcoalItem;
	struct Cleanable;
	struct ClothingItem;
	struct ConditionOverTimeBuff;
	struct ConditionRestBuff;
	struct Cookable;
	struct CookingPotItem;
	struct DegradeOnUse;
	struct EmergencyStimItem;
	struct EnergyBoostItem;
	struct EvolveItem;
	struct FatigueBuff;
	struct FireStarterItem;
	struct FirstAidItem;
	struct FirstPersonItem;
	struct FishingItem;
	struct FlareItem;
	struct FlashlightItem;
	struct FoodItem;
	struct FoodWeight;
	struct ForageItem;
	struct ForceLockItem;
	struct FreezingBuff;
	struct FuelSourceItem;
	struct HandheldShortwaveItem;
	struct GunItem;
	struct Harvest;
	struct IceFishingHoleClearItem;
	struct InProgressCraftItem;
	struct Inspect;
	struct KeroseneLampItem;
	struct Knowledge;
	struct LiquidItem;
	struct MatchesItem;
	struct Millable;
	struct NarrativeCollectibleItem;
	struct ShowOnMapItem;
	struct OwnershipOverride;
	struct PlaceableItem;
	struct PowderItem;
	struct PurifyWater;
	struct Repairable;
	struct ResearchItem;
	struct RopeItem;
	struct Scent;
	struct Sharpenable;
	struct SmashableItem;
	struct SnareItem;
	struct SprayPaintCan;
	struct StackableItem;
	struct StoneItem;
	struct StruggleBonus;
	struct ToolsItem;
	struct TorchItem;
	struct WaterSupply;
	struct WildlifeItem;
	struct WolfIntimidationBuff;
	struct MeshRenderer;
	struct SkinnedMeshRenderer;
	struct ObjectGuid;
	struct MissionObjectIdentifier;
	struct OnDroppedInWaterDelegate;
	struct RadialObjectSpawner;
	struct Container;
	struct Rigidbody;
	struct LocalizedString;
	struct GearItem;
	struct GearItemObject;
	struct KeroseneLampIntensity;
	struct Light;
	struct HeatSource;
	struct GameObject;
	struct DialogueStatesTable;
	struct MissionObjectiveTable;
	struct AfflictionDefinitionTable;
	struct SceneMapping;
	struct GameManager;
	struct PlayerManager;
	struct DebugViewModeManager;
	struct InterfaceManager;
	struct vpFPSCamera;
	struct vpFPSPlayer;
	struct PlayerMovement;
	struct Inventory;
	struct Encumber;
	struct AuroraField;
	struct StoryMissionObjective;
	struct TweenScale;
	struct Transform;
	struct InventoryGridItem;
	struct UILabel;
	struct UISprite;
	struct UIButton;
	struct UISlider;
	struct UIPanel;
	struct UIWidget;
	struct ButtonLegendContainer;
	struct ItemDescriptionPage;
	struct GearItemCoverflow;
	struct GamepadButtonSprite;
	struct GenericButtonMouseSpawner;
	struct MapCrosshair;
	struct RegionMap;
	struct TweenAlpha;
	struct MapElementSaveData;
	struct DetailSurveyPosition;
	struct FogOfWar;
	struct VistaLocationData;
	struct VistaLocation;
	struct MapElementRemovalData;
	struct MapIcon;
	struct MissionMapMarkerInfo;
	struct ClusterCell;

	struct Panel_Actions;
	struct Panel_ActionPicker;
	struct Panel_ActionsRadial;
	struct Panel_Affliction;
	struct Panel_Badges;
	struct Panel_BedRollSelect;
	struct Panel_BodyHarvest;
	struct Panel_BreakDown;
	struct Panel_CanOpening;
	struct Panel_ChallengeComplete;
	struct Panel_Challenges;
	struct Panel_ChooseChallenge;
	struct Panel_ChooseEpisodeExperience;
	struct Panel_ChooseSandbox;
	struct Panel_Choose4DON;
	struct Panel_ChooseStory;
	struct Panel_Clothing;
	struct Panel_Confirmation;
	struct Panel_Container;
	struct Panel_Cooking;
	struct Panel_Crafting;
	struct Panel_Credits;
	struct Panel_CustomXPSetup;
	struct Panel_Diagnosis;
	struct Panel_EpisodeContinue;
	struct Panel_EpisodeSelection;
	struct Panel_Extras;
	struct Panel_Debug;
	struct Panel_FeedFire;
	struct Panel_FireStart;
	struct Panel_FirstAid;
	struct Panel_GearSelect;
	struct Panel_GenericProgressBar;
	struct Panel_Harvest;
	struct Panel_Help;
	struct Panel_HUD;
	struct Panel_IceFishing;
	struct Panel_IceFishingHoleClear;
	struct Panel_Inventory;
	struct Panel_Inventory_Examine;
	struct Panel_Knowledge;
	struct Panel_Loading;
	struct Panel_Log;
	struct Panel_MainMenu;
	struct Panel_Map;
	struct Panel_MarkerList;
	struct Panel_Milling;
	struct Panel_MissionsStory;
	struct Panel_Notifications;
	struct Panel_OptionsMenu;
	struct Panel_PauseMenu;
	struct Panel_PickUnits;
	struct Panel_PickWater;
	struct Panel_Repair;
	struct Panel_Rest;
	struct Panel_SafeCracking;
	struct Panel_SaveIcon;
	struct Panel_SaveStory;
	struct Panel_Sandbox;
	struct Panel_Sandbox4DON;
	struct Panel_SelectChallengeType;
	struct Panel_SelectExperience;
	struct Panel_SelectRegion;
	struct Panel_SelectSurvivor;
	struct Panel_SnowShelterBuild;
	struct Panel_SnowShelterInteract;
	struct Panel_SprayPaint;
	struct Panel_LeanToBuild;
	struct Panel_LeanToInteract;
	struct Panel_Story;
	struct Panel_TorchLight;
	struct Panel_TutorialPopup;
	struct Panel_WeaponPicker;
	struct Panel_WorldMap;

	struct MissionUI;
	struct ContainerUI;

	// ==========================================================================================

	struct Vector2
	{
		float x;
		float y;
	};

	struct Vector3
	{
		float x;
		float y;
		float z;
	};

	struct Quaternion
	{
		float x;
		float y;
		float z;
		float w;
	};

	struct Color
	{
		float r;
		float g;
		float b;
		float a;
	};

	struct Object
	{
		void* _unknown0;
		void* _unknown1;
		void* m_CachedPtr;
	};

	struct Behaviour : Object
	{
	};

	struct MonoBehaviour : Behaviour
	{
	};

	struct BodyDamage : MonoBehaviour
	{
		enum class Weapon : uint32_t
		{
			Unspecified = 0,
			Arrow = 1,
			FlareGun = 2,
			Revolver = 3,
			Rifle = 4
		};
	};

	struct ConditionTableManager : MonoBehaviour
	{
		enum class ConditionTableType : int32_t
		{
			Unknown = -1,
			Meat = 0,
			DryFood = 1,
			CannedFood = 2,
			Clothing = 3,
			Ammunition = 4
		};
	};

	struct StackableItem : MonoBehaviour
	{
		int32_t m_Units;
		int32_t m_UnitsPerItem;
		LocalizedString* m_LocalizedSingleUnitText;
		LocalizedString* m_LocalizedMultipleUnitText;
		StackableItem** m_ShareStackWithGear;
		String* m_StackSpriteName;
		GearItem* m_InstantiateStackItem;
		bool m_StackByCondition;
	};

	struct LiquidItem : MonoBehaviour
	{
		float m_LiquidLiters;
		float m_LiquidCapacityLiters;
		GearLiquidTypeEnum m_LiquidType;
		LiquidQuality m_LiquidQuality;
		float m_TimeToDrinkSeconds;
		String* m_DrinkingAudio;
		float m_AmountPerUse;
		bool m_RandomizeQuantity;
	};

	struct WaterSupply : MonoBehaviour
	{
		LiquidQuality m_WaterQuality;
		float m_VolumeInLiters;
		float m_TimeToDrinkSeconds;
		String* m_DrinkingAudio;
	};

	struct FuelSourceItem : MonoBehaviour
	{
		float m_FireStartSkillModifier;
		float m_FireStartDurationModifier;
		float m_BurnDurationHours;
		float m_HeatIncrease;
		float m_HeatInnerRadius;
		float m_HeatOuterRadius;
		float m_FireAgeMinutesBeforeAdding;
		bool m_IsTinder;
		bool m_IsWet;
		bool m_IsBurntInFireTracked;
	};

	struct KeroseneLampItem : MonoBehaviour
	{
		float m_MaxFuelLiters;
		float m_FuelBurnLitersPerHour;
		float m_TurnOnEffectsDelay;
		float m_TurnOffDelay;
		String* m_TurnOnAudio;
		String* m_ExtinguishStartAudio;
		String* m_TurnOffAudio;
		String* m_LoopAudioWithDelay;
		String* m_LoopAudio;
		float m_RefuelTimeSeconds;
		String* m_RefuelAudio;
		float m_TurnOnEffectsTimer;
		float m_CurrentFuelLiters;
		KeroseneLampIntensity* m_IntensityComponent;
		Color m_Color;
		uint32_t m_TurnOnAudioID;
		uint32_t m_ExtinguishStartAudioID;
		uint32_t m_LoopAudioID;
		bool m_On;
		bool m_TurnOnComplete;
		GameObject* m_FXGameObject;
		Light* m_LightIndoor;
		Light* m_LightIndoorCore;
		Light* m_LightOutdoor;
		float m_TurnOffTimer;
		bool m_TurningOff;
		HeatSource* m_HeatSource;
		float m_TimeToBreak;
		GearItem* m_GearItem;
	};

	struct FlashlightItem : MonoBehaviour
	{
		enum class State : uint32_t
		{
			Off = 0,
			Low = 1,
			High = 2
		};

		Color m_Color;
		AuroraField* m_AuroraField;
		GameObject* m_FxObjectLow;
		GameObject* m_FxObjectHigh;
		Light* m_LightIndoor;
		Light* m_LightOutdoor;
		Light* m_LightIndoorHigh;
		Light* m_LightOutdoorHigh;
		String* m_TurnOnAudio;
		String* m_TurnOffAudio;
		float m_LowBeamDuration;
		float m_HighBeamDuration;
		float m_RechargeTime;
		float m_HighBeamCooldownSeconds;
		float m_AuroraFieldForwardOffset;
		float m_AuroraFieldVerticalOffset;
		GearItem* m_GearItem;
		State m_State;
		uint32_t m_TurnOnAudioId;
		uint32_t m_TurnOffAudioId;
		float m_CurrentBatteryCharge;
		float m_HighBeamCooldownEndTime;
		uint32_t m_IntensityAudioID;
	};

	struct Inventory : MonoBehaviour
	{
		List<GearItemObject>* m_Items;
		List<GearItem>* m_ItemsToDestroy;
		float m_MinimumViableWaterAmount;
		GearItem* m_WaterSupplyPotable;
		GearItem* m_WaterSupplyNotPotable;
		float m_WeightGeneral;
		float m_WeightMetal;
		float m_WeightWater;
		float m_WeightWood;
		float m_TotalWeight;
		float m_WeightGeneral_LastSent;
		float m_WeightMetal_LastSent;
		float m_WeightWater_LastSent;
		float m_WeightWood_LastSent;
		bool m_StartHasBeenCalled;
		bool m_ForceOverrideWeight;
		float m_OverridedWeight;
		float m_TotalScentIntensity;
		bool m_ConsumedCoffee;
		bool m_ConsumedRosehipTea;
		bool m_ConsumedReishiTea;
		bool m_ConsumedOldMansBeardDressing;
		bool m_SuppressScentIndicator;
		GameObject** m_QuickSelectSlots;
	};

	struct GearItem : MonoBehaviour
	{
		uint32_t m_InstanceID;
		bool m_BeenInPlayerInventory;
		bool m_HasBeenOwnedByPlayer;
		bool m_BeenInContainer;
		bool m_BeenInspected;
		bool m_InPlayerInventory;
		bool m_ItemLooted;
		bool m_InitialDecayApplied;
		bool m_IsInSatchel;
		uint32_t m_SatchelIndex;
		uint32_t m_InsideContainer;
		float m_NormalizedRevealTimeInContainer;
		bool m_LockedInContainer;
		bool m_IsHidden;
		Vector3 m_localScaleAtAwake;
		AmmoItem* m_AmmoItem;
		AmmoCasingItem* m_AmmoCasingItem;
		ArrowItem* m_ArrowItem;
		BearSpearItem* m_BearSpearItem;
		Bed* m_Bed;
		BodyHarvestItem* m_BodyHarvestItem;
		BodyHarvest* m_BodyHarvest;
		BowItem* m_BowItem;
		BreakDownItem* m_BreakDownItem;
		CanOpeningItem* m_CanOpeningItem;
		CarryableBody* m_CarryableBody;
		CarryingCapacityBuff* m_CarryingCapacityBuff;
		CharcoalItem* m_CharcoalItem;
		Cleanable* m_Cleanable;
		ClothingItem* m_ClothingItem;
		ConditionOverTimeBuff* m_ConditionOverTimeBuff;
		ConditionRestBuff* m_ConditionRestBuff;
		Cookable* m_Cookable;
		CookingPotItem* m_CookingPotItem;
		DegradeOnUse* m_DegradeOnUse;
		EmergencyStimItem* m_EmergencyStim;
		EnergyBoostItem* m_EnergyBoost;
		EvolveItem* m_EvolveItem;
		FatigueBuff* m_FatigueBuff;
		FireStarterItem* m_FireStarterItem;
		FirstAidItem* m_FirstAidItem;
		FirstPersonItem* m_FirstPersonItem;
		FishingItem* m_FishingItem;
		FlareItem* m_FlareItem;
		FlashlightItem* m_FlashlightItem;
		FoodItem* m_FoodItem;
		FoodWeight* m_FoodWeight;
		ForageItem* m_ForageItem;
		ForceLockItem* m_ForceLockItem;
		FreezingBuff* m_FreezingBuff;
		FuelSourceItem* m_FuelSourceItem;
		HandheldShortwaveItem* m_HandheldShortwaveItem;
		GunItem* m_GunItem;
		Harvest* m_Harvest;
		IceFishingHoleClearItem* m_IceFishingHoleClearItem;
		InProgressCraftItem* m_InProgressCraftItem;
		Inspect* m_Inspect;
		KeroseneLampItem* m_KeroseneLampItem;
		Knowledge* m_Knowledge;
		LiquidItem* m_LiquidItem;
		MatchesItem* m_MatchesItem;
		Millable* m_Millable;
		NarrativeCollectibleItem* m_NarrativeCollectibleItem;
		ShowOnMapItem* m_ShowOnMapItem;
		OwnershipOverride* m_OwnershipOverrideItem;
		PlaceableItem* m_PlaceableItem;
		PowderItem* m_PowderItem;
		PurifyWater* m_PurifyWater;
		Repairable* m_Repairable;
		ResearchItem* m_ResearchItem;
		RopeItem* m_RopeItem;
		Scent* m_Scent;
		Sharpenable* m_Sharpenable;
		SmashableItem* m_SmashableItem;
		SnareItem* m_SnareItem;
		SprayPaintCan* m_SprayPaintCan;
		StackableItem* m_StackableItem;
		StoneItem* m_StoneItem;
		StruggleBonus* m_StruggleBonus;
		ToolsItem* m_ToolsItem;
		TorchItem* m_TorchItem;
		WaterSupply* m_WaterSupply;
		WildlifeItem* m_WildlifeItem;
		WolfIntimidationBuff* m_WolfIntimidationBuff;
		MeshRenderer** m_MeshRenderers;
		SkinnedMeshRenderer** m_SkinnedMeshRenderers;
		ObjectGuid* m_ObjectGuid;
		MissionObjectIdentifier* m_MissionObject;
		OnDroppedInWaterDelegate* m_OnDroppedInWater;
		RadialObjectSpawner* m_RadialObjectSpawnerParent;
		Container* m_LastContainer;
		String* m_PlacePointGuid;
		String* m_PlacePointName;
		uintptr_t m_PhysicsEnabled;
		Rigidbody* m_RigidBody;
		bool m_UnequipInProgress;
		GearTypeEnum m_Type;
		List<GearTypeEnum>* m_AdditionalTypesInventoryFilter;
		bool m_ShouldUseProjectilePhysics;
		bool m_RemainInInventoryOnDrop;
		LocalizedString* m_LocalizedDisplayName;
		LocalizedString* m_LocalizedDescription;
		GearScarcityEnum m_Scarcity;
		float m_WeightKG;
		float m_CurrentHP;
		float m_MaxHP;
		float m_DailyHPDecay;
		float m_ScentIntensity;
		GearStartCondition m_StartCondition;
		GearMovementSound m_MovementSoundCategory;
		String* m_PickUpAudio;
		String* m_StowAudio;
		String* m_PutBackAudio;
		String* m_WornOutAudio;
		String* m_CookingSlotPlacementAudio;
		float m_SpawnChance;
		float m_GearBreakConditionThreshold;
		bool m_NonInteractive;
		ConditionTableManager::ConditionTableType m_ConditionTableType;
		bool m_DisableFavoriting;
		bool m_DisableSerialization;
		bool m_AlwaysHarvestedByPlayer;
		bool m_PromptsPersistUntilUsed;
		bool m_AutoEquipOnInteract;
		bool m_RequiredForMission;
		String* m_CoverflowMainTextureResourcePath;
		String* m_CoverflowDamageTextureResourcePath;
		String* m_CoverflowBlendTextureResourcePath;
		String* m_CoverflowOpenedTextureResourcePath;
		GearDummyType m_DummyGearType;
		String* m_GearName;
		bool m_RolledSpawnChance;
		bool m_WornOut;
		bool m_HaltDecay;
		bool m_HarvestedByPlayer;
		float m_LastUpdateDamageShaderCondition;
		bool m_MarkedForNextUpdateDestroy;
		bool m_StartHasBeenCalled;
		float m_DecayScalar;
		float m_LastUpdatedTODHours;
		bool m_LastUpdatedTODHoursInitialized;
		bool m_HasBeenEquippedAndUsed;
		bool m_IsTextureStreamingDisabled;
	};

	struct GameManager : MonoBehaviour
	{
		GameObject* m_AiDifficultySettingsPrefab;
		GameObject* m_AiSubsystemsPrefab;
		GameObject* m_BlueprintsPrefab;
		GameObject* m_ConditionSystemsPrefab;
		GameObject* m_ConditionTableSystemsPrefab;
		GameObject* m_EffectPoolManagerPrefab;
		GameObject* m_EngineSystemsPrefab;
		GameObject* m_EnvironmentSystemsPrefab;
		GameObject* m_ExperienceModesPrefab;
		GameObject* m_FirstAidSystemsPrefab;
		GameObject* m_GamePlaySystemsPrefab;
		GameObject* m_PlayerSystemsPrefab;
		GameObject* m_PlayerObjectPrefab;
		GameObject* m_RumbleEffectManagerPrefab;
		GameObject* m_SandboxManagerPrefab;
		GameObject* m_StoryManagerPrefab;
		DialogueStatesTable* m_DialogueStatesTable;
		MissionObjectiveTable* m_MissionObjectiveTable;
		AfflictionDefinitionTable* m_AfflictionDefinitionTable;
		SceneMapping* m_SceneMapping;
		GameObject* m_ConditionSystems;
		GameObject* m_ConditionTableSystems;
		GameObject* m_EngineSystems;
		GameObject* m_EnvironmentSystems;
		GameObject* m_ExperienceModes;
		GameObject* m_FirstAidSystems;
		GameObject* m_GamePlaySystems;
		GameObject* m_PlayerSystems;
		bool m_DoBurntHouseCheckNextFrame;
		bool m_SetQualitySettingsForLoadedScene;
		bool m_SetAudioModeForLoadedScene;
		float m_HeatmapTimer;
	};

	struct HUDManager : MonoBehaviour
	{
		float m_CrosshairAlpha;
		float Crosshair_FadeTimeSeconds;
		bool m_HasDoneLocationReveal;
	};

	struct Panel_Confirmation
	{
		struct CallbackDelegate;
	};

	struct Panel_Base : MonoBehaviour
	{
		int32_t m_PanelId;
	};

	struct Panel_Inventory : Panel_Base
	{
		GameObject* m_SurvivalTabs;
		GameObject* m_StoryTabs;
		GameObject* TableObject;
		GameObject* InventoryItemPrefab;
		int32_t m_MaxItemsDisplayAtOnce;
		UILabel* m_Label_CarryCapacity;
		GameObject* m_MouseButtonBack;
		UISprite* m_CapacityBarOutline;
		UISprite* m_CapacityBarSprite;
		Color m_CapacityNormalColor;
		Color m_CapacityOverloadColor;
		Color m_CapacityBuffColor;
		UIButton* m_DefaultFilterButton;
		UIButton* m_DefaultSortButton;
		UIButton** m_SortButtons;
		UIButton** m_FilterButtons;
		UILabel* m_CategoryLabel;
		GameObject* m_ScrollbarObject;
		Color m_LowConditionColor;
		Color m_MediumConditionColor;
		Color m_HighConditionColor;
		float m_AlphaWhenInBackground;
		GameObject* m_InteractionBlocker;
		GameObject* m_ButtonBack;
		UILabel* m_LabelNoItems;
		Color m_ColorFilterSelected;
		Color m_ColorFilterSelectedHover;
		Color m_ColorFilterUnselectedEmpty;
		Color m_ColorFilterUnselectedEmptyHover;
		Color m_ColorFilterUnselectedNonempty;
		Color m_ColorFilterUnselectedNonemptyHover;
		Color m_ColorFilterSelectedFAKHasAffliction;
		Color m_ColorFilterUnselectedFAKHasAffliction;
		Color m_ColorFilterUnselectedFAKHasAfflictionEmpty;
		GameObject* m_Stats;
		UILabel* m_AirTempLabel;
		UILabel* m_AirTempHeaderLabel;
		UILabel* m_WindChillLabel;
		UILabel* m_WindChillHeaderLabel;
		UILabel* m_ClothingWarmthLabel;
		UILabel* m_ClothingWarmthHeaderLabel;
		UILabel* m_ClothingWindproofLabel;
		UILabel* m_ClothingWindproofHeaderLabel;
		UILabel* m_TemperatureLabel;
		GameObject* m_SelectedSpriteObj;
		TweenScale* m_SelectedSpriteTweenScale;
		UILabel* m_CategoryWeightLabel;
		GameObject* m_CategoryWeightBG;
		UILabel* m_ClothingWeightLabel;
		GameObject* m_ClothingWeightBG;
		float m_SecondsBetweenMove;
		List<GearItem>* m_FilteredInventoryList;
		int32_t m_TableNumColumns;
		float m_TableSpacingHorizontal;
		float m_TableSpacingVertical;
		UILabel* m_RuinedLabel;
		GameObject* m_ItemDescriptionPageDummy;
		GameObject* m_ItemDescriptionPagePrefab;
		GameObject* m_GearItemCoverflowLocation;
		GameObject* m_GearItemCoverflowPrefab;
		GameObject* m_SortLabel;
		GameObject* m_SortButtonsObject;
		float m_PlaceObjectHoldDuration;
		ButtonLegendContainer* m_ButtonLegendContainer;
		ButtonLegendContainer* m_SortButtonLegendContainer;
		GameObject* m_SelectedEffect;
		bool m_EnableDiaryOnExit;
		UISlider* m_ScrollbarSlider;
		UIButton* m_SelectedFilterButton;
		UIButton* m_SelectedSortButton;
		String* m_SelectedSortOldSprite;
		String* m_FilterName;
		String* m_SortName;
		Dictionary<String, bool>* m_SortFlipDictionary;
		int32_t m_SelectedSortIndex;
		int32_t m_SelectedFilterIndex;
		int32_t m_SelectedItemIndexVal;
		int32_t m_NumItemsDisplayed;
		int32_t m_FirstItemDisplayedIndexVal;
		int32_t m_NumFramesInPanel;
		uint32_t m_OpenCloseAudioID;
		GearItem* m_LastSelectedGearItem;
		float m_SecondsToNextMove;
		int32_t m_NumColumns;
		InventoryGridItem** m_TableItems;
		UIPanel* m_Panel;
		GearItem* m_LastDroppedSingleGearItem;
		bool m_IsDirty;
		bool m_ForceSelectionUpdate;
		ItemDescriptionPage* m_ItemDescriptionPage;
		GearItemCoverflow* m_GearItemCoverflow;
		bool m_PausedAndHidden;
		Transform* m_SectionNavSelectedSprite;
		GameObject* m_SectionNavArrowPrompts;
		int32_t m_SectionNavIndex;
		bool m_IsInSectionNav;
		float m_DropButtonHeldTime;
		GamepadButtonSprite** m_GamepadButtonSprites;
		bool m_MovementPressedOnEnable;
		GameObject** m_SlotLabels;
	};

	struct Panel_Container : Panel_Base
	{
		struct ContainerUIConfig
		{
			void* _unknown0;
			void* _unknown1;
			MissionUI* m_MissionUIComponent;
			ContainerUI* m_ContainerUIComponent;
		};

		enum class ContainerMode : uint32_t
		{
			Standard = 0,
			Mission = 1
		};

		ContainerUIConfig* m_StandardConfig;
		ContainerUIConfig* m_MissionConfig;
		ButtonLegendContainer* m_ButtonLegendContainer;
		UILabel* m_Label_CarryCapacity;
		UISprite* m_CapacityBarSprite;
		UISprite* m_CapacityBarOutline;
		UILabel* m_Label_ContainerCapacity;
		UIButton* m_DefaultFilterButton;
		UIButton* m_DefaultSortButton;
		UIButton** m_SortButtons;
		UIButton** m_FilterButtons;
		UILabel* m_CategoryLabel;
		ItemDescriptionPage* m_ItemDescriptionPage;
		UILabel* m_NameplateLabel;
		float m_AlphaUnselectedSide;
		UISprite* m_FilterLeftGamepadButtonSprite;
		UISprite* m_FilterRightGamepadButtonSprite;
		bool m_EnablePauseMenuOnExit;
		Container* m_Container;
		List<GearItem>* m_FilteredInventoryList;
		List<GearItem>* m_FilteredContainerList;
		Color m_FilterLockedDisabledColor;
		GameObject* m_SortLabel;
		GameObject* m_SortButtonsObject;
		GameObject* m_SelectedSpriteObj;
		TweenScale* m_SelectedSpriteTweenScale;
		UIButton* m_SelectedFilterButton;
		UIButton* m_SelectedSortButton;
		String* m_SelectedSortOldSprite;
		Dictionary<String, bool>* m_SortFlipDictionary;
		ContainerMode m_ContainerMode;
		String* m_ContainerDisplayName;
		SelectedTableEnum m_SelectedTableVal;
		String* m_InventoryFilterName;
		String* m_InventorySortName;
		int32_t m_SelectedSortIndex;
		MissionUI* m_MissionUIComponent;
		ContainerUI* m_ContainerUIComponent;
		int32_t m_InventorySelectedItemIndexVal;
		int32_t m_InventoryNumItemsDisplayed;
		int32_t m_InventoryFirstItemDisplayedIndexVal;
		int32_t m_ContainerSelectedItemIndexVal;
		int32_t m_ContainerNumItemsDisplayed;
		int32_t m_ContainerFirstItemDisplayedIndexVal;
		bool m_EnablePending;
		float m_EnableDelaySeconds;
		float m_EnableDelayElapsed;
		bool m_ShouldResetSelectedItem;
		int32_t m_NumFramesPanelActive;
		bool m_ForceRefreshRequested;
		Transform* m_SectionNavSelectedSprite;
		GameObject* m_SectionNavArrowPrompts;
		int32_t m_SectionNavIndex;
		bool m_IsInSectionNav;
		StoryMissionObjective* m_ObjectiveToShow;
		int m_HasRequestedObjectiveUpdate;
	};

	struct Panel_Map : Panel_Base
	{
		enum class HoverState : uint32_t
		{
			None,
			BigSprite,
			SmallSprite,
			Area
		};

		enum class IconDisplayFilters : uint32_t
		{
			None = 0,
			Resources = 1,
			Structures = 2,
			Corpses = 4,
			RockCaches = 8,
			SprayMarkers = 16,
			All = 31
		};

		GameObject* m_SurvivalTabs;
		GameObject* m_StoryTabs;
		ButtonLegendContainer* m_ButtonLegendContainer;
		GenericButtonMouseSpawner* m_WorldMapButtonObj;
		UILabel* m_HeaderLabel;
		Transform* m_MapElementsTransform;
		MapCrosshair* m_Crosshair;
		Transform* m_PlayerIcon;
		GameObject* m_BigSpritePrefab;
		Transform* m_BigSpritePoolParent;
		Transform* m_BigSpriteActiveObjects;
		GameObject* m_SmallSpritePrefab;
		Transform* m_SmallSpritePoolParent;
		Transform* m_SmallSpriteActiveObjects;
		GameObject* m_DetailEntryPrefab;
		Transform* m_DetailEntryPoolParent;
		Transform* m_DetailEntryActiveObjects;
		GameObject* m_TextPrefab;
		Transform* m_TextPoolParent;
		Transform* m_TextActiveObjects;
		GameObject* m_AreaPrefab;
		Transform* m_AreaPoolParent;
		Transform* m_AreaActiveObjects;
		GameObject* m_RegionSelectObject;
		UILabel* m_LastUpdatedLabel;
		GameObject* m_MousePromptDelete;
		float m_DetailSurveyRadiusMeters;
		float m_DetailSurveyRockCacheRadiusMeters;
		float m_DetailSurveySprayPaintRadiusMeters;
		float m_DetailSurvayPolaroidRadiusMeters;
		float m_RangeToShowMapIcons;
		float m_ZoomedInSize;
		float m_GamepadMoveSpeed;
		float m_MagnetizeSpeed;
		List<RegionMap>* m_MapObjects;
		RegionMap* m_WorldMapObject;
		List<String>* m_LocationsToUseBigSprite;
		List<String>* m_OutdoorLocationLabelsToIgnore;
		bool m_DoMapCondense;
		float m_MapCondenseDistance;
		bool m_DoMapIconSpacing;
		float m_MapIconSpacingDistance;
		bool m_MergeMissionIconsWithLocations;
		float m_MapIconLocationSpacingDistance;
		String* m_MessageMapIcon;
		LocalizedString* m_SprayPaintQuickKeyMapHeader;
		LocalizedString* m_SprayPaintQuickKeyMapMessage;
		LocalizedString* m_VistaLocationDiscoveredHeader;
		LocalizedString* m_VistaLocationDiscoveredMessage;
		String* m_VistaDiscoverDynamicString;
		int32_t m_ScreenTopOffset;
		int32_t m_ScreenBottomOffset;
		int32_t m_ScreenLeftOffset;
		int32_t m_ScreenRightOffset;
		String* m_OpenMapAudio;
		String* m_CloseMapAudio;
		String* m_ChangeMapAudio;
		String* m_VistaCompletedAudio;
		float m_HoursThresholdJustNow;
		float m_HoursThresholdHoursAgo;
		float m_HoursThresholdToday;
		float m_HoursThresholdYesterday;
		TweenAlpha* m_ObjectiveTween;
		UILabel* m_ObjectiveLabel;
		UILabel* m_ObjectiveDesc;
		UISprite* m_ObjectiveIcon;
		GameObject* m_CartographyFilters;
		float m_FilterVerticalDelayTimeSeconds;
		UIButton* m_ResourcesButton;
		UIWidget* m_ResourcesOffOnDeselect;
		UIButton* m_StructuresButton;
		UIWidget* m_StructuresOffOnDeselect;
		UIButton* m_CorpsesButton;
		UIWidget* m_CorpsesOffOnDeselect;
		UIButton* m_RockCachesButton;
		UIWidget* m_RockCachesOffOnDeselect;
		UIButton* m_SprayMarkingsButton;
		UIWidget* m_SprayMarkingsOffOnDeselect;
		int32_t m_CartographyRockCacheSkillLevel;
		int32_t m_CartographyFilterSkillLevel;
		int32_t m_CartographyMarkerSkillLevel;
		List<String>* m_StructuresKeywordList;
		List<String>* m_CorpseKeywordList;
		String* m_RockCacheKeyword;
		String* m_UserMarkerKeyword;
		float m_MarkerClusterMapSize;
		String* m_SprayClusterIcon;
		String* m_RockCacheClusterIcon;
		String* m_MarkerClusterLocID;
		String* m_LowVisibilitySurveyLocId;
		float m_MultiMarkerIconSize;
		String** m_LocationNames;
		String** m_SpriteAssignments;
		bool m_HasBeenUpdated;
		Dictionary<String, List<MapElementSaveData>>* m_MapElementData;
		Dictionary<Transform, MapElementSaveData>* m_TransformToMapData;
		Dictionary<String, List<DetailSurveyPosition>>* m_DetailSurveyPositions;
		Dictionary<String, float>* m_DetailSurveyLastUpdateTimes;
		Dictionary<String, FogOfWar>* m_FogOfWar;
		Dictionary<String, List<VistaLocationData>>* m_SurveyedVistaLocations;
		List<VistaLocation>* m_ActiveVistaLocations;
		List<VistaLocation>* m_VistaLocationList;
		List<MapElementRemovalData>* m_DelayedMapElementRemovals;
		bool m_IsZoomed;
		HoverState m_HoverState;
		Vector3 m_MapElementsOrigPos;
		MapIcon* m_MapIconBeingHovered;
		MapIcon* m_MapIconToRenameDelete;
		UIWidget* m_CrosshairWidget;
		bool m_StartHasBeenCalled;
		String* m_RegionNameOfLoadedObjects;
		List<String>* m_UnlockedRegionNames;
		int32_t m_RegionSelectedIndex;
		MissionMapMarkerInfo** m_MarkerInfoFromResources;
		uint32_t m_OpenCloseAudioID;
		bool m_DoMapCondenseInternal;
		bool m_DoMapIconSpacingInternal;
		bool m_MergeMissionIconsWithLocationsInternal;
		GamepadButtonSprite** m_GamepadButtonSprites;
		MapElementSaveData* m_ObjectIconMapData;
		IconDisplayFilters m_IconDisplayFilters;
		List<UIWidget>* m_FilterOffOnDeselect;
		bool m_FilterSelecterEnabled;
		int32_t m_FilterSelectionIndex;
		List<ClusterCell>* m_ClusterCells;
		MapElementSaveData* m_LastMapElementAdded;
	};

	struct InterfaceManager_StaticFields
	{
		GameObject* s_BasicMenuPrefab;
		GameObject* m_CommonGUI;
		bool m_ImmediatelyExitOverlay;
		bool m_ShowCalories;
		bool m_ShowTemperature;
		Panel_Actions* m_Panel_Actions;
		Panel_ActionPicker* m_Panel_ActionPicker;
		Panel_ActionsRadial* m_Panel_ActionsRadial;
		Panel_Affliction* m_Panel_Affliction;
		Panel_Badges* m_Panel_Badges;
		Panel_BedRollSelect* m_Panel_BedRollSelect;
		Panel_BodyHarvest* m_Panel_BodyHarvest;
		Panel_BreakDown* m_Panel_BreakDown;
		Panel_CanOpening* m_Panel_CanOpening;
		Panel_ChallengeComplete* m_Panel_ChallengeComplete;
		Panel_Challenges* m_Panel_Challenges;
		Panel_ChooseChallenge* m_Panel_ChooseChallenge;
		Panel_ChooseEpisodeExperience* m_Panel_ChooseEpisodeExperience;
		Panel_ChooseSandbox* m_Panel_ChooseSandbox;
		Panel_Choose4DON* m_Panel_Choose4DON;
		Panel_ChooseStory* m_Panel_ChooseStory;
		Panel_Clothing* m_Panel_Clothing;
		Panel_Confirmation* m_Panel_Confirmation;
		Panel_Container* m_Panel_Container;
		Panel_Cooking* m_Panel_Cooking;
		Panel_Crafting* m_Panel_Crafting;
		Panel_Credits* m_Panel_Credits;
		Panel_CustomXPSetup* m_Panel_CustomXPSetup;
		Panel_Diagnosis* m_Panel_Diagnosis;
		Panel_EpisodeContinue* m_Panel_EpisodeContinue;
		Panel_EpisodeSelection* m_Panel_EpisodeSelection;
		Panel_Extras* m_Panel_Extras;
		Panel_Debug* m_Panel_Debug;
		Panel_FeedFire* m_Panel_FeedFire;
		Panel_FireStart* m_Panel_FireStart;
		Panel_FirstAid* m_Panel_FirstAid;
		Panel_GearSelect* m_Panel_GearSelect;
		Panel_GenericProgressBar* m_Panel_GenericProgressBar;
		Panel_Harvest* m_Panel_Harvest;
		Panel_Help* m_Panel_Help;
		Panel_HUD* m_Panel_HUD;
		Panel_IceFishing* m_Panel_IceFishing;
		Panel_IceFishingHoleClear* m_Panel_IceFishingHoleClear;
		Panel_Inventory* m_Panel_Inventory;
		Panel_Inventory_Examine* m_Panel_Inventory_Examine;
		Panel_Knowledge* m_Panel_Knowledge;
		Panel_Loading* m_Panel_Loading;
		Panel_Log* m_Panel_Log;
		Panel_MainMenu* m_Panel_MainMenu;
		Panel_Map* m_Panel_Map;
		Panel_MarkerList* m_Panel_MarkerList;
		Panel_Milling* m_Panel_Milling;
		Panel_MissionsStory* m_Panel_MissionsStory;
		Panel_Notifications* m_Panel_Notifications;
		Panel_OptionsMenu* m_Panel_OptionsMenu;
		Panel_PauseMenu* m_Panel_PauseMenu;
		Panel_PickUnits* m_Panel_PickUnits;
		Panel_PickWater* m_Panel_PickWater;
		Panel_Repair* m_Panel_Repair;
		Panel_Rest* m_Panel_Rest;
		Panel_SafeCracking* m_Panel_SafeCracking;
		Panel_SaveIcon* m_Panel_SaveIcon;
		Panel_SaveStory* m_Panel_SaveStory;
		Panel_Sandbox* m_Panel_Sandbox;
		Panel_Sandbox4DON* m_Panel_Sandbox4DON;
		Panel_SelectChallengeType* m_Panel_SelectChallengeType;
		Panel_SelectExperience* m_Panel_SelectExperience;
		Panel_SelectRegion* m_Panel_SelectRegion;
		Panel_SelectSurvivor* m_Panel_SelectSurvivor;
		Panel_SnowShelterBuild* m_Panel_SnowShelterBuild;
		Panel_SnowShelterInteract* m_Panel_SnowShelterInteract;
		Panel_SprayPaint* m_Panel_SprayPaint;
		Panel_LeanToBuild* m_Panel_LeanToBuild;
		Panel_LeanToInteract* m_Panel_LeanToInteract;
		Panel_Story* m_Panel_Story;
		Panel_TorchLight* m_Panel_TorchLight;
		Panel_TutorialPopup* m_Panel_TutorialPopup;
		Panel_WeaponPicker* m_Panel_WeaponPicker;
		Panel_WorldMap* m_Panel_WorldMap;
		GameObject* m_TimeWidget;
		Panel_Confirmation::CallbackDelegate* m_ConfirmRequest;
		bool s_IsOverlayActive;
		bool s_UseSdAtlases;
	};
}
