#include "TransactionManager.h"
#include "AccountManager.h"
#include "Transaction.h"
#include "test_logger.h"
#include "test_transaction_manager.h"

// Тесты для TransactionManager


void test_transaction_manager_all() {
    logger(info, "Starting tests for TransactionManager class");

    test_execute_transaction_success();
    test_execute_transaction_insufficient_funds();
    test_find_transaction_by_ID();
    test_show_transaction_info();
    test_show_all_transactions();

    logger(info, "Tests for TransactionManager class completed");
}

void test_execute_transaction_success() {
    AccountManager account_manager;

    // Добавляем два аккаунта с балансами
    account_manager.add_account(1);
    account_manager.add_account(2);

    account_manager.find_account_by_ID(1)->set_account_balance(500.0);  // Устанавливаем баланс для аккаунта 1
    account_manager.find_account_by_ID(2)->set_account_balance(300.0);  // Устанавливаем баланс для аккаунта 2

    TransactionManager transaction_manager(1, &account_manager);

    transaction_manager.execute_transaction(1, 2, 200.0);  // Переводим 200 с аккаунта 1 на аккаунт 2

    double balance_sender = account_manager.find_account_by_ID(1)->get_account_balance();
    double balance_receiver = account_manager.find_account_by_ID(2)->get_account_balance();

    log_assertion(balance_sender == 300.0, "Test Execute Transaction Success - Sender Account");
    log_assertion(balance_receiver == 500.0, "Test Execute Transaction Success - Receiver Account");
}

void test_execute_transaction_insufficient_funds() {
    AccountManager account_manager;

    // Добавляем два аккаунта с балансами
    account_manager.add_account(1);
    account_manager.add_account(2);

    account_manager.find_account_by_ID(1)->set_account_balance(100.0);  // Устанавливаем баланс для аккаунта 1
    account_manager.find_account_by_ID(2)->set_account_balance(300.0);  // Устанавливаем баланс для аккаунта 2

    TransactionManager transaction_manager(1, &account_manager);

    transaction_manager.execute_transaction(1, 2, 200.0);  // Пытаемся перевести 200 с аккаунта 1 на аккаунт 2 (недостаточно средств)

    double balance_sender = account_manager.find_account_by_ID(1)->get_account_balance();
    double balance_receiver = account_manager.find_account_by_ID(2)->get_account_balance();

    log_assertion(balance_sender == 100.0, "Test Execute Transaction Insufficient Funds - Sender Account");
    log_assertion(balance_receiver == 300.0, "Test Execute Transaction Insufficient Funds - Receiver Account");
}

void test_find_transaction_by_ID() {
    AccountManager account_manager;
    TransactionManager transaction_manager(1, &account_manager);

    account_manager.add_account(1);
    account_manager.add_account(2);

    account_manager.find_account_by_ID(1)->set_account_balance(100.0);  // Устанавливаем баланс для аккаунта 1
    account_manager.find_account_by_ID(2)->set_account_balance(300.0);  // Устанавливаем баланс для аккаунта 2

    // Добавляем две транзакции
    transaction_manager.execute_transaction(1, 2, 50.0);
    transaction_manager.execute_transaction(3, 4, 100.0);

    // Проверяем, что транзакции можно найти по их ID
    Transaction* transaction1 = transaction_manager.find_transaction_by_ID(1);
    Transaction* transaction2 = transaction_manager.find_transaction_by_ID(2);

    log_assertion(transaction1 != nullptr, "Test Find Transaction by ID 1");
    log_assertion(transaction2 == nullptr, "Test Find Transaction by ID 2");

    // Проверяем, что ID и суммы совпадают
    if (transaction1) {
        log_assertion(transaction1->get_amount() == 50.0, "Test Transaction 1 Amount");
    }
}

void test_show_transaction_info() {
    AccountManager account_manager;
    TransactionManager transaction_manager(1, &account_manager);

    // Добавляем транзакцию
    transaction_manager.execute_transaction(1, 2, 50.0);

    // Проверяем вывод информации о транзакции
    logger(info, "Testing show_transaction_info for transaction with ID 1:");
    transaction_manager.show_transaction_info(1);
}

void test_show_all_transactions() {
    AccountManager account_manager;
    TransactionManager transaction_manager(1, &account_manager);
    account_manager.add_account(1);
    account_manager.add_account(2);

    account_manager.find_account_by_ID(1)->set_account_balance(100.0);  // Устанавливаем баланс для аккаунта 1
    account_manager.find_account_by_ID(2)->set_account_balance(300.0);  // Устанавливаем баланс для аккаунта 2
    // Добавляем несколько транзакций
    transaction_manager.execute_transaction(1, 2, 50.0);
    transaction_manager.execute_transaction(2, 1, 100.0);

    // Проверяем вывод всех транзакций
    logger(info, "Testing show_all_transactions:");
    transaction_manager.show_all_transactions();
}


