# The Long Dark Cheat
A small cheat for the game **The Long Dark** compatible with steam version v1.78.63122;
Using cheats will degrade gameplay experience.
Use at own risk.

## Features:
- Always show crosshair;
- Never degrade items;
- One-Hit kill;
- Steady camera;
- Unlimited backpack weight;
- Unlimited storage weight;
- Unlimited lamp fuel;
- Increase/Decrease item units in player inventory (Also works with water, liquids and lamp);
- Repair item in player inventory;
- Speed hack (Up to 10x);

## How to use:
First you will need to compile it (The cheat was compiled using Visual Studio 2019 compiler, tested and it is functional on Windows 7 x64 SP1). Then you will be able to inject the .dll when the game is running. Any basic injector will do.

**General cheats (Only works if you are not in Inventory panel):**
|Cheat|Key|
|--|--|
|Toggle always show crosshair|KeyPad 0|
|Toggle One-Hit kill|KeyPad 1|
|Toggle never degrade items|KeyPad 2|
|Toggle steady camera|KeyPad 3|
|Toggle unlimited backpack|KeyPad 4|
|Toggle unlimited storage|KeyPad 5|
|Toggle unlimited lamp fuel|KeyPad 6|
|Increase movement speed|KeyPad +|
|Decrease movement speed|KeyPad -|
|Disable ALL cheats|End|

**Inventory cheats (Only works if you are in the Inventory panel):**
|Cheat|Key|
|--|--|
|Increase selected item count by 1|KeyPad +|
|Decrease selected item count by 1|KeyPad -|
|Increase selected item count by 5|**LeftShift** with **KeyPad +**|
|Decrease selected item count by 5|**LeftShift** with **KeyPad -**|
|Repair selected item|KeyPad *|

**Notes:**
- The inventory cheats does not work when inside a container (not implemented);
- Non-stackable items (like the Emergency Stim) cannot be incremented/decremented;
- Disabling all cheats (by pressing **End**) will remove all hooks. The only way to use cheats again is by injecting the .dll again;

## Libraries used:
[distormx](https://github.com/gdabah/distormx)
[fmt](https://github.com/fmtlib/fmt)
