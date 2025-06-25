#pragma once

#include "CoreMinimal.h"
#include "EquippedItemStruct.generated.h"

USTRUCT(BlueprintType)
struct FEquippedItem
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString Slot;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString ItemName;

    // ✅ Constructeur utile pour les Add(FEquippedItem(...))
    FEquippedItem() {}

    FEquippedItem(const FString& InSlot, const FString& InItemName)
        : Slot(InSlot), ItemName(InItemName) {
    }
};
