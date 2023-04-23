#pragma once
#include "Instruction.h"
#include "TargetAddress.h"

class JumpEncoding : public Instruction
{
	TargetAddress m_TargetAddress;
};

