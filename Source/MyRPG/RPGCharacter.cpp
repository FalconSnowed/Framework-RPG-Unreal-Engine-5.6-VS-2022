#include "RPGCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "RPGSaveGame.h"

ARPGCharacter::ARPGCharacter()
{
    InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
    StatComponent = CreateDefaultSubobject<UStatComponent>(TEXT("StatComponent"));
}

void ARPGCharacter::SavePlayerData()
{
    URPGSaveGame* SaveGameInstance = Cast<URPGSaveGame>(UGameplayStatics::CreateSaveGameObject(URPGSaveGame::StaticClass()));

    SaveGameInstance->SavedHealth = StatComponent->CurrentHealth;
    SaveGameInstance->SavedMana = StatComponent->CurrentMana;

    SaveGameInstance->SavedInventory.Empty();
    for (const FInventoryItem& Item : InventoryComponent->Items)
    {
        SaveGameInstance->SavedInventory.Add(FInventoryItem(Item.Name, Item.Quantity));
    }

    UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("PlayerSaveSlot"), 0);
}

void ARPGCharacter::LoadPlayerData()
{
    if (UGameplayStatics::DoesSaveGameExist(TEXT("PlayerSaveSlot"), 0))
    {
        URPGSaveGame* LoadedGame = Cast<URPGSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("PlayerSaveSlot"), 0));
        if (LoadedGame)
        {
            StatComponent->CurrentHealth = LoadedGame->SavedHealth;
            StatComponent->CurrentMana = LoadedGame->SavedMana;

            InventoryComponent->Items.Empty();
            for (const FInventoryItem& Saved : LoadedGame->SavedInventory)
            {
                InventoryComponent->Items.Add(FInventoryItem(Saved.Name, Saved.Quantity));
            }
        }
    }
}
