#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <cstdint>
#include <chrono>
#include <optional>

namespace bankbook::data {

/// @brief represents a financial transaction
class transaction
{
public:
    /// @brief returns the transaction id
    /// @return the transaction id
    std::uint64_t id() const;
    /// @brief sets the transaction id
    /// @param transaction_id the new transaction id
    void id(std::uint64_t transaction_id);

    /// @brief returns the target account id
    /// @return the target account id
    std::uint64_t account_id() const;
    /// @brief sets the target account id
    /// @param acc_id the new target account id
    void account_id(std::uint64_t acc_id);

    /// @brief returns the transaction category id
    /// @return the transaction category id
    std::optional<std::uint64_t> category_id() const;
    /// @brief sets the transaction category id
    /// @param cat_id the new transaction category id
    void category_id(std::optional<std::uint64_t> cat_id);

    /// @brief returns the transaction label
    /// @return the transaction label
    const std::string& label() const;
    /// @brief sets the transaction label
    /// @param transaction_label the new transaction label
    void label(std::string transaction_label);

    /// @brief returns the transaction note
    /// @return the transaction note
    const std::optional<std::string>& note() const;
    /// @brief sets the transaction note
    /// @param transaction_note the new transaction note
    void note(std::optional<std::string> transaction_note);

    /// @brief returns the payment method
    /// @return the payment method
    const std::optional<std::string>& payment_method() const;
    /// @brief sets the payment method
    /// @param method the new payment method
    void payment_method(std::optional<std::string> method);

    /// @brief returns the check number
    /// @return the check number
    const std::optional<std::string>& check_number() const;
    /// @brief sets the check number
    /// @param ck_number the new check number
    void check_number(std::optional<std::string> ck_number);

    /// @brief returns the transaction creation time
    /// @return the transaction creation time
    std::chrono::system_clock::time_point created_at() const;
    /// @brief sets the transaction creation time
    /// @param creation_time the new transaction creation time
    void created_at(std::chrono::system_clock::time_point creation_time);

    /// @brief returns the transaction accounting date
    /// @return the transaction accounting date
    std::chrono::year_month_day accounting_date() const;
    /// @brief sets the transaction accounting date
    /// @param date the new transaction accounting date
    void accounting_date(std::chrono::year_month_day date);

    /// @brief returns the transaction value date
    /// @return the transaction value date
    std::optional<std::chrono::year_month_day> value_date() const;
    /// @brief sets the transaction value date
    /// @param date the new transaction value date
    void value_date(std::optional<std::chrono::year_month_day> date);

    /// @brief returns the transaction reconciled state
    /// @return true if the transaction is reconciled, false otherwise
    bool is_reconciled() const;
    /// @brief sets the transaction reconciled state
    /// @param reconciled the new transaction reconciled state
    void is_reconciled(bool reconciled);

    /// @brief returns the transaction amount
    /// @return the transaction amount in cents
    std::int64_t amount() const;
    /// @brief sets the transaction amount
    /// @param cents the new transaction amount in cents
    void amount(std::int64_t cents);

private:
    std::uint64_t id_{0};
    std::uint64_t account_id_{0};
    std::optional<std::uint64_t> category_id_;
    std::string label_;
    std::optional<std::string> note_;
    std::optional<std::string> payment_method_;
    std::optional<std::string> check_number_;
    std::chrono::system_clock::time_point created_at_{};
    std::chrono::year_month_day accounting_date_{};
    std::optional<std::chrono::year_month_day> value_date_;
    bool is_reconciled_{false};
    std::int64_t amount_{0};
};

} // namespace bankbook::data end

#endif  // TRANSACTION_H

/*
    SQL query to create the table

    CREATE TABLE IF NOT EXISTS transactions (
        id              INTEGER PRIMARY KEY,
        account_id      INTEGER NOT NULL REFERENCES accounts(id) ON DELETE RESTRICT,
        category_id     INTEGER REFERENCES categories(id) ON DELETE RESTRICT,  -- NULL = non classée
        label           TEXT NOT NULL,
        note            TEXT,
        payment_method  TEXT,
        check_number    TEXT,
        created_at      INTEGER NOT NULL,   -- secondes depuis l'epoch
        accounting_date TEXT NOT NULL
            CHECK (accounting_date GLOB '[0-9][0-9][0-9][0-9]-[0-9][0-9]-[0-9][0-9]'),
        value_date      TEXT
            CHECK (value_date IS NULL
                OR value_date GLOB '[0-9][0-9][0-9][0-9]-[0-9][0-9]-[0-9][0-9]'),
        is_reconciled   INTEGER NOT NULL DEFAULT 0 CHECK (is_reconciled IN (0, 1)),
        amount          INTEGER NOT NULL    -- centimes, signé (crédit > 0, débit < 0)
    );

    CREATE INDEX IF NOT EXISTS transactions_account_date
        ON transactions(account_id, accounting_date);

    CREATE INDEX IF NOT EXISTS transactions_category
        ON transactions(category_id);
*/
