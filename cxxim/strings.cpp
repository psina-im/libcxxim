
/// \file strings.cpp
/// Contains implementation of utility functions for working with strings

#include "strings.hpp"
#include <cassert>
#include <locale>
#include <vector>


namespace im {


std::string wstring_to_string(std::wstring_view s) {
    // creating multibyte -> wide converter using current locale
    std::locale loc("");
    using conv_t = std::codecvt<wchar_t, char, std::mbstate_t>;
    const conv_t & conv = std::use_facet<conv_t>(loc);

    // allocating output buffer.
    // output will take at most same number of bytes as input
    std::vector<char> res(s.size() * 4 + 4);

    // converting chars to wchars
    std::mbstate_t state = mbstate_t();
    const wchar_t * input = s.data();
    const wchar_t * input_end = input + s.size();
    char * output = &res[0];
    const wchar_t * next_input = input;
    char * next_output = output;

    // converting wchars to chars
    conv.out(state,
             input,
             input_end,
             next_input,
             output,
             output + res.size(),
             next_output);

    // resising resulting array to output size
    assert(next_output - output <= res.size() && "invalid output size");
    return std::string{output, next_output};
}


std::wstring string_to_wstring(std::string_view s) {
    // creating multibyte -> wide converter using current locale
    std::locale loc("");
    using conv_t = std::codecvt<wchar_t, char, std::mbstate_t>;
    const conv_t & conv = std::use_facet<conv_t>(loc);

    // allocating output buffer.
    // output will take at most same number of bytes as input
    std::vector<wchar_t> res(s.end() - s.begin());

    // converting chars to wchars
    std::mbstate_t state = mbstate_t();
    wchar_t * output = &res[0];
    const char * next_input = s.begin();
    wchar_t * next_output = output;
    conv.in(state,
            s.begin(),
            s.end(),
            next_input,
            output,
            output + res.size(),
            next_output);

    // creating and returning wstring
    return std::wstring(output, next_output);
}


}