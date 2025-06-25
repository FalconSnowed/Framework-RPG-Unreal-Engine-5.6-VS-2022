#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DialogueStruct.h"
#include "DialogueComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDialogueUpdated, FString, NPCLine, TArray<FString>, Options);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYRPG_API UDialogueComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UDialogueComponent();

    UPROPERTY(BlueprintAssignable)
    FOnDialogueUpdated OnDialogueUpdated;

    UFUNCTION(BlueprintCallable)
    void StartDialogue(const FDialogueData& InDialogue);

    UFUNCTION(BlueprintCallable)
    void ChooseOption(int32 OptionIndex);

protected:
    UPROPERTY()
    FDialogueData CurrentDialogue;

    int32 CurrentNodeIndex;
};
