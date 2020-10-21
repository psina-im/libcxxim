
/// \file acccount.cpp
/// Contains implementation of the account class.

#include "account.hpp"
#include "json.hpp"


namespace im {


void to_json(json_t & json, const account & acc) {
    json["user-id"] = acc.user_id();
    json["password"] = acc.password();
}


void from_json(const json_t & json, account & acc) {
    acc.set_user_id(json.at("user-id").get<std::wstring>());
    acc.set_password(json.at("password").get<std::wstring>());
}


}