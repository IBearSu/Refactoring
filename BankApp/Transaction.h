#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>

// Forward declaration for TransactionManager
class TransactionManager;

class Transaction {
private:
    int transaction_ID_;               // Unique transaction identifier
    int sender_account_ID_;            // Sender's account ID
    int receiver_account_ID_;          // Receiver's account ID
    double amount_;                    // Transaction amount
    TransactionManager* transaction_manager_;  // Pointer to the transaction manager

public:
    // Constructor
    Transaction(int transaction_ID, int sender_account_ID, int receiver_account_ID, double amount, TransactionManager* manager);

    // Getter methods
    int get_transaction_ID() const;
    int get_sender_account_ID() const;
    int get_receiver_account_ID() const;
    double get_amount() const;

    // Getter for transaction_manager_
    TransactionManager* get_transaction_manager() const;
};

#endif  // TRANSACTION_H
