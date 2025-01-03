#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store account information
typedef struct Account {
    int accountNumber;
    double balance;
    char type[20]; // Deposit or credit
} Account;

// Structure to store client information
typedef struct Client {
    int clientID;
    char name[50];
    Account* accounts[10]; // Maximum 10 accounts per client
    int accountCount;
} Client;

// Structure to store transaction information
typedef struct Transaction {
    int transactionID;
    int senderAccount;
    int receiverAccount;
    double amount;
} Transaction;

// Global variables
Client* clients[100];       // Maximum 100 clients in the system
int clientCount = 0;
Transaction* transactions[1000]; // Maximum 1000 transactions
int transactionCount = 0;

// Function prototypes
void addClient();
void createAccount(int clientID);
void viewClient(int clientID);
void performTransaction();
void viewTransactionHistory();
void depositToAccount(int clientID);
void viewAllClients();
Client* findClientByID(int clientID);
Account* findAccountByNumber(int accountNumber);

// Main menu of the program
void menu() {
    int choice;
    while (1) {
        printf("\n----- BANKING SYSTEM -----\n");
        printf("1. Register a new client\n");
        printf("2. Create an account for a client\n");
        printf("3. View client information\n");
        printf("4. Perform a transaction\n");
        printf("5. View transaction history\n");
        printf("6. Deposit to an account\n");
        printf("7. View all clients\n");
        printf("8. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addClient();
            break;
        case 2: {
            int clientID;
            printf("Enter client ID: ");
            scanf("%d", &clientID);
            createAccount(clientID);
            break;
        }
        case 3: {
            int clientID;
            printf("Enter client ID: ");
            scanf("%d", &clientID);
            viewClient(clientID);
            break;
        }
        case 4:
            performTransaction();
            break;
        case 5:
            viewTransactionHistory();
            break;
        case 6: {
            int clientID;
            printf("Enter client ID for deposit: ");
            scanf("%d", &clientID);
            depositToAccount(clientID);
            break;
        }
        case 7:
            viewAllClients();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Invalid option, please try again.\n");
        }
    }
}

// Register a new client
void addClient() {
    Client* newClient = (Client*)malloc(sizeof(Client));
    printf("Enter client ID: ");
    scanf("%d", &newClient->clientID);

    // Use fgets for client name input to handle spaces
    printf("Enter client name: ");
    getchar(); // Consume newline left by previous input
    fgets(newClient->name, sizeof(newClient->name), stdin);

    // Remove trailing newline character if present
    size_t len = strlen(newClient->name);
    if (len > 0 && newClient->name[len - 1] == '\n') {
        newClient->name[len - 1] = '\0';
    }

    newClient->accountCount = 0;
    clients[clientCount++] = newClient;
    printf("Client %s successfully added with ID %d.\n", newClient->name, newClient->clientID);
}

// Create a new account for a client
void createAccount(int clientID) {
    Client* client = findClientByID(clientID);
    if (client == NULL) {
        printf("Client with ID %d not found.\n", clientID);
        return;
    }

    if (client->accountCount >= 10) {
        printf("Client already has the maximum number of accounts.\n");
        return;
    }

    Account* newAccount = (Account*)malloc(sizeof(Account));
    printf("Enter account number: ");
    scanf("%d", &newAccount->accountNumber);

    // Initialize account type string
    memset(newAccount->type, 0, sizeof(newAccount->type));

    // Use safer input for account type
    printf("Enter account type (deposit/credit): ");
    scanf("%19s", newAccount->type);  // Input no more than 19 characters

    newAccount->balance = 0.0; // Initial balance
    client->accounts[client->accountCount++] = newAccount;

    printf("Account %d successfully created for client %s.\n", newAccount->accountNumber, client->name);
}

// Deposit funds to an account
void depositToAccount(int clientID) {
    Client* client = findClientByID(clientID);
    if (client == NULL) {
        printf("Client with ID %d not found.\n", clientID);
        return;
    }

    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    Account* account = findAccountByNumber(accountNumber);
    if (account == NULL) {
        printf("Account number %d not found.\n", accountNumber);
        return;
    }

    double amount;
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    if (amount < 0) {
        printf("Amount cannot be negative.\n");
        return;
    }

    account->balance += amount;
    printf("Successfully deposited %.2f to account %d.\n", amount, accountNumber);
}

// Find a client by their ID
Client* findClientByID(int clientID) {
    for (int i = 0; i < clientCount; i++) {
        if (clients[i]->clientID == clientID)
            return clients[i];
    }
    return NULL;
}

/// View client information and their accounts
void viewClient(int clientID) {
    Client* client = findClientByID(clientID);
    if (client == NULL) {
        printf("Client with ID %d not found.\n", clientID);
        return;
    }

    printf("\n----- CLIENT INFORMATION -----\n");
    printf("Client ID: %d\n", client->clientID);
    printf("Client Name: %s\n", client->name);
    printf("Number of Accounts: %d\n", client->accountCount);

    for (int i = 0; i < client->accountCount; i++) {
        Account* account = client->accounts[i];
        printf("  Account %d - Type: %s - Balance: %.2f\n", account->accountNumber, account->type, account->balance);
    }
}

// View information of all registered clients
void viewAllClients() {
    printf("\n----- ALL CLIENTS -----\n");
    for (int i = 0; i < clientCount; i++) {
        printf("Client ID: %d - Name: %s - Number of Accounts: %d\n",
            clients[i]->clientID, clients[i]->name, clients[i]->accountCount);
    }
}

// Find an account by its number
Account* findAccountByNumber(int accountNumber) {
    for (int i = 0; i < clientCount; i++) {
        for (int j = 0; j < clients[i]->accountCount; j++) {
            if (clients[i]->accounts[j]->accountNumber == accountNumber)
                return clients[i]->accounts[j];
        }
    }
    return NULL;
}

// Perform a transaction between two accounts
void performTransaction() {
    int sender, receiver;
    double amount;

    printf("Enter sender account number: ");
    scanf("%d", &sender);
    printf("Enter receiver account number: ");
    scanf("%d", &receiver);
    printf("Enter transfer amount: ");
    scanf("%lf", &amount);

    Account* senderAccount = findAccountByNumber(sender);
    Account* receiverAccount = findAccountByNumber(receiver);

    if (senderAccount == NULL || receiverAccount == NULL) {
        printf("Sender or receiver account not found.\n");
        return;
    }

    if (senderAccount->balance < amount) {
        printf("Insufficient funds in sender's account.\n");
        return;
    }

    senderAccount->balance -= amount;
    receiverAccount->balance += amount;

    Transaction* newTransaction = (Transaction*)malloc(sizeof(Transaction));
    newTransaction->transactionID = ++transactionCount;
    newTransaction->senderAccount = sender;
    newTransaction->receiverAccount = receiver;
    newTransaction->amount = amount;
    transactions[transactionCount - 1] = newTransaction;

    printf("Transaction successfully completed!\n");
}

// View the history of all transactions
void viewTransactionHistory() {
    printf("\n----- TRANSACTION HISTORY -----\n");
    for (int i = 0; i < transactionCount; i++) {
        printf("Transaction ID: %d - Sender: %d - Receiver: %d - Amount: %.2f\n",
            transactions[i]->transactionID, transactions[i]->senderAccount,
            transactions[i]->receiverAccount, transactions[i]->amount);
    }
}

int main() {
    menu();
    return 0;
}
