#ifndef IACCOUNT_MANAGER_H
#define IACCOUNT_MANAGER_H

#include <list>
#include "Account.h"

class IAccountManager {
public:
    virtual ~IAccountManager() {}

    virtual std::list<Account*>* get_accounts_list() = 0;
    virtual int get_next_account_ID() const = 0;
    virtual void add_account(int account_owner_ID) = 0;
    virtual void delete_account(int account_ID) = 0;
    virtual Account* find_account_by_ID(int account_ID) const = 0;
    virtual void show_account_details(int account_ID) const = 0;
    virtual void show_all_accounts() const = 0;
    virtual void deposit(int account_ID, double amount) = 0;
    virtual void withdraw(int account_ID, double amount) = 0;
};

#endif // IACCOUNT_MANAGER_H
