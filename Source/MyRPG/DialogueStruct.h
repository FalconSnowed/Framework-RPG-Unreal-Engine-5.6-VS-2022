#pragma once

#include "CoreMinimal.h"
#include "DialogueStruct.generated.h"

USTRUCT(BlueprintType)
struct FDialogueOption
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PlayerChoiceText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NPCResponseText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 NextNodeIndex = -1; // -1 = Fin de dialogue
};

USTRUCT(BlueprintType)
struct FDialogueNode
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NPCLine;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FDialogueOption> Options;
};

USTRUCT(BlueprintType)
struct FDialogueData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName DialogueID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FDialogueNode> Nodes;
};
