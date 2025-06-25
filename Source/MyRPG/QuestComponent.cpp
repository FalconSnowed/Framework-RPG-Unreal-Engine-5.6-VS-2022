#include "QuestComponent.h"

UQuestComponent::UQuestComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UQuestComponent::AddQuest(const FQuestData& NewQuest)
{
    ActiveQuests.Add(NewQuest);
}

void UQuestComponent::UpdateObjectiveProgress(FName QuestID, int32 ObjectiveIndex, int32 Amount)
{
    for (FQuestData& Quest : ActiveQuests)
    {
        if (Quest.QuestID == QuestID && Quest.Status == EQuestStatus::InProgress)
        {
            if (Quest.Objectives.IsValidIndex(ObjectiveIndex))
            {
                FQuestObjective& Obj = Quest.Objectives[ObjectiveIndex];
                Obj.CurrentCount += Amount;
                if (Obj.CurrentCount >= Obj.RequiredCount)
                {
                    Obj.bIsComplete = true;
                }

                // Check if all are complete
                bool bAllComplete = true;
                for (const FQuestObjective& O : Quest.Objectives)
                {
                    if (!O.bIsComplete)
                    {
                        bAllComplete = false;
                        break;
                    }
                }

                if (bAllComplete)
                {
                    Quest.Status = EQuestStatus::Completed;
                    // ?? Ajouter ici une fonction d’alerte, récompense, etc.
                }
            }
            break;
        }
    }
}

void UQuestComponent::CompleteQuest(FName QuestID)
{
    for (FQuestData& Quest : ActiveQuests)
    {
        if (Quest.QuestID == QuestID)
        {
            Quest.Status = EQuestStatus::Completed;
            break;
        }
    }
}
