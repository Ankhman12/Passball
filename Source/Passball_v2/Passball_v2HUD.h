// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Passball_v2HUD.generated.h"

UCLASS()
class APassball_v2HUD : public AHUD
{
	GENERATED_BODY()

public:
	APassball_v2HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

