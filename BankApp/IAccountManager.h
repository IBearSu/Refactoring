#ifndef IACCOUNT_MANAGER_H
#define IACCOUNT_MANAGER_H

#include <list>
#include "Account.h"

class IAccountManager {
public:
    virtual ~IAccountManager() {}

    virtual std::list<Account*>* get_accounts_list() = 0;  // Return a reference to the account list
    virtual int get_next_account_ID() const = 0;           // Get the next available account ID
    virtual void add_account(int account_owner_ID) = 0;    // Add a new account
    virtual void delete_account(int account_ID) = 0;       // Delete an account by ID
    virtual Account* find_account_by_ID(int account_ID) const = 0;  // Find an account by ID
    virtual void show_account_details(int account_ID) const = 0;     // Display account details
    virtual void show_all_accounts() const = 0;            // Display all accounts
    virtual void deposit(int account_ID, double amount) = 0;  // Deposit money into an account
    virtual void withdraw(int account_ID, double amount) = 0; // Withdraw money from an account
};

#endif // IACCOUNT_MANAGER_H
