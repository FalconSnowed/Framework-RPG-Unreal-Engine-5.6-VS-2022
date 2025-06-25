#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestStruct.h"
#include "QuestComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYRPG_API UQuestComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UQuestComponent();

    UFUNCTION(BlueprintCallable)
    void AddQuest(const FQuestData& NewQuest);

    UFUNCTION(BlueprintCallable)
    void UpdateObjectiveProgress(FName QuestID, int32 ObjectiveIndex, int32 Amount = 1);

    UFUNCTION(BlueprintCallable)
    void CompleteQuest(FName QuestID);

    UFUNCTION(BlueprintCallable)
    const TArray<FQuestData>& GetActiveQuests() const { return ActiveQuests; }

protected:
    UPROPERTY()
    TArray<FQuestData> ActiveQuests;
};
