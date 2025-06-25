#include "ItemEffectComponent.h"
#include "RPGCharacter.h"
#include "StatComponent.h"

UItemEffectComponent::UItemEffectComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UItemEffectComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UItemEffectComponent::AddEffect(const FItemEffect& NewEffect)
{
    FItemEffect Effect = NewEffect;
    Effect.TimeRemaining = Effect.Duration;
    ActiveEffects.Add(Effect);
}

void UItemEffectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    for (int32 i = ActiveEffects.Num() - 1; i >= 0; --i)
    {
        FItemEffect& Effect = ActiveEffects[i];
        ProcessEffect(Effect, DeltaTime);
        Effect.TimeRemaining -= DeltaTime;

        if (Effect.TimeRemaining <= 0)
        {
            ActiveEffects.RemoveAt(i);
        }
    }
}

void UItemEffectComponent::ProcessEffect(FItemEffect& Effect, float DeltaTime)
{
    ARPGCharacter* OwnerChar = Cast<ARPGCharacter>(GetOwner());
    if (!OwnerChar) return;

    UStatComponent* StatComp = OwnerChar->FindComponentByClass<UStatComponent>();
    if (!StatComp) return;

    switch (Effect.EffectType)
    {
    case EItemEffectType::RegenHealth:
        StatComp->ApplyHealthDelta(Effect.Value * DeltaTime);
        break;

    case EItemEffectType::BoostDefense:
        StatComp->ApplyTemporaryDefenseBoost(Effect.Value);
        break;

    case EItemEffectType::Poisoned:
        StatComp->ApplyHealthDelta(-Effect.Value * DeltaTime);
        break;

    default:
        break;
    }
}
