#pragma once
#include "Instruction.h";
#include "Register.h"
#include "Shamt.h"
#include "Funct.h"

class RegisterEncoding: public Instruction
{
	Register m_Rs;
	Register m_Rt;
	Register m_Rd;
	Shamt m_Shamt;
	Funct m_Funct;
};

