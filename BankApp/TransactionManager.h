#ifndef TRANSACTION_MANAGER_H
#define TRANSACTION_MANAGER_H

#include <list>
#include "Transaction.h"
#include "AccountManager.h"
#include "ITransactionManager.h"  // ���������� ���������

class TransactionManager : public ITransactionManager {
private:
    std::list<Transaction*> transactions_list_;   // ������ ����������
    int next_transaction_ID_;                     // ��������� ID ��� ����������
    AccountManager* account_manager_;             // ��������� �� AccountManager

public:
    TransactionManager(int next_transaction_ID, AccountManager* manager);

    ~TransactionManager();  // ���������� ��� ������������ ������

    // ���������� ������� ���������� ITransactionManager
    std::list<Transaction*>& get_transactions_list() override;
    int get_next_transaction_ID() const override;
    void execute_transaction(int sender_ID, int receiver_ID, double amount) override;
    Transaction* find_transaction_by_ID(int transaction_ID) const override;
    void show_transaction_info(int transaction_ID) const override;
    void show_all_transactions() const override;
};

#endif // TRANSACTION_MANAGER_H
