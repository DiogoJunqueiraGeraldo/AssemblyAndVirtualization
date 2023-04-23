#pragma once
#include "Instruction.h"
#include "Register.h"
#include "Immediate.h"

class ImmediateEncoding : public Instruction
{
	Register m_Rs;
	Register m_Rt;
	Immediate m_Immediate;
};

