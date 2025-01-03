#include "TransactionManager.h"
#include "Transaction.h"
#include "AccountManager.h"
#include <iostream>

// Constructor
TransactionManager::TransactionManager(int next_transaction_ID, AccountManager* manager)
    : next_transaction_ID_(next_transaction_ID), account_manager_(manager) {
    std::cout << "TransactionManager initialized with next transaction ID: " << next_transaction_ID_ << "\n";
}

// Destructor to free allocated memory
TransactionManager::~TransactionManager() {
    for (Transaction* transaction : transactions_list_) {
        delete transaction;  // Free memory allocated for transactions
    }
    transactions_list_.clear();  // Clear the transaction list
}

// Return a reference to the transaction list
std::list<Transaction*>& TransactionManager::get_transactions_list() {
    return transactions_list_;  // Return a reference to the original list
}

// Get the next available transaction ID
int TransactionManager::get_next_transaction_ID() const {
    return next_transaction_ID_;
}

// Execute a transaction
void TransactionManager::execute_transaction(int sender_account_ID, int receiver_account_ID, double amount) {
    // Find sender and receiver accounts by their IDs
    Account* sender_account = account_manager_->find_account_by_ID(sender_account_ID);
    Account* receiver_account = account_manager_->find_account_by_ID(receiver_account_ID);

    if (sender_account && receiver_account) {
        // Create a new transaction and add it to the list
        Transaction* new_transaction = new Transaction(next_transaction_ID_, sender_account_ID, receiver_account_ID, amount, this);
        transactions_list_.push_back(new_transaction);

        // Check balance and execute transaction
        double sender_account_balance = sender_account->get_account_balance();
        if (sender_account_balance >= amount || sender_account == receiver_account) {
            account_manager_->withdraw(sender_account_ID, amount);
            account_manager_->deposit(receiver_account_ID, amount);
            std::cout << "Transaction ID: " << next_transaction_ID_ << " executed successfully.\n";
        }
        else {
            std::cout << "Insufficient funds in account " << sender_account_ID << ". Transaction failed.\n";
        }

        // Increment ID for the next transaction
        ++next_transaction_ID_;
    }
    else {
        std::cout << "One or both accounts not found. Transaction failed.\n";
    }
}

// Find a transaction by its ID
Transaction* TransactionManager::find_transaction_by_ID(int transaction_ID) const {
    for (Transaction* transaction : transactions_list_) {
        if (transaction->get_transaction_ID() == transaction_ID) {
            return transaction;  // Return a pointer to the found transaction
        }
    }
    return nullptr;  // Transaction not found
}

// Show information about a specific transaction
void TransactionManager::show_transaction_info(int transaction_ID) const {
    Transaction* transaction = find_transaction_by_ID(transaction_ID);
    if (transaction) {
        std::cout << "-------------------------\n"
            << "Transaction ID: " << transaction->get_transaction_ID()
            << "\nSender ID: " << transaction->get_sender_account_ID()
            << "\nReceiver ID: " << transaction->get_receiver_account_ID()
            << "\nTransaction amount: " << transaction->get_amount()
            << "\n-------------------------\n";
    }
    else {
        std::cout << "Transaction with ID: " << transaction_ID << " not found.\n";
    }
}

// Show all transactions
void TransactionManager::show_all_transactions() const {
    if (transactions_list_.empty()) {
        std::cout << "No transactions to display.\n";
        return;
    }

    std::cout << "List of all transactions:\n";
    for (const Transaction* transaction : transactions_list_) {
        show_transaction_info(transaction->get_transaction_ID());  // Display transaction details
    }
}
