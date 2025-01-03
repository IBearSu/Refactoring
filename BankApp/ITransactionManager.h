#ifndef ITRANSACTION_MANAGER_H
#define ITRANSACTION_MANAGER_H

#include <list>
#include "Transaction.h"
#include "AccountManager.h"

class ITransactionManager {
public:
    virtual ~ITransactionManager() {}

    virtual std::list<Transaction*>& get_transactions_list() = 0;
    virtual int get_next_transaction_ID() const = 0;
    virtual void execute_transaction(int sender_ID, int receiver_ID, double amount) = 0;
    virtual Transaction* find_transaction_by_ID(int transaction_ID) const = 0;
    virtual void show_transaction_info(int transaction_ID) const = 0;
    virtual void show_all_transactions() const = 0;
};

#endif // ITRANSACTION_MANAGER_H