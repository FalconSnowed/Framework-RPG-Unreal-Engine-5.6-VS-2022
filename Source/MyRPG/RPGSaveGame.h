#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "InventoryItemStruct.h" // ✅ struct FInventoryItem

#include "RPGSaveGame.generated.h" // ⚠️ TOUJOURS EN DERNIER

UCLASS()
class MYRPG_API URPGSaveGame : public USaveGame
{
    GENERATED_BODY()

public:
    URPGSaveGame();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SavedHealth;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SavedMana;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FInventoryItem> SavedInventory;
};
