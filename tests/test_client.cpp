#include "test_client.h"
#include "Client.h"
#include "AccountManager.h"
#include "TransactionManager.h"
#include "test_logger.h"

void test_client_all() {
    logger(info, "Starting tests for Client class");

    test_create_account();
    test_delete_account();
    test_transfer_between_accounts();
    test_send_money_to_another_client();

    logger(info, "Client class tests completed");
}

void test_create_account() {
    AccountManager account_manager;
    Client client(1, "John Doe", &account_manager);

    size_t initial_size = account_manager.get_accounts_list()->size();
    client.create_account();
    size_t new_size = account_manager.get_accounts_list()->size();

    log_assertion(new_size == initial_size + 1, "Test Create Account");
}

void test_delete_account() {
    AccountManager account_manager;
    Client client(1, "Jane Doe", &account_manager);

    client.create_account();

    // Проверяем, что список аккаунтов не пуст
    if (!client.get_client_account_IDs().empty()) {
        int account_ID = *client.get_client_account_IDs().begin();  // Получаем ID первого аккаунта

        size_t initial_size = account_manager.get_accounts_list()->size();
        client.delete_account(account_ID);
        size_t new_size = account_manager.get_accounts_list()->size();

        log_assertion(new_size == initial_size - 1, "Test Delete Account");
    }
    else {
        log_assertion(false, "Test Delete Account - No account found");
    }
}


void test_transfer_between_accounts() {
    AccountManager account_manager;
    TransactionManager transaction_manager(1, &account_manager);

    Client client1(1, "Alice", &account_manager);
    Client client2(2, "Bob", &account_manager);

    client1.create_account();
    client2.create_account();

    int client1_account_ID = *client1.get_client_account_IDs().begin();
    int client2_account_ID = *client2.get_client_account_IDs().begin();

    account_manager.find_account_by_ID(client1_account_ID)->set_account_balance(500.0);
    account_manager.find_account_by_ID(client2_account_ID)->set_account_balance(100.0);

    client1.transfer_between_accounts(&transaction_manager, client1_account_ID, client2_account_ID, 200.0);

    double client1_balance = account_manager.find_account_by_ID(client1_account_ID)->get_account_balance();
    double client2_balance = account_manager.find_account_by_ID(client2_account_ID)->get_account_balance();

    log_assertion(client1_balance == 300.0, "Test Transfer Between Accounts (Sender)");
    log_assertion(client2_balance == 300.0, "Test Transfer Between Accounts (Receiver)");
}

void test_send_money_to_another_client() {
    AccountManager account_manager;
    TransactionManager transaction_manager(1, &account_manager);

    Client client1(1, "Charlie", &account_manager);
    Client client2(2, "David", &account_manager);

    client1.create_account();
    client2.create_account();

    int client1_account_ID = *client1.get_client_account_IDs().begin();
    int client2_account_ID = *client2.get_client_account_IDs().begin();

    account_manager.find_account_by_ID(client1_account_ID)->set_account_balance(500.0);
    account_manager.find_account_by_ID(client2_account_ID)->set_account_balance(100.0);

    client1.send_money_to_another_client(&transaction_manager, client1_account_ID, client2_account_ID, 200.0);

    double client1_balance = account_manager.find_account_by_ID(client1_account_ID)->get_account_balance();
    double client2_balance = account_manager.find_account_by_ID(client2_account_ID)->get_account_balance();

    log_assertion(client1_balance == 300.0, "Test Send Money To Another Client (Sender)");
    log_assertion(client2_balance == 300.0, "Test Send Money To Another Client (Receiver)");
}

