#pragma once

#include "UObject/ObjectMacros.h"

/** Custom movement modes for Characters. */
UENUM(BlueprintType)
enum EParkourMovementMode
{
	MOVE_WallRunLeft   UMETA(DisplayName = "WallRunLeft"),
	MOVE_WallRunRight  UMETA(DisplayName = "WallRunRight"),
	MOVE_VertWallRun   UMETA(DisplayName = "VerticalWallRun"),
	MOVE_LedgeGrab     UMETA(DisplayName = "LedgeGrab"),
	MOVE_Mantle        UMETA(DisplayName = "Mantle"),
	MOVE_Crouch        UMETA(DisplayName = "Crouch"),
	MOVE_Slide         UMETA(DisplayName = "Slide"),
	MOVE_Sprint		   UMETA(DisplayName = "Sprint"),
	MOVE_NoParkour	   UMETA(DisplayName = "NoParkour")
};