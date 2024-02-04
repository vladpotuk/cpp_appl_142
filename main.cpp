#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include "Wallet.h"
#include "Expense.h"
#include "FinanceManager.h"

void printMenu() {
    std::cout << "===== ��������� ������������� ��������� =====" << std::endl;
    std::cout << "1. ������ ��������" << std::endl;
    std::cout << "2. ������ �������" << std::endl;
    std::cout << "3. ����������� ������ �������" << std::endl;
    std::cout << "4. ����������� ����� �������" << std::endl;
    std::cout << "5. �������� ���-3 �������� �� �������" << std::endl;
    std::cout << "6. �������� ���-3 �������� �� �����" << std::endl;
    std::cout << "7. �������� ���� � ����" << std::endl;
    std::cout << "8. �����" << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << "������� �����: ";
}

int main() {
    system("chcp 1251");
    system("cls");
    FinanceManager manager;
    int choice;

    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string walletName;
            double initialBalance;

            std::cout << "������ ����� �������: ";
            std::cin >> walletName;
            std::cout << "������ ���������� ������: ";
            std::cin >> initialBalance;

            Wallet wallet(walletName, initialBalance);
            manager.addWallet(wallet);

            std::cout << "�������� '" << walletName << "' ������ ������ � ���������� ��������: $" << initialBalance << std::endl;
            break;
        }

        case 2: {
            std::string category;
            double amount;
            std::cout << "������ �������� �������: ";
            std::cin >> category;
            std::cout << "������ ���� �������: ";
            std::cin >> amount;
            time_t timestamp = time(nullptr);
            Expense expense(category, amount, timestamp);
            manager.addExpense(expense);
            break;
        }

        case 3: {
            time_t startDate;
            std::cout << "������ ���� ������� ��� �������� ������ (� ������ timestamp): ";
            std::cin >> startDate;
            double weeklyExpense = manager.calculateWeeklyExpense(startDate);
            std::cout << "������ �������: $" << weeklyExpense << std::endl;
            break;
        }

        case 4: {
            time_t startDate;
            std::cout << "������ ���� ������� ��� ������� ������ (� ������ timestamp): ";
            std::cin >> startDate;
            double monthlyExpense = manager.calculateMonthlyExpense(startDate);
            std::cout << "̳���� �������: $" << monthlyExpense << std::endl;
            break;
        }

        case 5: {
            time_t startDate;
            std::cout << "������ ���� ������� ��� �������� ������ (� ������ timestamp): ";
            std::cin >> startDate;
            auto top3WeeklyCategories = manager.getTop3WeeklyCategories(startDate);
            std::cout << "���-3 �������� �� �������:" << std::endl;
            for (const auto& pair : top3WeeklyCategories) {
                std::cout << pair.first << ": $" << pair.second << std::endl;
            }
            break;
        }

        case 6: {
            time_t startDate;
            std::cout << "������ ���� ������� ��� ������� ������ (� ������ timestamp): ";
            std::cin >> startDate;
            auto top3MonthlyCategories = manager.getTop3MonthlyCategories(startDate);
            std::cout << "���-3 �������� �� �����:" << std::endl;
            for (const auto& pair : top3MonthlyCategories) {
                std::cout << pair.first << ": $" << pair.second << std::endl;
            }
            break;
        }

        case 7: {
            std::string filename;
            std::cout << "������ ����� ����� ��� ���������� ����: ";
            std::cin >> filename;
            manager.saveReportsToFile(filename);
            break;
        }

        case 8: {
            std::cout << "���������� ��������..." << std::endl;
            break;
        }

        default:
            std::cout << "������� ����. ���� �����, ������� ����� �����." << std::endl;
        }
    } while (choice != 8);

    return 0;
}
