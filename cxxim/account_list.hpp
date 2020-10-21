
/// \file account_list.hpp
/// Contains definition of the account_list class.

#pragma once

#include "account.hpp"
#include "json_fwd.hpp"
#include <ranges>
#include <vector>


namespace im {


/// Account list. Stores list of accounts.
class account_list {
public:
    /// Constructs empty account list
    account_list() {
        add(L"user1@server1", L"");
        add(L"esil@server.im", L"");
    }

    /// Returns range of all accounts
    auto all() const {
        auto fn = [](auto && acc_ptr) { return static_cast<const account*>(acc_ptr.get()); };
        return accounts_ | std::views::transform(fn);
    }

    /// Adds account
    void add(std::wstring uid, std::wstring pass);

    /// Saves account list to JSON
    void to_json(json_t & json) const;

    /// Loads account list from JSON
    void from_json(const json_t & json);

private:
    std::vector<std::unique_ptr<account>> accounts_;        ///< Vector of accounts
};


/// Saves account list to json
inline void to_json(json_t & json, const account_list & acc_list) {
    acc_list.to_json(json);
}

/// Loads account list from json
inline void from_json(const json_t & json, account_list & acc_list) {
    acc_list.from_json(json);
}


}
