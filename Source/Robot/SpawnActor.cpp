// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnActor.h"


// Sets default values
ASpawnActor::ASpawnActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpawnActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnActor::SpawnEnemy_Implementation()
{
}

void ASpawnActor::AddSpawn(int enemy, float toSpawn, float sizeSpawn)
{
	enemysToSpawn[enemy] += toSpawn;
	spawnSize = sizeSpawn;
}

int ASpawnActor::GetEnemy(int enemyID)
{
	if (enemysToSpawn[enemyID] > spawnSize)
	{
		enemysToSpawn[enemyID] -= spawnSize;
		return spawnSize;
	}
	else
	{
		int leftToSpawn = enemysToSpawn[enemyID];
		enemysToSpawn[enemyID] = 0;
		return leftToSpawn;
	}
}
