// RPGCharacter.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InventoryComponent.h"
#include "StatComponent.h"
#include "RPGCharacter.generated.h"

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

    UFUNCTION(BlueprintCallable)
    void SavePlayerData();

    UFUNCTION(BlueprintCallable)
    void LoadPlayerData();
};
