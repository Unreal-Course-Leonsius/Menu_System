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

	UFUNCTION()
	void HostServer();


public:  // Works only public section

	void SetGameInstanceInterface(IMenuInterface* GameInstaceInterface);

	void SetUIMode();
	void SetGameMode();

public:

	UPROPERTY(meta = (BindWidget))
	class UButton* Host;

	UPROPERTY(meta = (BindWidget))
	class UButton* Join;

private:

	/// Instead of it we use Interface
	//class UPuzzlePlatformsGameInstance* PPGameInstance = nullptr;

	IMenuInterface* GameInstanceInterface = nullptr;
	
};
