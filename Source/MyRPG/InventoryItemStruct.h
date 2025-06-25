#pragma once

#include "CoreMinimal.h"
#include "InventoryItemStruct.generated.h"

USTRUCT(BlueprintType)
struct MYRPG_API FInventoryItem
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FString ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    int32 Quantity;

    // Constructeur par défaut
    FInventoryItem()
        : ItemName(TEXT("")), Quantity(0)
    {
    }

    // Constructeur personnalisé
    FInventoryItem(const FString& InName, int32 InQuantity)
        : ItemName(InName), Quantity(InQuantity)
    {
    }
};
