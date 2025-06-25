// MedievalFPSCharacter.cpp
#include "MedievalFPSCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/World.h"
#include "RPGSaveGame.h"
#include "Kismet/GameplayStatics.h"

AMedievalFPSCharacter::AMedievalFPSCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    Health = 100.f;
    Mana = 50.f;

    FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
    FirstPersonCamera->SetRelativeLocation(FVector(0.f, 0.f, 64.f));
    FirstPersonCamera->bUsePawnControlRotation = true;
}

void AMedievalFPSCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AMedievalFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    check(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &AMedievalFPSCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AMedievalFPSCharacter::MoveRight);
    PlayerInputComponent->BindAxis("Turn", this, &AMedievalFPSCharacter::Turn);
    PlayerInputComponent->BindAxis("LookUp", this, &AMedievalFPSCharacter::LookUp);
    PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AMedievalFPSCharacter::Attack);
    PlayerInputComponent->BindAction("SaveGame", IE_Pressed, this, &AMedievalFPSCharacter::SavePlayerData);
    PlayerInputComponent->BindAction("LoadGame", IE_Pressed, this, &AMedievalFPSCharacter::LoadPlayerData);
}

void AMedievalFPSCharacter::MoveForward(float Value)
{
    if (Value != 0.0f)
        AddMovementInput(GetActorForwardVector(), Value);
}

void AMedievalFPSCharacter::MoveRight(float Value)
{
    if (Value != 0.0f)
        AddMovementInput(GetActorRightVector(), Value);
}

void AMedievalFPSCharacter::Turn(float Value)
{
    AddControllerYawInput(Value);
}

void AMedievalFPSCharacter::LookUp(float Value)
{
    AddControllerPitchInput(Value);
}

void AMedievalFPSCharacter::Attack()
{
    UE_LOG(LogTemp, Warning, TEXT("Medieval Attack Triggered!"));

    if (EquippedWeapon)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;

        FVector SpawnLocation = FirstPersonCamera->GetComponentLocation() + FirstPersonCamera->GetForwardVector() * 100.f;
        FRotator SpawnRotation = FirstPersonCamera->GetComponentRotation();

        GetWorld()->SpawnActor<AActor>(EquippedWeapon, SpawnLocation, SpawnRotation, SpawnParams);
    }
}

void AMedievalFPSCharacter::SavePlayerData()
{
    URPGSaveGame* SaveGameInstance = Cast<URPGSaveGame>(UGameplayStatics::CreateSaveGameObject(URPGSaveGame::StaticClass()));
    if (!SaveGameInstance) return;

    SaveGameInstance->SavedHealth = Health;
    SaveGameInstance->SavedMana = Mana;
    SaveGameInstance->SavedInventory = Inventory;

    UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("PlayerSaveSlot"), 0);
    UE_LOG(LogTemp, Log, TEXT("Player data successfully saved."));
}

void AMedievalFPSCharacter::LoadPlayerData()
{
    if (UGameplayStatics::DoesSaveGameExist(TEXT("PlayerSaveSlot"), 0))
    {
        URPGSaveGame* LoadGameInstance = Cast<URPGSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("PlayerSaveSlot"), 0));
        if (!LoadGameInstance) return;

        Health = LoadGameInstance->SavedHealth;
        Mana = LoadGameInstance->SavedMana;
        Inventory = LoadGameInstance->SavedInventory;

        UE_LOG(LogTemp, Log, TEXT("Player data successfully loaded."));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No save file found."));
    }
}
