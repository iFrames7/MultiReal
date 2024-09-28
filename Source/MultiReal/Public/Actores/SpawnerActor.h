// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnerActor.generated.h"

class APlatformBase;
UCLASS()
class MULTIREAL_API ASpawnerActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawnerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OnSpawnActor();

	UPROPERTY(EditAnywhere)
	TSubclassOf<APlatformBase> ActorToSpawn;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle SpawnTimerHandle;

	// UPROPERTY(EditAnywhere, Category = "Spawning")
	// TSubclassOf<AActor> BPBoxTestClass;
};
