#include "AccountManager.h"
#include "test_logger.h"
#include "test_account_manager.h"

// Тесты для AccountManager

void test_account_manager_all() {
    logger(info, "Starting tests for AccountManager class");

    test_AM_add_account();
    test_AM_delete_account();
    test_find_account_by_ID();
    test_deposit();
    test_withdraw();
    test_show_account_details();
    test_show_all_accounts();

    logger(info, "Tests for AccountManager class completed");
}

void test_AM_add_account() {
    AccountManager account_manager;

    // Добавляем новый аккаунт
    account_manager.add_account(1);

    // Проверяем, что аккаунт был добавлен и что следующий ID аккаунта был увеличен
    log_assertion(account_manager.get_accounts_list()->size() == 1, "Test Add Account - Size");
    log_assertion(account_manager.get_next_account_ID() == 2, "Test Add Account - Next Account ID");

    Account* added_account = account_manager.find_account_by_ID(1);
    log_assertion(added_account != nullptr, "Test Add Account - Account Exists");
    log_assertion(added_account->get_account_owner_ID() == 1, "Test Add Account - Owner ID");
}

void test_AM_delete_account() {
    AccountManager account_manager;

    // Добавляем два аккаунта
    account_manager.add_account(1);
    account_manager.add_account(2);

    // Удаляем первый аккаунт
    account_manager.delete_account(1);

    // Проверяем, что аккаунт был удален
    log_assertion(account_manager.get_accounts_list()->size() == 1, "Test Delete Account - Size");
    log_assertion(account_manager.find_account_by_ID(1) == nullptr, "Test Delete Account - Account Deleted");
}

void test_find_account_by_ID() {
    AccountManager account_manager;

    // Добавляем два аккаунта
    account_manager.add_account(1);
    account_manager.add_account(2);

    // Проверяем, что аккаунты можно найти по ID
    Account* account1 = account_manager.find_account_by_ID(1);
    Account* account2 = account_manager.find_account_by_ID(2);

    log_assertion(account1 != nullptr, "Test Find Account by ID 1");
    log_assertion(account2 != nullptr, "Test Find Account by ID 2");
}

void test_deposit() {
    AccountManager account_manager;

    // Добавляем аккаунт и устанавливаем баланс
    account_manager.add_account(1);
    account_manager.deposit(1, 100.0);

    Account* account = account_manager.find_account_by_ID(1);
    double balance = account->get_account_balance();

    // Проверяем, что баланс был увеличен
    log_assertion(balance == 100.0, "Test Deposit - Balance");
}

void test_withdraw() {
    AccountManager account_manager;

    // Добавляем аккаунт, пополняем его и затем снимаем деньги
    account_manager.add_account(1);
    account_manager.deposit(1, 100.0);
    account_manager.withdraw(1, 50.0);

    Account* account = account_manager.find_account_by_ID(1);
    double balance = account->get_account_balance();

    // Проверяем, что баланс был уменьшен
    log_assertion(balance == 50.0, "Test Withdraw - Balance");
}

void test_show_account_details() {
    AccountManager account_manager;

    // Добавляем аккаунт и выводим его информацию
    account_manager.add_account(1);
    logger(info, "Testing show_account_details for account with ID 1:");
    account_manager.show_account_details(1);
}

void test_show_all_accounts() {
    AccountManager account_manager;

    // Добавляем несколько аккаунтов и выводим информацию о всех
    account_manager.add_account(1);
    account_manager.add_account(2);

    logger(info, "Testing show_all_accounts:");
    account_manager.show_all_accounts();
}

