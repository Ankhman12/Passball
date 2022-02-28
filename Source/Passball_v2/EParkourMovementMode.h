#pragma once

#include "UObject/ObjectMacros.h"

/** Custom movement modes for Characters. */
UENUM(BlueprintType)
enum EParkourMovementMode
{
	MOVE_WallRunLeft   UMETA(DisplayName = "WallRunLeft"),
	MOVE_WallRunRight  UMETA(DisplayName = "WallRunRight"),
	MOVE_Sprint		   UMETA(DisplayName = "Sprint"),
	MOVE_NoParkour	   UMETA(DisplayName = "NoParkour")
};