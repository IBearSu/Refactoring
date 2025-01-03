#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>

class Account {
private:
    int account_ID_;                  // Уникальный идентификатор счета
    int account_owner_ID_;             // ID владельца счета
    double account_balance_;           // Баланс счета
    std::string account_type_;         // Тип счета (например, депозитный или кредитный)

public:
    Account(int account_ID, int account_owner_ID, double account_balance, const std::string& account_type);

    // Получить ID счета
    int get_account_ID() const;

    // Получить ID владельца счета
    int get_account_owner_ID() const;

    // Получить баланс счета
    double get_account_balance() const;

    // Получить тип счета
    const std::string& get_account_type() const;

    // Установить баланс счета
    void set_account_balance(double amount);
};

#endif  // ACCOUNT_H
