// https://www.codewars.com/kata/decode-the-morse-code/train/cpp/
#include "pch.h"

#include <sstream>
#include <string>


std::map<std::string, const char *> MORSE_CODE = 
{
	 { " "      , " " }, { "\n"     , "\n" }, { ".-"     , "A" }, { "-..."   , "B"  }, { "-.-."   , "C"  },
	 { "-.."    , "D" }, { "."      , "E"  }, { "..-."   , "F" }, { "--."    , "G"  }, { "...."   , "H"  },
	 { ".."     , "I" }, { ".---"   , "J"  }, { "-.-"    , "K" }, { ".-.."   , "L"  }, { "--"     , "M"  },
	 { "-."     , "N" }, { "---"    , "O"  }, { ".--."   , "P" }, { "--.-"   , "Q"  }, { ".-."    , "R"  },
	 { "..."    , "S" }, { "-"      , "T"  }, { "..-"    , "U" }, { "...-"   , "V"  }, { ".--"    , "W"  },
	 { "-..-"   , "X" }, { "-.--"   , "Y"  }, { "--.."   , "Z" }, { ".----"  , "1"  }, { "..---"  , "2"  },
	 { "...--"  , "3" }, { "....-"  , "4"  }, { "....."  , "5" }, { "-...."  , "6"  }, { "--..."  , "7"  },
	 { "---.."  , "8" }, { "----."  , "9"  }, { "-----"  , "0" }, { ".-.-.-" , "."  }, { "--..--" , ","  },
	 { "..--.." , "?" }, { "-...-"  , "-"  }, { "-..-."  , "/" }, { ".--.-." , "@"  }, { ".-.-."  , "+"  },
	 { "-..."   , "=" }, { ".----"  , "\'" }, { "-.--"   , "(" }, { "-.--."  , ")"  }, { ".-..-"  , "\"" },
	 { "...-.-" , "\x04"}
};

std::string decodeMorse(std::string morseCode) {
	std::replace(morseCode.begin(), morseCode.end(), ' ', '\n');
	std::stringstream is(morseCode);
	std::string code, decoded;
	bool previous_is_empty = false;

	while (std::getline(is, code)) {
		decoded += !code.empty() ? MORSE_CODE[code] : (!previous_is_empty && !decoded.empty() ? " " : "");
		previous_is_empty = code.empty();
	}

	if (previous_is_empty)
		decoded.erase(decoded.size() - 1);

	return decoded;
}

Describe(Decode_the_Code_Morse_Teste)
{
	It(All_Tests)
	{
		Assert::That(decodeMorse(".... . -.--   .--- ..- -.. ."), Equals("HEY JUDE"));
	}
};

