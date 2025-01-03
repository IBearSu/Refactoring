#include "TransactionManager.h"
#include "AccountManager.h"
#include "Transaction.h"
#include "test_logger.h"
#include "test_transaction_manager.h"

// Tests for TransactionManager

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

    // Add two accounts with balances
    account_manager.add_account(1);
    account_manager.add_account(2);

    account_manager.find_account_by_ID(1)->set_account_balance(500.0);  // Set balance for account 1
    account_manager.find_account_by_ID(2)->set_account_balance(300.0);  // Set balance for account 2

    TransactionManager transaction_manager(1, &account_manager);

    transaction_manager.execute_transaction(1, 2, 200.0);  // Transfer 200 from account 1 to account 2

    double balance_sender = account_manager.find_account_by_ID(1)->get_account_balance();
    double balance_receiver = account_manager.find_account_by_ID(2)->get_account_balance();

    log_assertion(balance_sender == 300.0, "Test Execute Transaction Success - Sender Account");
    log_assertion(balance_receiver == 500.0, "Test Execute Transaction Success - Receiver Account");
}

void test_execute_transaction_insufficient_funds() {
    AccountManager account_manager;

    // Add two accounts with balances
    account_manager.add_account(1);
    account_manager.add_account(2);

    account_manager.find_account_by_ID(1)->set_account_balance(100.0);  // Set balance for account 1
    account_manager.find_account_by_ID(2)->set_account_balance(300.0);  // Set balance for account 2

    TransactionManager transaction_manager(1, &account_manager);

    transaction_manager.execute_transaction(1, 2, 200.0);  // Try to transfer 200 from account 1 to account 2 (insufficient funds)

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

    account_manager.find_account_by_ID(1)->set_account_balance(100.0);  // Set balance for account 1
    account_manager.find_account_by_ID(2)->set_account_balance(300.0);  // Set balance for account 2

    // Add two transactions
    transaction_manager.execute_transaction(1, 2, 50.0);
    transaction_manager.execute_transaction(3, 4, 100.0);

    // Verify that transactions can be found by their IDs
    Transaction* transaction1 = transaction_manager.find_transaction_by_ID(1);
    Transaction* transaction2 = transaction_manager.find_transaction_by_ID(2);

    log_assertion(transaction1 != nullptr, "Test Find Transaction by ID 1");
    log_assertion(transaction2 == nullptr, "Test Find Transaction by ID 2");

    // Verify that ID and amounts match
    if (transaction1) {
        log_assertion(transaction1->get_amount() == 50.0, "Test Transaction 1 Amount");
    }
}

void test_show_transaction_info() {
    AccountManager account_manager;
    TransactionManager transaction_manager(1, &account_manager);

    // Add a transaction
    transaction_manager.execute_transaction(1, 2, 50.0);

    // Verify transaction information output
    logger(info, "Testing show_transaction_info for transaction with ID 1:");
    transaction_manager.show_transaction_info(1);
}

void test_show_all_transactions() {
    AccountManager account_manager;
    TransactionManager transaction_manager(1, &account_manager);
    account_manager.add_account(1);
    account_manager.add_account(2);

    account_manager.find_account_by_ID(1)->set_account_balance(100.0);  // Set balance for account 1
    account_manager.find_account_by_ID(2)->set_account_balance(300.0);  // Set balance for account 2

    // Add multiple transactions
    transaction_manager.execute_transaction(1, 2, 50.0);
    transaction_manager.execute_transaction(2, 1, 100.0);

    // Verify all transactions output
    logger(info, "Testing show_all_transactions:");
    transaction_manager.show_all_transactions();
}
