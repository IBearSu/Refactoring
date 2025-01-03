#ifndef ICLIENT_H
#define ICLIENT_H

#include <string>
#include <list>
#include "AccountManager.h"
#include "TransactionManager.h"

class IClient {
public:
    virtual ~IClient() {}

    virtual int get_client_ID() const = 0;
    virtual std::string get_client_name() const = 0;
    virtual const std::list<int>& get_client_account_IDs() const = 0;
    virtual void create_account() = 0;
    virtual void delete_account(int account_ID) = 0;
    virtual void transfer_between_accounts(TransactionManager* transaction_manager, int from_account_ID, int to_account_ID, double amount) = 0;
    virtual void send_money_to_another_client(TransactionManager* transaction_manager, int from_account_ID, int to_account_ID, double amount) = 0;
};

#endif // ICLIENT_H
