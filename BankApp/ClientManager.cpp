#include "ClientManager.h"
#include <iostream>

// �����������
ClientManager::ClientManager(int next_client_ID)
    : next_client_ID_(next_client_ID) {
    std::cout << "ClientManager initialized with next client ID: " << next_client_ID_ << "\n";
}

// ���������� ��� ������������ ������ ��������
ClientManager::~ClientManager() {
    for (Client* client : clients_list_) {
        delete client;  // ������� �������� �� ������������ ������
    }
    clients_list_.clear();  // ������� ������ ��������
}

// ���������� ������ �� ������ ��������
std::list<Client*>& ClientManager::get_clients_list() {
    return clients_list_;  // ���������� ������ �� ������������ ������
}

// ���������� ��������� ��������� ID �������
int ClientManager::get_next_client_ID() const {
    return next_client_ID_;
}

// ��������� ������ �������
void ClientManager::add_client(const std::string name, AccountManager* account_manager) {
    Client* new_client = new Client(next_client_ID_, name, account_manager);  // ������� ������� � ������������ ������
    clients_list_.push_back(new_client);  // ��������� ������� � ������
    std::cout << "Client added: " << name << " with ID: " << next_client_ID_ << std::endl;
    ++next_client_ID_;  // ����������� ��������� ��������� ID
}

// ������� ������� �� ID
void ClientManager::delete_client(int client_ID) {
    for (auto it = clients_list_.begin(); it != clients_list_.end(); ++it) {
        if ((*it)->get_client_ID() == client_ID) {
            delete* it;  // ������� ������� �� ������
            clients_list_.erase(it);  // ������� ��������� �� ������
            std::cout << "Client with ID: " << client_ID << " deleted.\n";
            return;
        }
    }
    std::cout << "Client with ID: " << client_ID << " not found.\n";
}

// ������� ������� �� ��� ID
Client* ClientManager::find_client_by_ID(int client_ID) const {
    for (Client* client : clients_list_) {
        if (client->get_client_ID() == client_ID) {
            return client;  // ���������� ��������� �� ���������� �������
        }
    }
    return nullptr;
}

// ���������� ���������� � �������
void ClientManager::show_client_info(int client_ID) const {
    Client* client = find_client_by_ID(client_ID);
    if (client) {
        std::cout << "-------------------------\n";
        std::cout << "Client ID: " << client->get_client_ID()
            << "\nClient name: " << client->get_client_name()
            << "\nAccount IDs: ";

        const std::list<int>& account_IDs = client->get_client_account_IDs();
        if (account_IDs.empty()) {
            std::cout << "No accounts.\n";
        }
        else {
            for (int account_ID : account_IDs) {
                std::cout << account_ID << " ";
            }
            std::cout << "\n";
        }
        std::cout << "-------------------------\n";
    }
    else {
        std::cout << "Client with ID: " << client_ID << " not found.\n";
    }
}

// �������� ���� ��������
void ClientManager::show_all_clients() const {
    if (clients_list_.empty()) {
        std::cout << "No clients to display.\n";
        return;
    }
    std::cout << "List of all clients:\n";
    for (const Client* client : clients_list_) {
        show_client_info(client->get_client_ID());
    }
}
