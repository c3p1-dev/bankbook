#ifndef CONFIG_H
#define CONFIG_H

#include <map>
#include <string>
#include <string_view>

namespace bankbook {

/// @brief manages application configuration settings
class config
{
public:
    /// @brief load configuration from a file
    /// @param filename path to the configuration file
    /// @return true if loading succeeded, false otherwise
    bool load(std::string_view filename);
    /// @brief save configuration to a file
    /// @param filename path to the configuration file
    /// @return true if saving succeeded, false otherwise
    bool save(std::string_view filename) const;

    /// @brief returns a configuration value
    /// @param key configuration key
    /// @return configuration value, or an empty string if the key does not exist
    std::string get(std::string_view key) const;
    /// @brief sets a configuration value
    /// @param key configuration key
    /// @param value configuration value
    void set(std::string_view key, std::string_view value);

    /// @brief returns all configuration entries
    /// @return a map containing all configuration keys and values
    std::map <std::string, std::string> get_all() const;

private:
    std::map<std::string, std::string> data_;
};

} // namespace bankbook end

#endif  // CONFIG_H
