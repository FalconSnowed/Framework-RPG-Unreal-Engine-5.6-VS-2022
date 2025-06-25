// ✅ EquipmentComponent.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EquippedItemStruct.h"
#include "EquipmentComponent.generated.h" // toujours en dernier

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYRPG_API UEquipmentComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FEquippedItem> EquippedItems;

    UFUNCTION(BlueprintCallable)
    void EquipItem(const FString& Slot, const FString& ItemName);

    UFUNCTION(BlueprintCallable)
    void UnequipItem(const FString& Slot);

    UFUNCTION(BlueprintCallable)
    FString GetEquippedItem(const FString& Slot) const;
};
