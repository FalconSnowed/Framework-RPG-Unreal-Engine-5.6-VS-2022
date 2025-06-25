#include "AbilityComponent.h"
#include "RPGCharacter.h"
#include "StatComponent.h"
#include "Kismet/GameplayStatics.h"

UAbilityComponent::UAbilityComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UAbilityComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UAbilityComponent::AddAbility(const FAbilityData& NewAbility)
{
    Abilities.Add(NewAbility.AbilityID, NewAbility);
}

void UAbilityComponent::UseAbility(FName AbilityID)
{
    if (!Abilities.Contains(AbilityID)) return;

    const FAbilityData& Ability = Abilities[AbilityID];

    if (Cooldowns.Contains(AbilityID) && Cooldowns[AbilityID] > 0)
        return;

    if (!HasEnoughMana(Ability)) return;

    TriggerEffect(Ability);
    ApplyCooldown(AbilityID);

    ARPGCharacter* OwnerChar = Cast<ARPGCharacter>(GetOwner());
    if (OwnerChar && Ability.CastMontage)
    {
        OwnerChar->PlayAnimMontage(Ability.CastMontage);
    }
}

void UAbilityComponent::TriggerEffect(const FAbilityData& Ability)
{
    ARPGCharacter* OwnerChar = Cast<ARPGCharacter>(GetOwner());
    if (!OwnerChar || !Ability.AbilityEffectClass) return;

    FVector SpawnLoc = OwnerChar->GetActorLocation() + OwnerChar->GetActorForwardVector() * 100.f;
    FRotator SpawnRot = OwnerChar->GetActorRotation();

    GetWorld()->SpawnActor<AActor>(Ability.AbilityEffectClass, SpawnLoc, SpawnRot);

    // 🧪 Appliquer coût de mana
    UStatComponent* Stat = OwnerChar->FindComponentByClass<UStatComponent>();
    if (Stat)
    {
        Stat->ApplyManaDelta(-Ability.ManaCost);
    }
}

void UAbilityComponent::ApplyCooldown(FName AbilityID)
{
    Cooldowns.Add(AbilityID, Abilities[AbilityID].Cooldown);
}

bool UAbilityComponent::HasEnoughMana(const FAbilityData& Ability) const
{
    ARPGCharacter* OwnerChar = Cast<ARPGCharacter>(GetOwner());
    if (!OwnerChar) return false;

    UStatComponent* Stat = OwnerChar->FindComponentByClass<UStatComponent>();
    return Stat && Stat->GetCurrentMana() >= Ability.ManaCost;
}
