#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <iostream>
#include <list>
#include "Client.h"
#include "AccountManager.h"
#include "IClientManager.h"  // ���������� ���������

class ClientManager : public IClientManager {
private:
    std::list<Client*> clients_list_;   // ������ ��������
    int next_client_ID_;                // ��������� ��������� ID ��� �������

public:
    ClientManager(int next_client_ID);  // �����������
    ~ClientManager();                   // ���������� ��� ������������ ������

    // ���������� ������� ���������� IClientManager
    std::list<Client*>& get_clients_list() override;  // ���������� ������ �� ������
    int get_next_client_ID() const override;          // ���������� ��������� ��������� ID
    void add_client(const std::string name, AccountManager* account_manager) override;  // �������� �������
    void delete_client(int client_ID) override;       // ������� �������
    Client* find_client_by_ID(int client_ID) const override;  // ����� ������� �� ID
    void show_client_info(int client_ID) const override;      // �������� ���������� � �������
    void show_all_clients() const override;           // �������� ���� ��������
};

#endif // CLIENT_MANAGER_H
