#ifndef TRANSACTION_MANAGER_H
#define TRANSACTION_MANAGER_H

#include <list>
#include "Transaction.h"
#include "AccountManager.h"
#include "ITransactionManager.h"  // Подключаем интерфейс

class TransactionManager : public ITransactionManager {
private:
    std::list<Transaction*> transactions_list_;   // Список транзакций
    int next_transaction_ID_;                     // Следующий ID для транзакции
    AccountManager* account_manager_;             // Указатель на AccountManager

public:
    TransactionManager(int next_transaction_ID, AccountManager* manager);

    ~TransactionManager();  // Деструктор для освобождения памяти

    // Реализация методов интерфейса ITransactionManager
    std::list<Transaction*>& get_transactions_list() override;
    int get_next_transaction_ID() const override;
    void execute_transaction(int sender_ID, int receiver_ID, double amount) override;
    Transaction* find_transaction_by_ID(int transaction_ID) const override;
    void show_transaction_info(int transaction_ID) const override;
    void show_all_transactions() const override;
};

#endif // TRANSACTION_MANAGER_H
