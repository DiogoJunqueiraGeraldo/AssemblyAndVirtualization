#pragma once
#include "Instruction.h"
#include "TargetAddress.h"

class JumpEncoding : Instruction
{
	TargetAddress TargetAddress;
};

