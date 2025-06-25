#include "CombatComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "StatComponent.h"

UCombatComponent::UCombatComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UCombatComponent::PerformAttack()
{
    PlayAttackAnimation();

    ACharacter* OwnerChar = Cast<ACharacter>(GetOwner());
    if (!OwnerChar) return;

    FVector Start = OwnerChar->GetActorLocation();
    FVector End = Start + OwnerChar->GetActorForwardVector() * 150.f;

    TArray<FHitResult> Hits;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(OwnerChar);

    GetWorld()->SweepMultiByChannel(Hits, Start, End, FQuat::Identity, ECC_Pawn, FCollisionShape::MakeSphere(100.f), Params);

    for (const FHitResult& Hit : Hits)
    {
        AActor* HitActor = Hit.GetActor();
        if (HitActor && HitActor != OwnerChar)
        {
            const bool bCrit = IsCriticalHit();
            const float FinalDamage = bCrit ? BaseDamage * CritMultiplier : BaseDamage;
            ApplyDamage(HitActor, FinalDamage, bCrit);
        }
    }
}

void UCombatComponent::ApplyDamage(AActor* Target, float DamageAmount, bool bIsCrit)
{
    if (!Target) return;

    UStatComponent* Stat = Target->FindComponentByClass<UStatComponent>();
    if (Stat)
    {
        Stat->TakeDamage(DamageAmount);
    }

    if (HitEffect)
    {
        UGameplayStatics::SpawnEmitterAtLocation(
            GetWorld(),
            HitEffect,
            Target->GetActorLocation(),
            FRotator::ZeroRotator
        );
    }
}

void UCombatComponent::PlayAttackAnimation()
{
    ACharacter* OwnerChar = Cast<ACharacter>(GetOwner());
    if (OwnerChar && AttackMontage)
    {
        OwnerChar->PlayAnimMontage(AttackMontage);
    }
}

bool UCombatComponent::IsCriticalHit() const
{
    return FMath::FRand() <= CritChance;
}
