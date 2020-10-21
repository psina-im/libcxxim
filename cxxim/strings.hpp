
/// \file strings.hpp
/// Cotnains declaration of utility functions for working with strings.

#pragma once

#include <string>


namespace im {


/// Converts wstring to string using current locale
std::string wstring_to_string(std::wstring_view s);

/// converts string to wstring using current locale
std::wstring string_to_wstring(std::string_view s);


}
