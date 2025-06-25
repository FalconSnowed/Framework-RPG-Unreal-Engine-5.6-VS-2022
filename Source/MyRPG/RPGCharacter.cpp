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

    if (!SaveGameInstance || !StatComponent || !InventoryComponent)
    {
        UE_LOG(LogTemp, Warning, TEXT("❌ Cannot save: Components or SaveGame invalid."));
        return;
    }

    // ✅ Utilisation des getters
    SaveGameInstance->SavedHealth = StatComponent->GetHealth();
    SaveGameInstance->SavedMana = StatComponent->GetMana();

    SaveGameInstance->SavedInventory.Empty();
    for (const FInventoryItem& Item : InventoryComponent->Items)
    {
        SaveGameInstance->SavedInventory.Add(FInventoryItem(Item.ItemName, Item.Quantity));
    }

    UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("PlayerSaveSlot"), 0);
}

void ARPGCharacter::LoadPlayerData()
{
    if (!InventoryComponent || !StatComponent)
    {
        UE_LOG(LogTemp, Warning, TEXT("❌ Cannot load: Components invalid."));
        return;
    }

    if (UGameplayStatics::DoesSaveGameExist(TEXT("PlayerSaveSlot"), 0))
    {
        URPGSaveGame* LoadedGame = Cast<URPGSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("PlayerSaveSlot"), 0));
        if (LoadedGame)
        {
            // ✅ Utilisation des setters
            StatComponent->SetHealth(LoadedGame->SavedHealth);
            StatComponent->SetMana(LoadedGame->SavedMana);

            InventoryComponent->Items.Empty();
            for (const FInventoryItem& Saved : LoadedGame->SavedInventory)
            {
                InventoryComponent->Items.Add(FInventoryItem(Saved.ItemName, Saved.Quantity));
            }
        }
    }
}
