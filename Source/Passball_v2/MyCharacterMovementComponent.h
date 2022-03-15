// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EWallRunSide.h"
#include "EParkourMovementMode.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyCharacterMovementComponent.generated.h"


/**
 *
 */
UCLASS(BlueprintType)
class UMyCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

		friend class FSavedMove_My;

#pragma region Defaults
private:
	// The ground speed when running
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Character Movement|Grounded", Meta = (AllowPrivateAccess = "true"))
		float RunSpeed = 300.0f;
	// The ground speed when sprinting
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Character Movement|Grounded", Meta = (AllowPrivateAccess = "true"))
		float SprintSpeed = 800.0f;
	// The acceleration when running
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Character Movement|Grounded", Meta = (AllowPrivateAccess = "true"))
		float RunAcceleration = 2000.0f;
	// The acceleration when sprinting
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Character Movement|Grounded", Meta = (AllowPrivateAccess = "true"))
		float SprintAcceleration = 2000.0f;
	// The amount of vertical room between the two line traces when checking if the character is still on the wall
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "My Character Movement|Wall Running", Meta = (AllowPrivateAccess = "true"))
		float LineTraceVerticalTolerance = 50.0f;
	// The player's velocity while wall running
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "My Character Movement|Wall Running", Meta = (AllowPrivateAccess = "true"))
		float WallRunSpeed = 850.0f;
	//Default gravity to reset after wall running
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "My Character Movement|Wall Running", Meta = (AllowPrivateAccess = "true"))
		float DefaultGravity = 1.0f;
	//Gravity value to use while wall running
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "My Character Movement|Wall Running", Meta = (AllowPrivateAccess = "true"))
		float WallRunTargetGravity = 0.2f;
	//Boolean to determine if wall run uses gravity
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "My Character Movement|Wall Running", Meta = (AllowPrivateAccess = "true"))
		 bool UseWallRunGravity = false;
	//Height to jump off of wall with
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "My Character Movement|Wall Running", Meta = (AllowPrivateAccess = "true"))
		float WallRunJumpHeight = 400.0f;
	//Outward force to jump off of wall with
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "My Character Movement|Wall Running", Meta = (AllowPrivateAccess = "true"))
		float WallRunJumpOutForce = 300.0f;

	// The player's velocity while vertical wall running
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "My Character Movement|Climbing", Meta = (AllowPrivateAccess = "true"))
		float VerticalWallRunSpeed = 300.0f;

	//Maximum height for ledge to be mantle-able
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "My Character Movement|Mantling", Meta = (AllowPrivateAccess = "true"))
		float MantleHeight = 40.0f;

	//Camera Shakes
	UPROPERTY(EditAnywhere, Category = "My Character Movement|Camera Shakes") //, Meta = (AllowPrivateAccess = "true"))
		TSubclassOf<UCameraShakeBase> LandShake;
	UPROPERTY(EditAnywhere, Category = "My Character Movement|Camera Shakes") //, Meta = (AllowPrivateAccess = "true"))
		TSubclassOf<UCameraShakeBase> LedgeGrabShake;
	UPROPERTY(EditAnywhere, Category = "My Character Movement|Camera Shakes") //, Meta = (AllowPrivateAccess = "true"))
		TSubclassOf<UCameraShakeBase> QuickMantleShake;
	UPROPERTY(EditAnywhere, Category = "My Character Movement|Camera Shakes") //, Meta = (AllowPrivateAccess = "true"))
		TSubclassOf<UCameraShakeBase> MantleShake;
#pragma endregion

#pragma region Parkour General Functions
	void ParkourUpdate();
	void CameraTick(float deltaTime);
	void CameraTilt(float xRoll, float deltaTime);
	void ResetMovement();
	void OnParkourModeChanged(EParkourMovementMode PreviousParkourMode, EParkourMovementMode NewParkourMode);
	bool SetParkourMovementMode(EParkourMovementMode ModeToSet);
	float ForwardInput() const;
	void PlayCameraShake(TSubclassOf<UCameraShakeBase> shake);
#pragma endregion

#pragma region Sprinting Functions
public:
	// Sets sprinting to either enabled or disabled
	UFUNCTION(BlueprintCallable, Category = "My Character Movement")
		void SetSprinting(bool sprinting);
#pragma endregion

