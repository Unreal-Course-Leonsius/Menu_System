// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

	/// Don't work in this Section

protected:

	virtual bool Initialize() override;

	/// We can also use this virtual function instead of SetGameMode()
	//virtual void OnLevelRemovedFromWorld(ULevel* Inlevel, UWorld* InWorld) override;

	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void OpenMainMenu();


public:  // Works only public section

	void SetGameInstanceInterface(IMenuInterface* GameInstaceInterface);

	void SetUIMode();
	void SetGameMode();

public:

	/// Blueprint Buttons
	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* CancleButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinToServer;


	/// Blueprint Widgets
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;


private:

	/// Instead of it we use Interface
	//class UPuzzlePlatformsGameInstance* PPGameInstance = nullptr;

	IMenuInterface* GameInstanceInterface = nullptr;
	
};
