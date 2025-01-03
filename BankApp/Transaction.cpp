#include "Transaction.h"
#include "Account.h"
#include "AccountManager.h"

// Constructor
Transaction::Transaction(int transaction_ID, int sender_account_ID, int receiver_account_ID, double amount, TransactionManager* manager)
    : transaction_ID_(transaction_ID),
    sender_account_ID_(sender_account_ID),
    receiver_account_ID_(receiver_account_ID),
    amount_(amount),
    transaction_manager_(manager) {
    std::cout << "Transaction: " << amount << "$ from " << sender_account_ID
        << " to " << receiver_account_ID << " created with ID: " << transaction_ID_ << "\n";
}

// Getter methods
int Transaction::get_transaction_ID() const {
    return transaction_ID_;
}

int Transaction::get_sender_account_ID() const {
    return sender_account_ID_;
}

int Transaction::get_receiver_account_ID() const {
    return receiver_account_ID_;
}

double Transaction::get_amount() const {
    return amount_;
}

// Getter for transaction_manager_
TransactionManager* Transaction::get_transaction_manager() const {
    return transaction_manager_;
}
