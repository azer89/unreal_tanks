// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UCapsuleComponent;
class AProjectileBase;

UCLASS()
class UNREAL_TANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnBase();

	virtual void HandleDestruction();

//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//public:	
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//	// Called to bind functionality to input
//	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// COMPONENTS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USceneComponent* ProjectileSpawnPoint;

	// VARIABLES
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile Type", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AProjectileBase> ProjectileClass;


protected:

	void RotateTurret(FVector LookAtTarget);

	void Fire();

	
};