#pragma region Wall Running Functions
	// Requests that the character begins wall running. Will return false if the required keys are not being pressed
	//UFUNCTION(BlueprintCallable, Category = "My Character Movement")
		//void BeginWallRun(float wallRunDirection);

	// Ends the character's wall run
	UFUNCTION(BlueprintCallable, Category = "My Character Movement")
		void EndWallRun(float resetTime);

	// Returns true if the required wall run keys are currently down
	//bool AreRequiredWallRunKeysDown() const;
	// Returns true if the player is next to a wall that can be wall ran
	//bool IsNextToWall(float vertical_tolerance = 0.0f);
	// Finds the wall run direction and side based on the specified surface normal
	//void FindWallRunDirectionAndSide(const FVector& surface_normal, FVector& direction, EWallRunSide& side) const;
	// Helper function that returns true if the specified surface normal can be wall ran on
	//bool CanSurfaceBeWallRan(const FVector& surface_normal) const;

	// Returns true if the movement mode is custom and matches the provided custom movement mode
	bool IsCustomMovementMode(uint8 custom_movement_mode) const;
	// Returns true if the player is wall running
	bool IsWallRunning() const;
	// Returns vector used to push player forward along the wall
	FVector GetWallRunForwardVector(float wallRunDirection) const;
	// Returns the distance vector used by line trace to check if player is on a wall (left side)
	FVector GetLeftWallEndVector() const;
	// Returns the distance vector used by line trace to check if player is on a wall (right side)
	FVector GetRightWallEndVector() const;
	// Returns bool of whether or not the wall is wall runnable given the wall normal
	bool ValidWallRunVector(FVector wallNormal) const;
	//Returns bool of whether or not player can wall run
	bool CanWallRun() const;
	//Handles jumping while wall running 
	UFUNCTION(BlueprintCallable, Category = "My Character Movement")
		void WallRunJump();
	//Main wall run body functions
	void WallRunUpdate();
	//Function for calculting movement along wall run
	bool WallRunMovement(FVector start, FVector end, float direction);
	//Wall Run Gate functions
	void OpenWallRunGate();
	void CloseWallRunGate();

	//Vertical Wall Run functions
	void VerticalWallRunUpdate();
	void VerticalWallRunMovement();
	void EndVerticalWallRun(float resetTime);
	bool CanVerticalWallRun();
	void OpenVerticalWallRunGate();
	void CloseVerticalWallRunGate();

	//Mantle functions
	void MantleCheck();
	void MantleUpdate();
	FVector GetMantleHighVector();
	FVector GetMantleLowVector();
	void OpenMantleCheckGate();
	void CloseMantleCheckGate();
	void OpenMantleGate();
	void CloseMantleGate();

private:
	// Called when the owning actor hits something (to begin the wall run)
	//UFUNCTION()
	//	void OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
#pragma endregion

#pragma region Overrides
protected:
	virtual void BeginPlay() override;
	//virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void UpdateFromCompressedFlags(uint8 Flags) override;
	virtual void OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode) override;
	//virtual void PhysCustom(float deltaTime, int32 Iterations) override;
	//void PhysWallRunning(float deltaTime, int32 Iterations);
	virtual float GetMaxSpeed() const override;
	virtual float GetMaxAcceleration() const override;
	virtual void ProcessLanded(const FHitResult& Hit, float remainingTime, int32 Iterations) override;
	virtual FNetworkPredictionData_Client* GetPredictionData_Client() const override;
#pragma endregion

#pragma region Compressed Flags
private:
	uint8 WantsToSprint : 1;
	uint8 WallRunKeysDown : 1;
#pragma endregion

#pragma region Private Variables
	// True if the sprint key is down
	bool SprintKeyDown = false;
	// Normal vector of the wall the player is running on
	FVector WallNormal;
	// Normal vector of the wall player is climbing up
	FVector VerticalWallNormal;
	// Trace distance of most recent mantle check
	float MantleTraceDistance;

	//General update timer handler
	FTimerHandle ParkourHandle;

	//Wall Run Gate variables
	bool IsWallRunGateOpen = true;
	FTimerHandle WallRunGateHandle;

	//Vertical Wall Run Gate variables
	bool IsVerticalWallRunGateOpen;
	FTimerHandle VerticalWallRunGateHandle;

	//Mantle Check Gate variables
	bool IsMantleCheckGateOpen;
	FTimerHandle MantleCheckGateHandle;

	//Mantle Gate variables
	bool IsMantleGateOpen;
	FTimerHandle MantleGateHandle;

	//Movement mode variables
	EMovementMode PrevMovementMode;
	EMovementMode CurrMovementMode;
	EParkourMovementMode PrevParkourMode = EParkourMovementMode::MOVE_NoParkour;
	EParkourMovementMode CurrParkourMode = EParkourMovementMode::MOVE_NoParkour;

#pragma endregion
};

class FSavedMove_My : public FSavedMove_Character
{
public:

	typedef FSavedMove_Character Super;

	// Resets all saved variables.
	virtual void Clear() override;
	// Store input commands in the compressed flags.
	virtual uint8 GetCompressedFlags() const override;
	// This is used to check whether or not two moves can be combined into one.
	// Basically you just check to make sure that the saved variables are the same.
	virtual bool CanCombineWith(const FSavedMovePtr& NewMovePtr, ACharacter* Character, float MaxDelta) const override;
	// Sets up the move before sending it to the server. 
	virtual void SetMoveFor(ACharacter* Character, float InDeltaTime, FVector const& NewAccel, class FNetworkPredictionData_Client_Character& ClientData) override;
	// Sets variables on character movement component before making a predictive correction.
	virtual void PrepMoveFor(class ACharacter* Character) override;

private:
	uint8 SavedWantsToSprint : 1;
	uint8 SavedWallRunKeysDown : 1;
};

class FNetworkPredictionData_Client_My : public FNetworkPredictionData_Client_Character
{
public:
	typedef FNetworkPredictionData_Client_Character Super;

	// Constructor
	FNetworkPredictionData_Client_My(const UCharacterMovementComponent& ClientMovement);

	//brief Allocates a new copy of our custom saved move
	virtual FSavedMovePtr AllocateNewMove() override;
};
