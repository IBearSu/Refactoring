#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>

class Account {
private:
    int account_ID_;                  // Unique account identifier
    int account_owner_ID_;             // Account owner's ID
    double account_balance_;           // Account balance
    std::string account_type_;         // Account type (e.g., deposit or credit)

public:
    Account(int account_ID, int account_owner_ID, double account_balance, const std::string& account_type);

    // Get account ID
    int get_account_ID() const;

    // Get account owner's ID
    int get_account_owner_ID() const;

    // Get account balance
    double get_account_balance() const;

    // Get account type
    const std::string& get_account_type() const;

    // Set account balance
    void set_account_balance(double amount);
};

#endif  // ACCOUNT_H
