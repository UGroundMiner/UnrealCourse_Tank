// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "GameFramework/Actor.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank))
	{
		// Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// Aim at player tank
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire every frame
		ControlledTank->Fire(); // TODO Don't fire every frame
	}
}