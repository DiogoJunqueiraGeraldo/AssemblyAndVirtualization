#pragma once

#include <string>

namespace Tokens {
	class Token
	{
	public:
		virtual std::string GetTokenType() { return "BaseToken"; }
	};
}
