// MedievalFPSCharacter.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InventoryItemStruct.h"
#include "MedievalFPSCharacter.generated.h"

UCLASS()
class MYRPG_API AMedievalFPSCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AMedievalFPSCharacter();

protected:
    virtual void BeginPlay() override;

public:
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void MoveForward(float Value);
    void MoveRight(float Value);
    void LookUp(float Value);
    void Turn(float Value);
    void Attack();

    UFUNCTION(BlueprintCallable)
    void SavePlayerData();

    UFUNCTION(BlueprintCallable)
    void LoadPlayerData();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Health;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Mana;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TArray<FInventoryItem> Inventory;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    class UCameraComponent* FirstPersonCamera;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    TSubclassOf<class AActor> EquippedWeapon;
};