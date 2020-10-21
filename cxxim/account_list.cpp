
/// \file account_list.cpp
/// Contains implementation of the account_list class.

#include "account_list.hpp"
#include "runtime_error.hpp"
#include "json.hpp"
#include <sstream>


namespace im {


void account_list::add(std::wstring uid, std::wstring pass) {
    accounts_.push_back(std::make_unique<account>(std::move(uid), std::move(pass)));
}


void account_list::to_json(json_t & json) const {
    for (auto && acc : all()) {
        json.push_back(*acc);
    }
}


void account_list::from_json(const json_t & json) {
    for (auto && elt : json) {
        auto acc = std::make_unique<account>();
        elt.get_to(*acc);
        accounts_.push_back(std::move(acc));
    }
}


}
