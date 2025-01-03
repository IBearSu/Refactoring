#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>

// ��������������� ���������� ��� TransactionManager
class TransactionManager;

class Transaction {
private:
    int transaction_ID_;               // ���������� ������������� ����������
    int sender_account_ID_;            // ID �������� �����������
    int receiver_account_ID_;          // ID �������� ����������
    double amount_;                    // ����� ����������
    TransactionManager* transaction_manager_;  // ��������� �� ��������� ����������

public:
    // �����������
    Transaction(int transaction_ID, int sender_account_ID, int receiver_account_ID, double amount, TransactionManager* manager);

    // ������ ��� ��������� ������
    int get_transaction_ID() const;
    int get_sender_account_ID() const;
    int get_receiver_account_ID() const;
    double get_amount() const;

    // ������ ��� transaction_manager_
    TransactionManager* get_transaction_manager() const;
};

#endif  // TRANSACTION_H
