#ifndef CATEGORY_H
#define CATEGORY_H

#include <cstdint>
#include <optional>
#include <string>

namespace bankbook::data {

/// @brief represents a transaction category
class category
{
public:
    /// @brief returns the category id
    /// @return the category id
    std::uint64_t id() const;
    /// @brief sets the category id
    /// @param category_id the new category id
    void id(std::uint64_t category_id);

    /// @brief returns the parent category id
    /// @return the parent category id
    std::optional<std::uint64_t> parent_id() const;
    /// @brief sets the parent category id
    /// @param parent the new parent category id
    void parent_id(std::optional<std::uint64_t> parent);

    /// @brief returns the category code
    /// @return the category code
    const std::string& code() const;
    /// @brief sets the category code
    /// @param category_code the new category code
    void code(std::string category_code);

    /// @brief returns the category name
    /// @return the category name
    const std::string& name() const;
    /// @brief sets the category name
    /// @param category_name the new category name
    void name(std::string category_name);

    /// @brief returns the category description
    /// @return the category description
    const std::optional<std::string>& description() const;
    /// @brief sets the category description
    /// @param category_description the new category description
    void description(std::optional<std::string> category_description);

private:
    std::uint64_t id_{0};
    std::optional<std::uint64_t> parent_id_;
    std::string code_;
    std::string name_;
    std::optional<std::string> description_;
};

} // namespace bankbook::data end

#endif  // CATEGORY_H

/*
    SQL query to create the table

    CREATE TABLE IF NOT EXISTS categories (
        id          INTEGER PRIMARY KEY,
        parent_id   INTEGER REFERENCES categories(id) ON DELETE RESTRICT,
        code        TEXT NOT NULL UNIQUE CHECK (length(code) > 0),
        name        TEXT NOT NULL CHECK (length(name) > 0),
        description TEXT,
        CHECK (parent_id IS NULL OR parent_id <> id)
    );

    CREATE INDEX IF NOT EXISTS categories_parent ON categories(parent_id);
*/
