#include "StatComponent.h"

UStatComponent::UStatComponent()
{
    PrimaryComponentTick.bCanEverTick = false;

    CurrentHealth = MaxHealth;
    CurrentMana = MaxMana;
}

void UStatComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UStatComponent::ApplyManaDelta(float Delta)
{
    CurrentMana = FMath::Clamp(CurrentMana + Delta, 0.f, MaxMana);
}

float UStatComponent::GetCurrentMana() const
{
    return CurrentMana;
}

void UStatComponent::ApplyHealthDelta(float Delta)
{
    CurrentHealth = FMath::Clamp(CurrentHealth + Delta, 0.f, MaxHealth);
}

void UStatComponent::ApplyTemporaryDefenseBoost(float Value)
{
    Defense += Value;
    // Optionnel : timer pour reset
}

void UStatComponent::TakeDamage(float Amount)
{
    float DamageTaken = FMath::Max(0.f, Amount - Defense);
    ApplyHealthDelta(-DamageTaken);
}

void UStatComponent::Heal(float Amount)
{
    ApplyHealthDelta(Amount);
}

bool UStatComponent::IsDead() const
{
    return CurrentHealth <= 0.f;
}
