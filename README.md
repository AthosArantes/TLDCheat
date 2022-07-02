# The Long Dark Cheat
A small cheat for the game **The Long Dark** compatible with steam version 2.0.0.91441;\
Using cheats will degrade gameplay experience.\
Use at own risk.

## Features:
- Always show crosshair;
- One-Hit kill;
- Steady camera (Greatly reduces aiming sway);
- Unlimited lamp fuel;
- Increase/Decrease item units in player inventory;
- Repair item in player inventory;
- Remove items from player inventory;
- Remove collision between items;
- Allow flashlight to be turned on at any time;
- Allow movement while aiming the revolver;
- Speedhack (Up to 10x);

## How to use:
First you will need to compile it (The cheat was compiled using Visual Studio 2022, tested and it is functional on Windows 10).\
Then you will be able to inject the .dll when the game is running. Any basic injector will do.

**General cheats (Only works if you are not in Inventory panel):**
|Cheat|Key|
|--|--|
|Toggle steady camera|KeyPad 0|
|Toggle always show crosshair|KeyPad 1|
|Toggle item placement collision|KeyPad 2|
|Toggle One-Hit kill|KeyPad 3|
|Toggle unlimited lamp fuel|KeyPad 4|
|Toggle flashlight use|KeyPad 5|
|Toggle movement while aiming revolver|KeyPad 6|
|Toggle speedhack|KeyPad 9|
|Increase speedhack movement|KeyPad +|
|Decrease speedhack movement|KeyPad -|
|Quickly disable all cheats|End|

**Inventory cheats (Only works if you are in the Inventory panel):**
|Cheat|Key|
|--|--|
|Duplicate selected item (non-stackable items)|Insert|
|Delete selected item|Delete|
|Increase selected item count by 1|KeyPad +|
|Decrease selected item count by 1|KeyPad -|
|Repair selected item|KeyPad *|

**Notes:**
- The inventory cheats does not work when inside a container (not implemented);

## Libraries used:
[distormx](https://github.com/gdabah/distormx)
