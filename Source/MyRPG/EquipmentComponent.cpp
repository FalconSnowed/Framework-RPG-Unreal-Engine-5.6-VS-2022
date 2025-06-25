#include "EquipmentComponent.h"

void UEquipmentComponent::EquipItem(const FString& Slot, const FString& ItemName)
{
    for (FEquippedItem& Item : EquippedItems)
    {
        if (Item.Slot == Slot)
        {
            Item.ItemName = ItemName;
            return;
        }
    }

    // Si aucun slot existant, on ajoute un nouvel item équipé
    EquippedItems.Add(FEquippedItem(Slot, ItemName));
}

void UEquipmentComponent::UnequipItem(const FString& Slot)
{
    for (int32 i = 0; i < EquippedItems.Num(); ++i)
    {
        if (EquippedItems[i].Slot == Slot)
        {
            EquippedItems.RemoveAt(i);
            return;
        }
    }
}

FString UEquipmentComponent::GetEquippedItem(const FString& Slot) const
{
    for (const FEquippedItem& Item : EquippedItems)
    {
        if (Item.Slot == Slot)
        {
            return Item.ItemName;
        }
    }

    return FString();
}
