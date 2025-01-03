#include "Account.h"

// Используем список инициализации для инициализации членов класса
Account::Account(int account_ID, int account_owner_ID, double account_balance, const std::string& account_type)
    : account_ID_(account_ID),
    account_owner_ID_(account_owner_ID),
    account_balance_(account_balance),
    account_type_(account_type) {}

// Получить ID счета
int Account::get_account_ID() const {
    return account_ID_;
}

// Получить ID владельца счета
int Account::get_account_owner_ID() const {
    return account_owner_ID_;
}

// Получить баланс счета
double Account::get_account_balance() const {
    return account_balance_;
}

// Получить тип счета (возвращаем ссылку на строку для оптимизации)
const std::string& Account::get_account_type() const {
    return account_type_;
}

// Установить баланс счета
void Account::set_account_balance(double amount) {
    account_balance_ = amount;
}
