#pragma once

#include "CoreMinimal.h"
#include "QuestStruct.generated.h"

UENUM(BlueprintType)
enum class EQuestStatus : uint8
{
    NotStarted,
    InProgress,
    Completed,
    Failed
};

USTRUCT(BlueprintType)
struct FQuestObjective
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RequiredCount = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CurrentCount = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsComplete = false;
};

USTRUCT(BlueprintType)
struct FQuestData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName QuestID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Title;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EQuestStatus Status = EQuestStatus::NotStarted;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FQuestObjective> Objectives;
};
