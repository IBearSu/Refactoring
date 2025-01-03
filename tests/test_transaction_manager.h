#ifndef TESTS_TRANSACTION_MANAGER_H
#define TESTS_TRANSACTION_MANAGER_H

// Функции для тестирования класса TransactionManager
void test_transaction_manager_all();
void test_execute_transaction_success();
void test_execute_transaction_insufficient_funds();
void test_find_transaction_by_ID();
void test_show_transaction_info();
void test_show_all_transactions();

#endif  // TESTS_TRANSACTION_MANAGER_H
