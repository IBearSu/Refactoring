#ifndef BANK_H
#define BANK_H

#include "ClientManager.h"
#include "TransactionManager.h"
#include "AccountManager.h"
#include <string>

class Bank {
private:
    ClientManager client_manager_;
    TransactionManager transaction_manager_;
    AccountManager account_manager_;

public:
    // default constructor
    Bank();
    // default getters
    ClientManager* get_client_manager();
    TransactionManager* get_transaction_manager();
    AccountManager* get_account_manager();
};

#endif // BANK_H
