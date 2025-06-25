#include "InventoryComponent.h"
#include "EquipmentComponent.h"

UInventoryComponent::UInventoryComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::BeginPlay()
{
    Super::BeginPlay();

    // Si le composant existe sur le même acteur, on l’attrape
    EquipmentComponent = GetOwner()->FindComponentByClass<UEquipmentComponent>();
    if (!EquipmentComponent)
    {
        UE_LOG(LogTemp, Warning, TEXT("❌ EquipmentComponent not found on %s"), *GetOwner()->GetName());
    }
}

void UInventoryComponent::AddItem(const FString& ItemName, int32 Quantity)
{
    for (FInventoryItem& Item : Items)
    {
        if (Item.ItemName == ItemName)
        {
            Item.Quantity += Quantity;
            return;
        }
    }

    Items.Add(FInventoryItem(ItemName, Quantity));
}

void UInventoryComponent::EquipItem(const FString& Slot, const FString& ItemName)
{
    if (EquipmentComponent)
    {
        EquipmentComponent->EquipItem(Slot, ItemName);
    }
}

void UInventoryComponent::UnequipItem(const FString& Slot)
{
    if (EquipmentComponent)
    {
        EquipmentComponent->UnequipItem(Slot);
    }
}

FString UInventoryComponent::GetEquippedItem(const FString& Slot) const
{
    if (EquipmentComponent)
    {
        return EquipmentComponent->GetEquippedItem(Slot);
    }

    return TEXT("None");
}
