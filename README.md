# UE4_1_BattleTankGame
Open world head to head tank battle game, with AI, terrain and advanced control, UE4
For Github Repository click [here](https://github.com/chineseburn/UE4_1_BattleTank)
Andrew Paine

---
## GDD

Tank Battle, open world head to head combat game
Terrain used for tactical advantage
Focus on flow & feel

Rules
Move anywhere, surrounded by mountains
Both players start with finite health and ammo
direct hit reduces health
last player standing = winner

Requirements
SFX - gun, explosion, barrel / turret moving, engine
Static Meshes (star with primitive objects) - simple tank comprising tracks, body, turret & barrel
Textures - add for visual flare later
Music - background music for tension

## Iterative Cycle
World -> tank-> control -> player 2 (AI or human) -> User Interface (UI) -> world (repeat)

## Commits
* BT01_UE4 Game Design Document (GDD)
* BT02_UE4 Iterative Cycle (IC)
* BT03_UE4 Unreal File Creation
* BT04_UE4 Landscape Creation
* BT05_UE4 Tank Creation & Binding
* BT06_UE4 Fix 3rd Person Camera
* BT07_UE4 Player UI widget & TankPlayerControl
* BT08_UE4 Startermenu + UI Scale, Mouse & Buttons
* BT09_UE4 Controller Ready Navigation StartMenu
* BT10_UE4 Unreal UI, UMG & C++
* BT11_UE4 Get PlayerController & Tick
* BT12_UE4 Aiming Component and test
* BT13_UE4 Finding Pixel coords
* BT14_UE4 DeprojectScreenToWorld
* BT15_UE4 LineTraceSingleByChannel()
* BT16_UE4 Unify Player & AI Aiming
* BT17_UE4 Creating Default Sub Objects
* BT18_UE4 BluePrintCallable()
* BT19_UE4 SuggestProjectileVelocity() (UGameStatics)
* BT20_UE4 FRotators, Barrel movement beginning
* BT21_UE4 221: Forward Declarations
* BT22_UE4 222: BlueprintSpawnableComponent()
