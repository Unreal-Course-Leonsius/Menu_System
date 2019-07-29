// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"

#include "Edit_Tools/HandTools.h"
#include "Components/Button.h"
#include "PuzzlePlatformsGameInstance.h"

void UMainMenu::SetGameInstanceInterface(IMenuInterface * GameInstanceInterface)
{
	this->GameInstanceInterface = GameInstanceInterface;
}

void UMainMenu::SetUIMode()
{
	this->AddToViewport();

	auto World = GetWorld();

	APlayerController* PlayerController = World->GetFirstPlayerController();

	FInputModeUIOnly Mode;
	Mode.SetWidgetToFocus(this->GetCachedWidget());
	PlayerController->SetInputMode(Mode);
	PlayerController->bShowMouseCursor = true;

	/// Sam's Code
	/*	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(Menu->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock); // without it code works fine

	PlayerController->SetInputMode(InputModeData);

	PlayerController->bShowMouseCursor = true;*/
}

void UMainMenu::SetGameMode()
{
	auto World = GetWorld();

	APlayerController* PlayerController = World->GetFirstPlayerController();
	this->RemoveFromViewport();

	/// This code is not work here in UUserWidget
	//this = nullptr;
	//UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
	//FSlateApplication::Get().SetFocusToGameViewport();
	///

	FInputModeGameOnly Mode;
	PlayerController->SetInputMode(Mode);
	PlayerController->bShowMouseCursor = false;
}

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(Host != nullptr)) return false;
	Host->OnClicked.AddDynamic(this, &UMainMenu::HostServer);
	
	/// Instead of it we use Interface
	//PPGameInstance = Cast<UPuzzlePlatformsGameInstance>(GetWorld()->GetGameInstance());

	return true;

}


/// We can also use this virtual function instead of SetGameMode()
/// and the code take into here from SetGameMode()
/// But I think in such way code became less readable
/*void UMainMenu::OnLevelRemovedFromWorld(ULevel * Inlevel, UWorld * InWorld)
{
	Super::OnLevelRemovedFromWorld(Inlevel, InWorld);

	LOG_S(FString("Virtual Function OnLevelRemoveFromWorld"));

	auto World = GetWorld();

	APlayerController* PlayerController = World->GetFirstPlayerController();
	this->RemoveFromViewport();

	/// This code is not work here in UUserWidget
	//this = nullptr;
	//UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
	//FSlateApplication::Get().SetFocusToGameViewport();
	///

	FInputModeGameOnly Mode;
	PlayerController->SetInputMode(Mode);
	PlayerController->bShowMouseCursor = false;
}*/

void UMainMenu::HostServer()
{
	LOG_S(FString("Click Event Conneted"));

	/// Instead of it we use Interface
	//PPGameInstance->Host();

	if (GameInstanceInterface != nullptr)
	{
		GameInstanceInterface->Host();
	}
}

