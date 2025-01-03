#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <list>
#include "AccountManager.h"
#include "TransactionManager.h"
#include "IClient.h"  // Include the IClient interface

class Client : public IClient {
private:
    int client_ID_;                      // Unique client identifier
    std::string client_name_;            // Client name
    std::list<int> client_account_IDs_;  // List of client account IDs
    AccountManager* account_manager_;    // Pointer to AccountManager

public:
    // Constructor
    Client(int id, const std::string& name, AccountManager* manager);

    // Implementation of IClient interface methods
    int get_client_ID() const override;
    std::string get_client_name() const override;
    const std::list<int>& get_client_account_IDs() const override;

    // Methods for managing accounts
    void create_account() override;
    void delete_account(int account_ID) override;

    // Transfer money between accounts
    void transfer_between_accounts(TransactionManager* transaction_manager, int from_account_ID, int to_account_ID, double amount) override;

    // Transfer money to another client
    void send_money_to_another_client(TransactionManager* transaction_manager, int from_account_ID, int to_account_ID, double amount) override;
};

#endif
