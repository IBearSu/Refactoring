#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include <iostream>
#include "Account.h"
#include <list>
#include "IAccountManager.h"  // Include the IAccountManager interface

class AccountManager : public IAccountManager {
private:
    std::list<Account*> accounts_list_;   // List of accounts
    int next_account_ID_;                  // Next available account ID

public:
    AccountManager();
    AccountManager(int next_account_ID);

    std::list<Account*>* get_accounts_list() override; // Return reference to this list, not a copy
    int get_next_account_ID() const override;
    // Add a new account
    void add_account(int account_owner_ID) override;
    // Delete an account by its ID
    void delete_account(int account_ID) override;
    // Find an account by its ID
    Account* find_account_by_ID(int account_ID) const override;
    void show_account_details(int account_ID) const override;
    // Show all accounts
    void show_all_accounts() const override;
    void deposit(int account_ID, double amount) override;
    void withdraw(int account_ID, double amount) override;
};

#endif  
