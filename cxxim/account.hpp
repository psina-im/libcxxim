
/// \file account.hpp
/// Contains definition of the account class.

#pragma once

#include "json_fwd.hpp"
#include <string>


namespace im {


/// Single IM account
class account {
public:
    /// Constructs account with specified user ID and password
    account(std::wstring uid = {}, std::wstring pass = {}):
        user_id_{std::move(uid)}, password_{std::move(pass)} {}

    /// Returns user ID for account
    auto & user_id() const { return user_id_; }

    /// Sets user ID
    void set_user_id(std::wstring_view uid) { user_id_ = uid; }

    /// Returns password for account
    auto & password() const { return password_; }

    /// Sets password
    void set_password(std::wstring_view p) { password_ = p; }

private:
    std::wstring user_id_;          ///< User ID
    std::wstring password_;         ///< Password
};


/// Writes account to JSON
void to_json(json_t & json, const account & acc);

/// Reads account from JSON
void from_json(const json_t & json, account & acc);


}
