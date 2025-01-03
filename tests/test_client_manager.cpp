#include "ClientManager.h"
#include "AccountManager.h"
#include "test_client_manager.h"
#include "test_logger.h"

// Tests for ClientManager

void test_client_manager_all() {
    logger(info, "Starting tests for ClientManager class");

    test_add_client();
    test_delete_client();
    test_find_client_by_ID();
    test_show_client_info();
    test_show_all_clients();

    logger(info, "Tests for ClientManager class completed");
}

void test_add_client() {
    AccountManager account_manager;
    ClientManager client_manager(1);  // Initial client ID is set to 1

    // Add a client
    client_manager.add_client("John Doe", &account_manager);

    // Verify that the client was added and that the next client ID was incremented
    log_assertion(client_manager.get_clients_list().size() == 1, "Test Add Client - Size");
    log_assertion(client_manager.get_next_client_ID() == 2, "Test Add Client - Next Client ID");

    Client* added_client = client_manager.find_client_by_ID(1);
    log_assertion(added_client != nullptr, "Test Add Client - Client Exists");
    log_assertion(added_client->get_client_name() == "John Doe", "Test Add Client - Client Name");
}

void test_delete_client() {
    AccountManager account_manager;
    ClientManager client_manager(1);

    // Add a client
    client_manager.add_client("Jane Doe", &account_manager);

    // Delete the client
    client_manager.delete_client(1);

    // Verify that the client was deleted
    log_assertion(client_manager.get_clients_list().size() == 0, "Test Delete Client - Size");
    log_assertion(client_manager.find_client_by_ID(1) == nullptr, "Test Delete Client - Client Deleted");
}

void test_find_client_by_ID() {
    AccountManager account_manager;
    ClientManager client_manager(1);

    // Add two clients
    client_manager.add_client("Alice", &account_manager);
    client_manager.add_client("Bob", &account_manager);

    // Verify that clients can be found by ID
    Client* client1 = client_manager.find_client_by_ID(1);
    Client* client2 = client_manager.find_client_by_ID(2);

    log_assertion(client1 != nullptr, "Test Find Client by ID 1");
    log_assertion(client2 != nullptr, "Test Find Client by ID 2");

    // Verify client names
    if (client1) {
        log_assertion(client1->get_client_name() == "Alice", "Test Find Client 1 Name");
    }
    if (client2) {
        log_assertion(client2->get_client_name() == "Bob", "Test Find Client 2 Name");
    }
}

void test_show_client_info() {
    AccountManager account_manager;
    ClientManager client_manager(1);

    // Add a client
    client_manager.add_client("Charlie", &account_manager);

    // Verify output of client information
    logger(info, "Testing show_client_info for client with ID 1:");
    client_manager.show_client_info(1);
}

void test_show_all_clients() {
    AccountManager account_manager;
    ClientManager client_manager(1);

    // Add multiple clients
    client_manager.add_client("Charlie", &account_manager);
    client_manager.add_client("David", &account_manager);

    // Verify output of all clients
    logger(info, "Testing show_all_clients:");
    client_manager.show_all_clients();
}
