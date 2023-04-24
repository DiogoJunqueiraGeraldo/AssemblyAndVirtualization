#pragma once

#include "Instructions.h"
#include "Operands.h"

namespace Instructions {
	namespace Encodings {
		class RegisterEncoding: public Instructions::Instruction {
			Operands::Register m_Rs;
			Operands::Register m_Rt;
			Operands::Register m_Rd;
			Operands::Shamt m_Shamt;
			Operands::Funct m_Funct;
		};

		class JumpEncoding : public Instruction
		{
			Operands::TargetAddress m_TargetAddress;
		};

		class ImmediateEncoding : public Instruction
		{
			Operands::Register m_Rs;
			Operands::Register m_Rt;
			Operands::Immediate m_Immediate;
		};
	}
}