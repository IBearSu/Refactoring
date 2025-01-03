#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>

class Account {
private:
    int account_ID_;                  // ���������� ������������� �����
    int account_owner_ID_;             // ID ��������� �����
    double account_balance_;           // ������ �����
    std::string account_type_;         // ��� ����� (��������, ���������� ��� ���������)

public:
    Account(int account_ID, int account_owner_ID, double account_balance, const std::string& account_type);

    // �������� ID �����
    int get_account_ID() const;

    // �������� ID ��������� �����
    int get_account_owner_ID() const;

    // �������� ������ �����
    double get_account_balance() const;

    // �������� ��� �����
    const std::string& get_account_type() const;

    // ���������� ������ �����
    void set_account_balance(double amount);
};

#endif  // ACCOUNT_H
