// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PlatformTrigger.h"
#include "PuzzlePlatformsGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectInitializer);

	virtual void Init();

	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UFUNCTION(BlueprintCallable)
	void Host();

	UFUNCTION(BlueprintCallable) // UFUNCTION(Exec) to get command in Editor command with key ~
	void Join(const FString& Address);

private:

	void SetFocusAndCursorMenuMode();
	void SetFocuseAndCursorGameMode();

private:

	TSubclassOf<class UUserWidget> MainMenu; // Such way MainMenu = PlatformTriggerBPClass.Class Because both of they is TSubclassOf<>(); 
	//class UUserWidget* MainMenu = nullptr;  // Such way MainMenu = PlatformTriggerBPClass.Class.GetDefaultObject(); Because they are different type // But we need TSubclassOf<>() because CreateWidget() function requier it

	UUserWidget* Menu = nullptr;  //it's for to get value which CreateWidget() return

	APlayerController* PlayerController = nullptr;

};
