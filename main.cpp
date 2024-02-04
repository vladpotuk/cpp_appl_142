#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include "Wallet.h"
#include "Expense.h"
#include "FinanceManager.h"

void printMenu() {
    std::cout << "===== Управління персональними фінансами =====" << std::endl;
    std::cout << "1. Додати гаманець" << std::endl;
    std::cout << "2. Додати витрату" << std::endl;
    std::cout << "3. Розрахувати тижневі витрати" << std::endl;
    std::cout << "4. Розрахувати місячні витрати" << std::endl;
    std::cout << "5. Показати ТОП-3 категорій за тиждень" << std::endl;
    std::cout << "6. Показати ТОП-3 категорій за місяць" << std::endl;
    std::cout << "7. Зберегти звіти у файл" << std::endl;
    std::cout << "8. Вийти" << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << "Виберіть опцію: ";
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

            std::cout << "Введіть назву гаманця: ";
            std::cin >> walletName;
            std::cout << "Введіть початковий баланс: ";
            std::cin >> initialBalance;

            Wallet wallet(walletName, initialBalance);
            manager.addWallet(wallet);

            std::cout << "Гаманець '" << walletName << "' успішно додано з початковим балансом: $" << initialBalance << std::endl;
            break;
        }

        case 2: {
            std::string category;
            double amount;
            std::cout << "Введіть категорію витрати: ";
            std::cin >> category;
            std::cout << "Введіть суму витрати: ";
            std::cin >> amount;
            time_t timestamp = time(nullptr);
            Expense expense(category, amount, timestamp);
            manager.addExpense(expense);
            break;
        }

        case 3: {
            time_t startDate;
            std::cout << "Введіть дату початку для тижневих витрат (у форматі timestamp): ";
            std::cin >> startDate;
            double weeklyExpense = manager.calculateWeeklyExpense(startDate);
            std::cout << "Тижневі витрати: $" << weeklyExpense << std::endl;
            break;
        }

        case 4: {
            time_t startDate;
            std::cout << "Введіть дату початку для місячних витрат (у форматі timestamp): ";
            std::cin >> startDate;
            double monthlyExpense = manager.calculateMonthlyExpense(startDate);
            std::cout << "Місячні витрати: $" << monthlyExpense << std::endl;
            break;
        }

        case 5: {
            time_t startDate;
            std::cout << "Введіть дату початку для тижневих витрат (у форматі timestamp): ";
            std::cin >> startDate;
            auto top3WeeklyCategories = manager.getTop3WeeklyCategories(startDate);
            std::cout << "ТОП-3 категорій за тиждень:" << std::endl;
            for (const auto& pair : top3WeeklyCategories) {
                std::cout << pair.first << ": $" << pair.second << std::endl;
            }
            break;
        }

        case 6: {
            time_t startDate;
            std::cout << "Введіть дату початку для місячних витрат (у форматі timestamp): ";
            std::cin >> startDate;
            auto top3MonthlyCategories = manager.getTop3MonthlyCategories(startDate);
            std::cout << "ТОП-3 категорій за місяць:" << std::endl;
            for (const auto& pair : top3MonthlyCategories) {
                std::cout << pair.first << ": $" << pair.second << std::endl;
            }
            break;
        }

        case 7: {
            std::string filename;
            std::cout << "Введіть назву файлу для збереження звітів: ";
            std::cin >> filename;
            manager.saveReportsToFile(filename);
            break;
        }

        case 8: {
            std::cout << "Завершення програми..." << std::endl;
            break;
        }

        default:
            std::cout << "Невірний вибір. Будь ласка, виберіть дійсну опцію." << std::endl;
        }
    } while (choice != 8);

    return 0;
}
