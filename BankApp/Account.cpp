#include "Account.h"

// Using an initializer list to initialize class members
Account::Account(int account_ID, int account_owner_ID, double account_balance, const std::string& account_type)
    : account_ID_(account_ID),
    account_owner_ID_(account_owner_ID),
    account_balance_(account_balance),
    account_type_(account_type) {
}

// Get account ID
int Account::get_account_ID() const {
    return account_ID_;
}

// Get account owner's ID
int Account::get_account_owner_ID() const {
    return account_owner_ID_;
}

// Get account balance
double Account::get_account_balance() const {
    return account_balance_;
}

// Get account type (returning a reference to a string for optimization)
const std::string& Account::get_account_type() const {
    return account_type_;
}

// Set account balance
void Account::set_account_balance(double amount) {
    account_balance_ = amount;
}
