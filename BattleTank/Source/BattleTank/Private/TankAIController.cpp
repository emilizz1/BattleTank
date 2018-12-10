// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "BattleTank.h"
#include "Engine.h"
#include "Engine/Classes/GameFramework/PlayerController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerPawn)
	{
		//TODO move towards the player
		Cast<ATank>(GetPawn())->AimAt(Cast<ATank>(PlayerPawn)->GetActorLocation());
		Cast<ATank>(GetPawn())->Fire();
	}
}
