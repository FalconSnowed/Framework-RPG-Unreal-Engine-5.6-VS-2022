#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryItemStruct.h"
#include "InventoryComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYRPG_API UInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UInventoryComponent();

    // Tableau contenant les objets de l’inventaire
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
    TArray<FInventoryItem> Items;

    // Ajout d’un objet
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void AddItem(const FString& ItemName, int32 Quantity);
};
