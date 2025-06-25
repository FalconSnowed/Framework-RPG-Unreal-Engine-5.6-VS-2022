#pragma once

#include "CoreMinimal.h"
#include "InventoryItemStruct.generated.h" // ✅ DOIT être le dernier include

USTRUCT(BlueprintType)
struct FInventoryItem
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    FString Name;

    UPROPERTY(BlueprintReadWrite)
    int32 Quantity;

    FInventoryItem() : Name(TEXT("")), Quantity(0) {}
    FInventoryItem(const FString& InName, int32 InQuantity) : Name(InName), Quantity(InQuantity) {}
};
