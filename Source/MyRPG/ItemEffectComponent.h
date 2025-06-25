#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemEffectComponent.generated.h"

UENUM(BlueprintType)
enum class EItemEffectType : uint8
{
    None        UMETA(DisplayName = "None"),
    RegenHealth UMETA(DisplayName = "Health Regen"),
    BoostDefense UMETA(DisplayName = "Boost Defense"),
    Poisoned    UMETA(DisplayName = "Poisoned"),
    // Ajoute d'autres types si besoin
};

USTRUCT(BlueprintType)
struct FItemEffect
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EItemEffectType EffectType = EItemEffectType::None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Value = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Duration = 0.0f;

    float TimeRemaining = 0.0f;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYRPG_API UItemEffectComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UItemEffectComponent();

    UFUNCTION(BlueprintCallable)
    void AddEffect(const FItemEffect& NewEffect);

protected:
    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    UPROPERTY()
    TArray<FItemEffect> ActiveEffects;

    void ProcessEffect(FItemEffect& Effect, float DeltaTime);
};
