#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include <iostream>
#include "Account.h"
#include <list>
#include "IAccountManager.h"  // ���������� ��������� IAccountManager

class AccountManager: public IAccountManager {
private:
    std::list<Account*> accounts_list_;   // ������ ������
    int next_account_ID_;                  // ��������� ��������� ID �����

public:
    AccountManager();
    AccountManager(int next_account_ID);

    std::list<Account*>* get_accounts_list() override; // return reference to this list, not a copy
    int get_next_account_ID() const override;
    // �������� ����� ����
    void add_account(int account_owner_ID) override;
    // ������� ���� �� ��� ID
    void delete_account(int account_ID) override;
    // ����� ���� �� ��� ID
    Account* find_account_by_ID(int account_ID) const override;
    void show_account_details(int account_ID) const override;
    // �������� ��� �����
    void show_all_accounts() const override;
    void deposit(int account_ID, double amount) override;
    void withdraw(int account_ID, double amount) override;
};


#endif 