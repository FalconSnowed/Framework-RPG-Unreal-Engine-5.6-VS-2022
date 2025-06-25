#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "InventoryItemStruct.h" // ✅ on inclut ici ta struct

#include "RPGSaveGame.generated.h"

UCLASS()
class MYRPG_API URPGSaveGame : public USaveGame
{
    GENERATED_BODY()

public:
    URPGSaveGame();

    UPROPERTY()
    float SavedHealth;

    UPROPERTY()
    float SavedMana;

    UPROPERTY()
    TArray<FInventoryItem> SavedInventory; // ✅ on utilise bien FInventoryItem
};
