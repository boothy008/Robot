// Fill out your copyright notice in the Description page of Project Settings.

#include "Bullet.h"


// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));

	boxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	RootComponent = boxCollision;
	
	bulletMesh->SetupAttachment(RootComponent);
	bulletMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	speed = 100.0f;
	damage = 10.0f;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + (GetActorForwardVector() * speed));

	lifeTime -= DeltaTime;

	if (lifeTime <= 0.0f && !IsPendingKill())
	{
		Destroy();
	}
}