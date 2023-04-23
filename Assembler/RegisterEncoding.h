#pragma once
#include "Instruction.h";
#include "Register.h"
#include "Shamt.h"
#include "Funct.h"

class RegisterEncoding: Instruction
{
	Register Rs;
	Register Rt;
	Register Rd;
	Shamt Shamt;
	Funct Funct;
};

