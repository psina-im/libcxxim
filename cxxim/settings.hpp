
/// \file settings.hpp
/// Contains definition of the settings class.

#pragma once

#include <nlohmann/json.hpp>
#include <filesystem>


namespace im {

/// Type of JSON used in settings
using json_t = nlohmann::json;


/// Class for loading and saving settings in JSON format
class settings {
public:
    /// Constructs settings with specified path to settings file. Loads json
    /// and saves it in class instance
    settings(const std::filesystem::path & p);

private:
    std::filesystem::path json_path_;   ///< Path to JSON config
    json_t json_;                       ///< Current settings JSON
};


}