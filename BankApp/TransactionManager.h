#ifndef TRANSACTION_MANAGER_H
#define TRANSACTION_MANAGER_H

#include <list>
#include "Transaction.h"
#include "AccountManager.h"
#include "ITransactionManager.h"  // Include the ITransactionManager interface

class TransactionManager : public ITransactionManager {
private:
    std::list<Transaction*> transactions_list_;   // List of transactions
    int next_transaction_ID_;                     // Next available transaction ID
    AccountManager* account_manager_;             // Pointer to AccountManager

public:
    TransactionManager(int next_transaction_ID, AccountManager* manager);

    ~TransactionManager();  // Destructor to free allocated memory

    // Implementation of ITransactionManager interface methods
    std::list<Transaction*>& get_transactions_list() override;
    int get_next_transaction_ID() const override;
    void execute_transaction(int sender_ID, int receiver_ID, double amount) override;
    Transaction* find_transaction_by_ID(int transaction_ID) const override;
    void show_transaction_info(int transaction_ID) const override;
    void show_all_transactions() const override;
};

#endif // TRANSACTION_MANAGER_H
