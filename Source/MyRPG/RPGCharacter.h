#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InventoryComponent.h"
#include "StatComponent.h"
#include "CombatComponent.h" // Tous les includes avant...

#include "RPGCharacter.generated.h" // ⚠️ DOIT être le dernier include

UCLASS()
class MYRPG_API ARPGCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ARPGCharacter();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UInventoryComponent* InventoryComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStatComponent* StatComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UCombatComponent* CombatComponent;

    UFUNCTION(BlueprintCallable)
    void SavePlayerData();

    UFUNCTION(BlueprintCallable)
    void LoadPlayerData();
};
