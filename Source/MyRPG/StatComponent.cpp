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
    CurrentHealth = MaxHealth;
    CurrentMana = MaxMana;
}

void UStatComponent::TakeDamage(float Amount)
{
    CurrentHealth = FMath::Clamp(CurrentHealth - Amount, 0.f, MaxHealth);
}

void UStatComponent::Heal(float Amount)
{
    CurrentHealth = FMath::Clamp(CurrentHealth + Amount, 0.f, MaxHealth);
}

bool UStatComponent::IsDead() const
{
    return CurrentHealth <= 0.f;
}
