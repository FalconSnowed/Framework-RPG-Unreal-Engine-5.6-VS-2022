#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
    PrimaryComponentTick.bCanEverTick = false; // Pas besoin de tick pour un inventaire simple
}

void UInventoryComponent::AddItem(const FString& ItemName, int32 Quantity)
{
    for (FInventoryItem& Item : Items)
    {
        if (Item.Name == ItemName)
        {
            Item.Quantity += Quantity;
            return;
        }
    }

    // Si l’objet n’existe pas encore dans l’inventaire
    Items.Add(FInventoryItem(ItemName, Quantity));
}
