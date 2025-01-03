#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <iostream>
#include <list>
#include "Client.h"
#include "AccountManager.h"
#include "IClientManager.h"  // Include the IClientManager interface

class ClientManager : public IClientManager {
private:
    std::list<Client*> clients_list_;   // List of clients
    int next_client_ID_;                // Next available client ID

public:
    ClientManager(int next_client_ID);  // Constructor
    ~ClientManager();                   // Destructor to free memory

    // Implementation of IClientManager interface methods
    std::list<Client*>& get_clients_list() override;  // Return a reference to the client list
    int get_next_client_ID() const override;          // Return the next available client ID
    void add_client(const std::string name, AccountManager* account_manager) override;  // Add a client
    void delete_client(int client_ID) override;       // Delete a client
    Client* find_client_by_ID(int client_ID) const override;  // Find a client by ID
    void show_client_info(int client_ID) const override;      // Display client information
    void show_all_clients() const override;           // Display all clients
};

#endif // CLIENT_MANAGER_H
