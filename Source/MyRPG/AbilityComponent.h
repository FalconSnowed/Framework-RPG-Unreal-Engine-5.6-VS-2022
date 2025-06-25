#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilityStruct.h"
#include "AbilityComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYRPG_API UAbilityComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UAbilityComponent();

    UFUNCTION(BlueprintCallable)
    void UseAbility(FName AbilityID);

    UFUNCTION(BlueprintCallable)
    void AddAbility(const FAbilityData& NewAbility);

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY()
    TMap<FName, FAbilityData> Abilities;

    UPROPERTY()
    TMap<FName, float> Cooldowns;

    void TriggerEffect(const FAbilityData& Ability);
    bool HasEnoughMana(const FAbilityData& Ability) const;
    void ApplyCooldown(FName AbilityID);
};
