
/// \file settings.cpp
/// Contains implementation of the settings class.

#include "settings.hpp"
#include <fstream>

namespace fs = std::filesystem;


namespace im {


settings::settings(const std::filesystem::path & p):
json_path_{p} {
    try {
        // reading JSON from config file
        if (fs::exists(p)) {
            std::ifstream str{p, std::ios_base::in};
            json_ = json_t::parse(str);
        }
    }
    catch(std::exception & err) {
        // can't read config. Ignore error
    }
}


}