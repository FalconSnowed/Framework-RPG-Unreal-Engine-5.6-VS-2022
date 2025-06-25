# 🧙‍♂️ MyRPG — Modular C++ RPG Framework (Unreal Engine 5.6)

Bienvenue dans **MyRPG**, un framework RPG solo construit en C++ pour Unreal Engine 5.6, entièrement modulaire, extensible et propulsé par des composants Unreal (Inventory, Stats, Save, UI...).

---

## 📦 Features

### ✅ Core Components
- `UStatComponent` — Gère la vie, mana, attaque, défense et niveau.
- `UInventoryComponent` — Ajout, suppression et gestion des objets.
- `UEquipmentComponent` — Système d’équipement avec slots (`Head`, `Chest`, `Weapon`, etc.)
- `URPGSaveGame` — Sauvegarde persistante des statistiques et de l’inventaire.

### 🧙‍♀️ ARPGCharacter
- Contient les composants `InventoryComponent` et `StatComponent`.
- Peut sauvegarder et charger l’état du joueur avec `SavePlayerData()` et `LoadPlayerData()`.

### 🎒 Inventory System
- Struct `FInventoryItem` pour les objets.
- Widget `UInventorySlotWidget` (UMG + C++) avec **glisser-déposer intégré**.
- Support visuel avec icône, quantité, et opérations de drag & drop.
- Fonction `SwapItems()` à intégrer pour échanger dynamiquement deux objets.

### 💾 Sauvegarde & Chargement
- Sauvegarde automatique dans `PlayerSaveSlot`.
- Persistance de la santé, mana et inventaire.

### 🖱️ GUI Drag & Drop
- Widget `InventorySlotWidget` :
  - `UImage* ItemImage`
  - `UTextBlock* QuantityText`
  - Support `DragDropOperation` natif
- Système extensible pour l’intégration d’un `InventoryGridWidget` ou `EquipmentWidget`.

---

## 🧩 Structs

- `FInventoryItem` : Nom + quantité
- `FEquippedItem` : Slot + nom de l’objet équipé

---

## 🧠 Extension Suggestions

- 🔄 Ajoute `SwapItems()` dans `UInventoryComponent` pour gérer les échanges entre slots.
- 🎨 Intègre des icônes personnalisées via `UTexture2D*` dans chaque `FInventoryItem`.
- 📱 Ajoute un `UInventoryGridWidget` pour la vue globale avec un `UniformGridPanel`.
- ⚔️ Intègre les statistiques des objets équipés dans `UStatComponent`.

---

## 🛠️ Build Instructions

1. **Cloner le projet :**
   ```bash
   git clone https://github.com/votreuser/MyRPG.git
