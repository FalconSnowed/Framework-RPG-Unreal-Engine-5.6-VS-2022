#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYRPG_API UStatComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UStatComponent();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float MaxHealth = 100.f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
    float CurrentHealth;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float MaxMana = 50.f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
    float CurrentMana;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Strength = 10.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Defense = 5.f;

    UFUNCTION(BlueprintCallable)
    void TakeDamage(float Amount);

    UFUNCTION(BlueprintCallable)
    void Heal(float Amount);

    UFUNCTION(BlueprintCallable)
    bool IsDead() const;
};
