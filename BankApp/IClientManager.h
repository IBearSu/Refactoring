#ifndef ICLIENT_MANAGER_H
#define ICLIENT_MANAGER_H

#include <string>
#include <list>
#include "Client.h"

class IClientManager {
public:
    virtual ~IClientManager() {}

    virtual std::list<Client*>& get_clients_list() = 0;  // Return a reference to the client list
    virtual int get_next_client_ID() const = 0;          // Get the next available client ID
    virtual void add_client(const std::string name, AccountManager* account_manager) = 0;  // Add a new client
    virtual void delete_client(int client_ID) = 0;       // Delete a client by ID
    virtual Client* find_client_by_ID(int client_ID) const = 0;  // Find a client by ID
    virtual void show_client_info(int client_ID) const = 0;      // Display client information
    virtual void show_all_clients() const = 0;           // Display all clients
};

#endif // ICLIENT_MANAGER_H
