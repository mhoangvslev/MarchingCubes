// Copyright 2017 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelWorldGenerator.h"
#include "FlatWorldGenerator.generated.h"


USTRUCT(Blueprintable)
struct VOXEL_API FFlatWorldStruct
{
	GENERATED_BODY()

public:
	// Color of the layer
	UPROPERTY(EditAnywhere)
		FLinearColor Color;

	// Start (Z position) of the layer
	UPROPERTY(EditAnywhere)
		int Start;

	// Height of the layer
	UPROPERTY(EditAnywhere)
		int Height;
};

/**
 *
 */
UCLASS(Blueprintable)
class VOXEL_API UFlatWorldGenerator : public UObject, public IVoxelWorldGenerator
{
	GENERATED_BODY()

public:
	UFlatWorldGenerator();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Voxel")
		float GetDefaultValue(FIntVector Position);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Voxel")
		FColor GetDefaultColor(FIntVector Position);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Voxel")
		void SetVoxelWorld(AVoxelWorld* VoxelWorld);


	virtual float GetDefaultValue_Implementation(FIntVector Position) override;
	virtual FColor GetDefaultColor_Implementation(FIntVector Position) override;
	virtual void SetVoxelWorld_Implementation(AVoxelWorld* VoxelWorld) override;

	// Height of the difference between full and empty
	UPROPERTY(EditAnywhere)
		int Height;

	// Color to set if no layer
	UPROPERTY(EditAnywhere)
		FLinearColor DefaultColor;

	// Layers
	UPROPERTY(EditAnywhere)
		TArray<FFlatWorldStruct> Layers;

	// Value to set
	UPROPERTY(EditAnywhere)
		float ValueMultiplier;
};