#include "Bank.h"
#include <iostream>

// Default constructor for composition
Bank::Bank()
    : client_manager_(1),
    transaction_manager_(1, &account_manager_),
    account_manager_(1) {
    std::cout << "Bank initialized.\n";
}

ClientManager* Bank::get_client_manager() {
    return &client_manager_; // Return a pointer to the client manager
}

TransactionManager* Bank::get_transaction_manager() {
    return &transaction_manager_; // Return a pointer to the transaction manager
}

AccountManager* Bank::get_account_manager() {
    return &account_manager_; // Return a pointer to the account manager
}
