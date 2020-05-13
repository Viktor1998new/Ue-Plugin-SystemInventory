// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemActor.h"

// Sets default values
AItemActor::AItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AItemActor::SetData(const FString &NewData)
{
	ReceiveInitData(NewData);
	
}

FString AItemActor::GetData()
{
	FString newData;
	
	ReceiveGetData(newData);

	return newData;

}
