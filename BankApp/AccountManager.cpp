#include "AccountManager.h"

AccountManager::AccountManager()
    : next_account_ID_(1) {
    std::cout << "AccountManager initialized by default constructor with ID: " << next_account_ID_ << "\n";
}

AccountManager::AccountManager(int next_account_ID)
    : next_account_ID_(next_account_ID) {
    std::cout << "AccountManager initialized with next account ID: " << next_account_ID_ << "\n";
}

std::list<Account*>* AccountManager::get_accounts_list() {
    return &accounts_list_;  // Return reference to the original list
}

int AccountManager::get_next_account_ID() const {
    return next_account_ID_;
}

void AccountManager::add_account(int account_owner_ID) {
    std::string account_type;
    account_type = "deposit";
    Account* new_account = new Account(next_account_ID_, account_owner_ID, 0, account_type);
    accounts_list_.push_back(new_account);
    std::cout << "Account with ID: " << next_account_ID_ << " created for client ID: " << account_owner_ID << std::endl;
    ++next_account_ID_;
}

void AccountManager::delete_account(int account_ID) {
    for (auto it = accounts_list_.begin(); it != accounts_list_.end(); ++it) {
        if ((*it)->get_account_ID() == account_ID) {
            delete* it;  // Delete the Account object pointed to by the pointer
            *it = nullptr;  // Assign nullptr to avoid using a deleted pointer
            accounts_list_.erase(it);  // Remove the pointer from the list
            std::cout << "Account with ID: " << account_ID << " deleted.\n";
            return;
        }
    }
    std::cout << "Account with ID: " << account_ID << " not found.\n";
}

Account* AccountManager::find_account_by_ID(int account_ID) const {
    // Iterate through the list of accounts using a range-based for loop or an iterator
    for (Account* account : accounts_list_) {
        // Check if the current account ID matches the required ID
        if (account->get_account_ID() == account_ID) {
            return account; // Return pointer to the found account
        }
    }
    // If the account with the specified ID is not found, return nullptr
    return nullptr;
}

void AccountManager::show_account_details(int account_ID) const {
    Account* account = find_account_by_ID(account_ID);
    if (account) {
        std::cout << "-------------------------\n";
        std::cout << "Account ID: " << account->get_account_ID()
            << "\nAccount owner ID: " << account->get_account_owner_ID()
            << "\nAccount type: " << account->get_account_type()
            << "\nAccount balance: " << account->get_account_balance() << "$\n";
        std::cout << "-------------------------\n";
    }
    else {
        std::cout << "Account with ID: " << account_ID << " not found.\n";
    }
}

// Show all accounts
void AccountManager::show_all_accounts() const {
    if (accounts_list_.empty()) {
        std::cout << "No accounts to display.\n";
        return;
    }
    std::cout << "List of all accounts:\n";
    for (const Account* account : accounts_list_) {
        show_account_details(account->get_account_ID()); // Call the method to display account details
    }
}

void AccountManager::deposit(int account_ID, double amount) {
    Account* account = find_account_by_ID(account_ID);
    double current_balance = account->get_account_balance();
    account->set_account_balance(current_balance += amount);
}

void AccountManager::withdraw(int account_ID, double amount) {
    Account* account = find_account_by_ID(account_ID);
    double current_balance = account->get_account_balance();
    account->set_account_balance(current_balance -= amount);
}
