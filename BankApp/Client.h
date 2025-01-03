#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <list>
#include "AccountManager.h"
#include "TransactionManager.h"
#include "IClient.h"  // Подключаем интерфейс

class Client : public IClient {
private:
    int client_ID_;                      // Уникальный идентификатор клиента
    std::string client_name_;            // Имя клиента
    std::list<int> client_account_IDs_;  // Список идентификаторов аккаунтов клиента
    AccountManager* account_manager_;    // Указатель на AccountManager

public:
    // Конструктор
    Client(int id, const std::string& name, AccountManager* manager);

    // Реализация методов интерфейса IClient
    int get_client_ID() const override;
    std::string get_client_name() const override;
    const std::list<int>& get_client_account_IDs() const override;

    // Методы для работы с аккаунтами
    void create_account() override;
    void delete_account(int account_ID) override;

    // Перевод денег между аккаунтами
    void transfer_between_accounts(TransactionManager* transaction_manager, int from_account_ID, int to_account_ID, double amount) override;

    // Перевод денег другому клиенту
    void send_money_to_another_client(TransactionManager* transaction_manager, int from_account_ID, int to_account_ID, double amount) override;
};

#endif
