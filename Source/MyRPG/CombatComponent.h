#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYRPG_API UCombatComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UCombatComponent();

    UFUNCTION(BlueprintCallable)
    void PerformAttack();

    UFUNCTION(BlueprintCallable)
    void ApplyDamage(AActor* Target, float DamageAmount, bool bIsCrit = false);

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float BaseDamage = 10.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float CritChance = 0.2f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float CritMultiplier = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    UAnimMontage* AttackMontage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    UParticleSystem* HitEffect;

    void PlayAttackAnimation();
    bool IsCriticalHit() const;
};
