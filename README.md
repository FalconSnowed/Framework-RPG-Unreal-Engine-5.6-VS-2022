# MyRPG - Modular RPG Framework (UE 5.6)

A modular RPG framework for Unreal Engine 5.6, designed for solo devs who love clean architecture, rich features, and extensibility.

---

## 🔧 Core Modules

### 📦 `InventoryComponent`

Manage all inventory items, quantities, and slots.

### 📦 `EquipmentComponent`

Handles equipment logic for weapons, armor, and more. Compatible with `EquippedItemStruct`.

### 📦 `StatComponent`

Stores and modifies player stats like HP, defense, etc. Used by combat and gameplay logic.

### 📦 `QuestComponent`

Quest tracking and completion logic, including current objectives and rewards.

### 📦 `DialogueComponent`

Simple dialogue branching system with support for NPC integration.

### 📦 `AbilityComponent`

Manages active and passive abilities, cooldowns, and usage logic.

### 📦 `CombatComponent` ✅ NEW!

* Handles melee attacks
* Supports hit detection in area
* Applies damage via `StatComponent`
* Triggers VFX (particle system)
* Handles critical hit logic

---

## 📁 Structs

* `InventoryItemStruct` — Basic info for inventory items.
* `EquippedItemStruct` — Used to define stats and effects of equipped items.

---

## 🎮 Main Character Class

`ARPGCharacter` includes:

* `InventoryComponent`
* `EquipmentComponent`
* `StatComponent`
* `CombatComponent`

---

## 🛠 Setup

1. Clone the repo
2. Generate Visual Studio project files
3. Open `.uproject` in Unreal Engine 5.6
4. Compile
5. 🎮 Play and test

---

## 📌 Notes

* Fully modular.
* BlueprintCallable for easy design use.
* Optimized for solo and small team projects.

---

## 📚 Future Modules

* 🎯 AIComponent (EnemyAI)
* 💬 Dialogue UI Widget
* 🌟 Leveling System
* 🧠 Behavior Tree integration

---

Made with ❤️ by Maëlik aka Light

---
