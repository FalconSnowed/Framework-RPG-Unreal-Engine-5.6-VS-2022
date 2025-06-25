# 🎮 MyRPG Framework (WIP) – Unreal Engine 5.6

A modular, C++-based RPG framework built in **Unreal Engine 5.6**, designed to be lightweight, extensible, and beginner-friendly.  
This project is ideal for solo devs or small teams looking to bootstrap an RPG with save/load, inventory, stats, and character systems.

---

## 🔧 Features

### ✅ Core Systems Implemented
- `ARPGCharacter` with component-driven architecture
- `UInventoryComponent` to manage a dynamic item list
- `UStatComponent` to track current health and mana
- `URPGSaveGame` system to persist player data (stats + inventory)
- `FInventoryItem` struct with name and quantity

### 💾 Save/Load System
- Uses `UGameplayStatics::SaveGameToSlot` and `LoadGameFromSlot`
- Saves:
  - Player health
  - Player mana
  - Full inventory
- Can be extended to include equipment, XP, quests, etc.

---

## 🧱 Code Architecture

### ARPGCharacter.cpp
- Creates `InventoryComponent` and `StatComponent`
- Provides two main functions:
  - `SavePlayerData()` – saves stats and inventory
  - `LoadPlayerData()` – loads saved state into components

### FInventoryItem (struct)
```cpp
USTRUCT(BlueprintType)
struct FInventoryItem
{
    GENERATED_BODY();

    UPROPERTY(BlueprintReadWrite)
    FString Name;

    UPROPERTY(BlueprintReadWrite)
    int32 Quantity;

    FInventoryItem() : Name(TEXT("")), Quantity(0) {}
    FInventoryItem(const FString& InName, int32 InQuantity) : Name(InName), Quantity(InQuantity) {}
};
