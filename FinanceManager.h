#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include "Wallet.h"
#include "Expense.h"
#include <vector>
#include <map>
#include <string>
#include <ctime>

class FinanceManager {
private:
    std::vector<Wallet> wallets;
    std::vector<Expense> expenses;

public:
    void addWallet(Wallet wallet);
    void addExpense(Expense expense);
    double calculateWeeklyExpense(time_t startDate) const;
    double calculateMonthlyExpense(time_t startDate) const;
    std::map<std::string, double> getTop3WeeklyCategories(time_t startDate) const;
    std::map<std::string, double> getTop3MonthlyCategories(time_t startDate) const;
    void saveReportsToFile(std::string filename) const;
};

#endif
