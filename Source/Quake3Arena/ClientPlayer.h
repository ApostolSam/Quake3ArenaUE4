// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ClientPlayer.generated.h"

UCLASS()
class QUAKE3ARENA_API AClientPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AClientPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

	/** default inventory list */
	UPROPERTY(EditDefaultsOnly, Category = Inventory)
	TArray<TSubclassOf<class AWeaponBase> > DefaultInventoryClasses;

	/** weapons in inventory */
	UPROPERTY(Transient)
	TArray<class AWeaponBase*> Inventory;

	/** currently equipped weapon */
	UPROPERTY(Transient)
	class AWeaponBase* CurrentWeapon;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	class AWeaponBase* FindWeapon(TSubclassOf<class AWeaponBase> WeaponClass);
	void EquipWeapon(class AWeaponBase* Weapon);

	void MoveForward(float Val);
	void MoveRight(float Val);
	void OnStartJump();
	void OnStopJump();

};
