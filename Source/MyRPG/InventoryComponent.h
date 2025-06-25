#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryItemStruct.h"
#include "InventoryComponent.generated.h"

// 👇 Forward declaration pour éviter les inclusions croisées
class UEquipmentComponent;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYRPG_API UInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UInventoryComponent();

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
    TArray<FInventoryItem> Items;

    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void AddItem(const FString& ItemName, int32 Quantity);

    UFUNCTION(BlueprintCallable, Category = "Equipment")
    void EquipItem(const FString& Slot, const FString& ItemName);

    UFUNCTION(BlueprintCallable, Category = "Equipment")
    void UnequipItem(const FString& Slot);

    UFUNCTION(BlueprintCallable, Category = "Equipment")
    FString GetEquippedItem(const FString& Slot) const;

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY()
    UEquipmentComponent* EquipmentComponent;
};
