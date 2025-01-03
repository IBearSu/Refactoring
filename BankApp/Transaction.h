#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>

// Предварительное объявление для TransactionManager
class TransactionManager;

class Transaction {
private:
    int transaction_ID_;               // Уникальный идентификатор транзакции
    int sender_account_ID_;            // ID аккаунта отправителя
    int receiver_account_ID_;          // ID аккаунта получателя
    double amount_;                    // Сумма транзакции
    TransactionManager* transaction_manager_;  // Указатель на менеджера транзакций

public:
    // Конструктор
    Transaction(int transaction_ID, int sender_account_ID, int receiver_account_ID, double amount, TransactionManager* manager);

    // Методы для получения данных
    int get_transaction_ID() const;
    int get_sender_account_ID() const;
    int get_receiver_account_ID() const;
    double get_amount() const;

    // геттер для transaction_manager_
    TransactionManager* get_transaction_manager() const;
};

#endif  // TRANSACTION_H
