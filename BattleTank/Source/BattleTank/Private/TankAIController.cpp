// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "Engine/Classes/GameFramework/PlayerController.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{

}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerPawn)
	{
		return Cast<ATank>(PlayerPawn);
	}
	else
	{
		return nullptr;
	}
}
