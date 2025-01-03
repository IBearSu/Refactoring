#include "Client.h"

// Constructor
Client::Client(int id, const std::string& name, AccountManager* manager)
    : client_ID_(id), client_name_(name), account_manager_(manager) {
}

// Get client ID
int Client::get_client_ID() const {
    return client_ID_;
}

// Get client name
std::string Client::get_client_name() const {
    return client_name_;
}

// Return a reference to the list of client account IDs (read-only)
const std::list<int>& Client::get_client_account_IDs() const {
    return client_account_IDs_;
}

// Create a new account (using internal account_manager_)
void Client::create_account() {
    std::cout << "Client " << client_name_ << " with ID: " << client_ID_
        << " asked AccountManager to create an account.\n";
    account_manager_->add_account(client_ID_);
    int new_account_ID = account_manager_->get_next_account_ID() - 1;
    client_account_IDs_.push_back(new_account_ID);
    std::cout << "Account ID " << new_account_ID << " added to client account list.\n";
}

// Delete an account (using internal account_manager_)
void Client::delete_account(int account_ID) {
    std::cout << "Client " << client_name_ << " with ID: " << client_ID_
        << " asked AccountManager to delete account: " << account_ID << std::endl;
    account_manager_->delete_account(account_ID);
    // Remove account_ID from client_account_IDs_ list
    auto it = std::find(client_account_IDs_.begin(), client_account_IDs_.end(), account_ID);
    if (it != client_account_IDs_.end()) {
        client_account_IDs_.erase(it);  // Remove the found element
        std::cout << "Account ID " << account_ID << " removed from client account list.\n";
    }
    else {
        std::cout << "Account ID " << account_ID << " not found in client's account list.\n";
    }
}

// Transfer money between client's own accounts
void Client::transfer_between_accounts(TransactionManager* transaction_manager, int from_account_ID, int to_account_ID, double amount) {
    std::cout << "Asked TransactionManager to transfer " << amount << "$"
        << " from account " << from_account_ID << " to account " << to_account_ID << std::endl;
    transaction_manager->execute_transaction(from_account_ID, to_account_ID, amount);
}

// Transfer money to another client
void Client::send_money_to_another_client(TransactionManager* transaction_manager, int from_account_ID, int to_account_ID, double amount) {
    transfer_between_accounts(transaction_manager, from_account_ID, to_account_ID, amount);
}
