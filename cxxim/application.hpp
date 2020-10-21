
/// \file application.hpp
/// Contains definition of the application class.

#pragma once

#include "account_list.hpp"


namespace im {


/// Main client application class
class application {
public:
    /// Constructs application class
    application();

    /// Returns reference to account list
    auto & accounts() { return accounts_; }

private:
    account_list accounts_;         ///< List of accounts
};


}
