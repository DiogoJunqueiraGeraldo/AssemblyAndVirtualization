#pragma once
#include "Instruction.h"
#include "Register.h"
#include "Immediate.h"

class ImmediateEncoding : Instruction
{
	Register Rs;
	Register Rt;
	Immediate Immediate;
};

