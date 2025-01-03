#include "test_logger.h"
#include "Bank.h"
#include "test_client.h"
#include "test_transaction_manager.h"
#include "test_client_manager.h"
#include "test_account_manager.h"

void show_menu() {
    std::cout << "\n======= Bank Application Menu =======\n";
    std::cout << "1. Register a new client\n";
    std::cout << "2. Delete a client\n";
    std::cout << "3. Show all clients\n";
    std::cout << "4. Create an account for a client\n";
    std::cout << "5. Delete an account for a client\n";
    std::cout << "6. Show all accounts\n";
    std::cout << "7. Deposit money to an account\n";
    std::cout << "8. Withdraw money from an account\n";
    std::cout << "9. Execute a transaction\n";
    std::cout << "10. Show all transactions\n";
    std::cout << "0. Exit\n";
    std::cout << "=====================================\n";
    std::cout << "Please select an option: ";
}

void run_bank_app() {
    Bank bank;  // Create a Bank object to interact with the system
    int choice;

    do {
        show_menu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // Register a new client via ClientManager
            std::string client_name;
            std::cout << "Enter client's name: ";
            std::cin >> client_name;
            bank.get_client_manager()->add_client(client_name, bank.get_account_manager());
            break;
        }
        case 2: {
            // Delete a client via ClientManager
            int client_ID;
            std::cout << "Enter client ID to delete: ";
            std::cin >> client_ID;
            bank.get_client_manager()->delete_client(client_ID);
            break;
        }
        case 3: {
            // Show all clients via ClientManager
            bank.get_client_manager()->show_all_clients();
            break;
        }
        case 4: {
            // Create an account for a client via AccountManager
            int client_ID;
            std::cout << "Enter client ID to create an account: ";
            std::cin >> client_ID;
            bank.get_client_manager()->find_client_by_ID(client_ID)->create_account();
            break;
        }
        case 5: {
            // Delete an account via AccountManager
            int account_ID;
            std::cout << "Enter account ID to delete: ";
            std::cin >> account_ID;
            bank.get_account_manager()->delete_account(account_ID);
            break;
        }
        case 6: {
            // Show all accounts via AccountManager
            bank.get_account_manager()->show_all_accounts();
            break;
        }
        case 7: {
            // Deposit money into an account via TransactionManager
            int account_ID;
            double amount;
            std::cout << "Enter account ID to deposit: ";
            std::cin >> account_ID;
            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            bank.get_transaction_manager()->execute_transaction(account_ID, account_ID, amount);
            break;
        }
        case 8: {
            // Withdraw money from an account via TransactionManager
            int account_ID;
            double amount;
            std::cout << "Enter account ID to withdraw: ";
            std::cin >> account_ID;
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            bank.get_transaction_manager()->execute_transaction(account_ID, account_ID, -amount);
            break;
        }
        case 9: {
            // Execute a transaction via TransactionManager
            int sender_ID, receiver_ID;
            double amount;
            std::cout << "Enter sender's account ID: ";
            std::cin >> sender_ID;
            std::cout << "Enter receiver's account ID: ";
            std::cin >> receiver_ID;
            std::cout << "Enter amount to transfer: ";
            std::cin >> amount;
            bank.get_transaction_manager()->execute_transaction(sender_ID, receiver_ID, amount);
            break;
        }
        case 10: {
            // Show all transactions via TransactionManager
            bank.get_transaction_manager()->show_all_transactions();
            break;
        }
        case 0:
            std::cout << "Exiting the application...\n";
            break;
        default:
            std::cout << "Invalid option. Please try again.\n";
            break;
        }
    } while (choice != 0);
}

int main() {
    // run_bank_app();
    test_client_all();
    test_transaction_manager_all();
    test_client_manager_all();
    test_account_manager_all();
    return 0;
}
