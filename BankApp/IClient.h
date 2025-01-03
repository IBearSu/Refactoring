#ifndef ICLIENT_H
#define ICLIENT_H

#include <string>
#include <list>
#include "AccountManager.h"
#include "TransactionManager.h"

class IClient {
public:
    virtual ~IClient() {}

    virtual int get_client_ID() const = 0;  // Get client ID
    virtual std::string get_client_name() const = 0;  // Get client name
    virtual const std::list<int>& get_client_account_IDs() const = 0;  // Get list of client account IDs
    virtual void create_account() = 0;  // Create a new account
    virtual void delete_account(int account_ID) = 0;  // Delete an account
    virtual void transfer_between_accounts(TransactionManager* transaction_manager, int from_account_ID, int to_account_ID, double amount) = 0;  // Transfer funds between client's own accounts
    virtual void send_money_to_another_client(TransactionManager* transaction_manager, int from_account_ID, int to_account_ID, double amount) = 0;  // Transfer funds to another client
};

#endif // ICLIENT_H
