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

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerTank)
	{
		MoveToActor(PlayerTank, AcceptanceRadius);
		Cast<ATank>(GetPawn())->AimAt(Cast<ATank>(PlayerTank)->GetActorLocation());
		Cast<ATank>(GetPawn())->Fire();
	}
}
