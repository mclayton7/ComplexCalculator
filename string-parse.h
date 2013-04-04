// String Parse Class Declaration
// ECE3090 - String Parsing Functions

#include <string>
#include <vector>

// Define a type that is a variable length array of strings
typedef std::vector<std::string> StringVec_t;
// Define a type that is a variable length array of characters
typedef std::vector<char>        CharVec_t;

int StringParse(const std::string&,  // String to parse
                const std::string&,  // Delimiter set
                StringVec_t&,        // Returned substrings
                CharVec_t&);         // Returned delimiters

// ToDouble converts a string containing digits and a (possible)
// decimal point to the corresponding floating point value.
double ToDouble(const std::string&); // Convert a string value to double

// RemoveParens removes leading and trailing parentheses from a string.
// For example, if the input string is "(1,2)", the  returned string is "1,2".
std::string RemoveParens(const std::string&);

// GetString reads a character string from the keyboard.
std::string GetStringFromKeyboard();
