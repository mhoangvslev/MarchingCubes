// Copyright 2017 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "Input/Reply.h"
#include "IDetailCustomization.h"

class AVoxelWorld;

DECLARE_LOG_CATEGORY_EXTERN(VoxelWorldEditorLog, Log, All);
class FVoxelWorldDetails : public IDetailCustomization
{
public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<IDetailCustomization> MakeInstance();

private:
	/** IDetailCustomization interface */
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailLayout) override;

	FReply OnWorldUpdate();

	FReply OnUpdateCameraPosition();
private:
	TWeakObjectPtr<AVoxelWorld> World;
};
