#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <list>
#include "AccountManager.h"
#include "TransactionManager.h"
#include "IClient.h"  // ���������� ���������

class Client : public IClient {
private:
    int client_ID_;                      // ���������� ������������� �������
    std::string client_name_;            // ��� �������
    std::list<int> client_account_IDs_;  // ������ ��������������� ��������� �������
    AccountManager* account_manager_;    // ��������� �� AccountManager

public:
    // �����������
    Client(int id, const std::string& name, AccountManager* manager);

    // ���������� ������� ���������� IClient
    int get_client_ID() const override;
    std::string get_client_name() const override;
    const std::list<int>& get_client_account_IDs() const override;

    // ������ ��� ������ � ����������
    void create_account() override;
    void delete_account(int account_ID) override;

    // ������� ����� ����� ����������
    void transfer_between_accounts(TransactionManager* transaction_manager, int from_account_ID, int to_account_ID, double amount) override;

    // ������� ����� ������� �������
    void send_money_to_another_client(TransactionManager* transaction_manager, int from_account_ID, int to_account_ID, double amount) override;
};

#endif
