#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <cstdint>
#include <optional>
#include <chrono>

namespace bankbook::data {

/// @brief represents a bank account
class account
{
public:
    /// @brief returns the account id
    /// @return the account id
    std::uint64_t id() const;
    /// @brief sets the account id
    /// @param account_id the new account id
    void id(std::uint64_t account_id);

    /// @brief returns the initial balance
    /// @return the initial balance
    std::int64_t initial_balance() const;
    /// @brief sets the initial balance
    /// @param cents the new initial balance in cents
    void initial_balance(std::int64_t cents);

    /// @brief returns the account code
    /// @return the account code
    const std::string& code() const;
    /// @brief sets the account code
    /// @param account_code the new account code
    void code(std::string account_code);

    /// @brief returns the account name
    /// @return the account name
    const std::string& name() const;
    /// @brief sets the account name
    /// @param account_name the new account name
    void name(std::string account_name);

    /// @brief returns the account bankname
    /// @return the account bankname
    const std::optional<std::string>& bank() const;
    /// @brief sets the account bankname
    /// @param bank_name the new account bankname
    void bank(std::optional<std::string> bank_name);

    /// @brief returns the account description
    /// @return the account description
    const std::optional<std::string>& description() const;
    /// @brief sets the account description
    /// @param account_description the new account description
    void description(std::optional<std::string> account_description);

    /// @brief returns the account iban
    /// @return the account iban
    const std::optional<std::string>& iban() const;
    /// @brief sets the account iban
    /// @param account_iban the new account iban
    void iban(std::optional<std::string> account_iban);

    /// @brief returns the account swift code
    /// @return the account swift code
    const std::optional<std::string>& swift() const;
    /// @brief sets the account swift code
    /// @param account_swift the new account swift code
    void swift(std::optional<std::string> account_swift);

    /// @brief returns the account website url
    /// @return the account website url
    const std::optional<std::string>& url() const;
    void url(std::optional<std::string> account_url);

    /// @brief returns the account locked_at date
    /// @return the account locked_at date
    std::optional<std::chrono::system_clock::time_point> locked_at() const;
    /// @brief sets the account locked_at date
    /// @param lock_time the new account locked_at date
    void locked_at(std::optional<std::chrono::system_clock::time_point> lock_time);

private:
    std::uint64_t id_{0};
    std::int64_t initial_balance_{0};

    std::string code_;
    std::string name_;

    std::optional<std::string> bank_;
    std::optional<std::string> description_;
    std::optional<std::string> iban_;
    std::optional<std::string> swift_;
    std::optional<std::string> url_;
    std::optional<std::chrono::system_clock::time_point> locked_at_;
};

} // namespace bankbook::data end

#endif // ACCOUNT_H

/*
    SQL query to create the table
    
    CREATE TABLE IF NOT EXISTS accounts (
        id              INTEGER PRIMARY KEY,
        code            TEXT NOT NULL UNIQUE,
        name            TEXT NOT NULL,
        initial_balance INTEGER NOT NULL DEFAULT 0,  -- cents
        bank            TEXT,
        description     TEXT,
        iban            TEXT,
        swift           TEXT,
        url             TEXT,
        locked_at       INTEGER                      -- secs since epoch, NULL if unlocked
    );
*/
