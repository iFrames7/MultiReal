// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformBase.generated.h"

UCLASS()
class MULTIREAL_API APlatformBase : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> StaticMeshComp;
public:
	// Sets default values for this actor's properties
	APlatformBase();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateMovement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
