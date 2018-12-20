// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;
	void Tick(float deltaTime) override;
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);
private:
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
	void AimTowardsCrosshair();
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333;
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;
};
