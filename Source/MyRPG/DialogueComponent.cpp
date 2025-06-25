#include "DialogueComponent.h"

UDialogueComponent::UDialogueComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    CurrentNodeIndex = 0;
}

void UDialogueComponent::StartDialogue(const FDialogueData& InDialogue)
{
    CurrentDialogue = InDialogue;
    CurrentNodeIndex = 0;

    if (CurrentDialogue.Nodes.IsValidIndex(CurrentNodeIndex))
    {
        const FDialogueNode& Node = CurrentDialogue.Nodes[CurrentNodeIndex];
        TArray<FString> Choices;
        for (const FDialogueOption& Opt : Node.Options)
        {
            Choices.Add(Opt.PlayerChoiceText);
        }

        OnDialogueUpdated.Broadcast(Node.NPCLine, Choices);
    }
}

void UDialogueComponent::ChooseOption(int32 OptionIndex)
{
    if (!CurrentDialogue.Nodes.IsValidIndex(CurrentNodeIndex)) return;

    const FDialogueNode& Node = CurrentDialogue.Nodes[CurrentNodeIndex];
    if (!Node.Options.IsValidIndex(OptionIndex)) return;

    const FDialogueOption& Chosen = Node.Options[OptionIndex];
    CurrentNodeIndex = Chosen.NextNodeIndex;

    if (CurrentNodeIndex == -1)
    {
        OnDialogueUpdated.Broadcast(TEXT(""), {});
        return;
    }

    if (CurrentDialogue.Nodes.IsValidIndex(CurrentNodeIndex))
    {
        const FDialogueNode& NewNode = CurrentDialogue.Nodes[CurrentNodeIndex];
        TArray<FString> Choices;
        for (const FDialogueOption& Opt : NewNode.Options)
        {
            Choices.Add(Opt.PlayerChoiceText);
        }

        OnDialogueUpdated.Broadcast(NewNode.NPCLine, Choices);
    }
}
