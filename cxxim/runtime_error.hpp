
/// \file runtime_error class.
/// Contains definition of the runtime_error class.

#pragma once

#include "strings.hpp"
#include <stdexcept>


namespace im {


/// Standard class for exceptions thrown by cxxim. Implements conversion to/from wide strings.
class runtime_error: public std::runtime_error {
public:
    /// Constructs error with specified message
    runtime_error(std::wstring msg):
        std::runtime_error{wstring_to_string(msg)}, msg_{std::move(msg)} {}

    /// Returns reference to message string
    auto & wwhat() const { return msg_; }

private:
    std::wstring msg_;          ///< Error message
};


}