#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <iostream>
#include <list>
#include "Client.h"
#include "AccountManager.h"
#include "IClientManager.h"  // Подключаем интерфейс

class ClientManager : public IClientManager {
private:
    std::list<Client*> clients_list_;   // Список клиентов
    int next_client_ID_;                // Следующий доступный ID для клиента

public:
    ClientManager(int next_client_ID);  // Конструктор
    ~ClientManager();                   // Деструктор для освобождения памяти

    // Реализация методов интерфейса IClientManager
    std::list<Client*>& get_clients_list() override;  // Возвращаем ссылку на список
    int get_next_client_ID() const override;          // Возвращаем следующий доступный ID
    void add_client(const std::string name, AccountManager* account_manager) override;  // Добавить клиента
    void delete_client(int client_ID) override;       // Удалить клиента
    Client* find_client_by_ID(int client_ID) const override;  // Найти клиента по ID
    void show_client_info(int client_ID) const override;      // Показать информацию о клиенте
    void show_all_clients() const override;           // Показать всех клиентов
};

#endif // CLIENT_MANAGER_H
