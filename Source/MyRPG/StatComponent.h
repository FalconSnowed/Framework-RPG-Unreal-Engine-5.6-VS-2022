#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYRPG_API UStatComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UStatComponent(); // ✅ N’oublie pas le constructeur

    // === Public Functions ===
    UFUNCTION(BlueprintCallable)
    void ApplyManaDelta(float Delta);

    UFUNCTION(BlueprintCallable)
    float GetCurrentMana() const;

    UFUNCTION(BlueprintCallable)
    void ApplyHealthDelta(float Delta);

    UFUNCTION(BlueprintCallable)
    void ApplyTemporaryDefenseBoost(float Value);

    UFUNCTION(BlueprintCallable)
    void TakeDamage(float Amount);

    UFUNCTION(BlueprintCallable)
    void Heal(float Amount);

    UFUNCTION(BlueprintCallable)
    bool IsDead() const;

    // === Getters utiles pour sauvegarde ===
    float GetHealth() const { return CurrentHealth; }
    float GetMana() const { return CurrentMana; }

    void SetHealth(float Value) { CurrentHealth = FMath::Clamp(Value, 0.f, MaxHealth); }
    void SetMana(float Value) { CurrentMana = FMath::Clamp(Value, 0.f, MaxMana); }

protected:
    virtual void BeginPlay() override;

    // === Stats ===
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float MaxHealth = 100.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float MaxMana = 50.f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
    float CurrentHealth;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
    float CurrentMana;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Strength = 10.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Defense = 5.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float BaseDefense = 10.f;
};
