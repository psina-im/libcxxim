
/// \file json.hpp
/// Contains definition of json type used for storing data.

#pragma once

#include "json_fwd.hpp"
#include <nlohmann/json.hpp>
#include <codecvt>
#include <locale>
#include <string>


namespace std {


inline void to_json(nlohmann::json & j, const std::wstring & s) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    j = conv.to_bytes(s);
}


/// Converts UTF8 string to wstring
inline void from_json(const nlohmann::json & j, std::wstring & s) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    s = conv.from_bytes(j.get<std::string>());
}


}
