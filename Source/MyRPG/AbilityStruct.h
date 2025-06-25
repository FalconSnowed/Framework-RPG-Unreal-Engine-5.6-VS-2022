#pragma once

#include "CoreMinimal.h"
#include "AbilityStruct.generated.h"

UENUM(BlueprintType)
enum class EAbilityType : uint8
{
    Instant,
    Targeted,
    Area,
    Passive
};

USTRUCT(BlueprintType)
struct FAbilityData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName AbilityID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EAbilityType Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ManaCost = 10.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Cooldown = 5.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<AActor> AbilityEffectClass; // Ex: projectile, explosion, etc.

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UAnimMontage* CastMontage;
};
