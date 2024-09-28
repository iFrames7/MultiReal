// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiReal/Public/Actores/SpawnerActor.h"
#include "MultiReal/Public/Actores/PlatformBase.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

// Sets default values
ASpawnerActor::ASpawnerActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpawnerActor::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawnerActor::OnSpawnActor, 1.0f, true);
}

void ASpawnerActor::OnSpawnActor()
{
	if(HasAuthority())
	{
		APlatformBase* Platform = GetWorld()->SpawnActor<APlatformBase>(ActorToSpawn, GetActorLocation(), GetActorRotation());
		Platform->OnUpdateMovement();
	}    
}

// Called every frame
void ASpawnerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


