#include "FinanceManager.h"
#include <fstream>
#include <iostream>

void FinanceManager::addWallet(Wallet wallet) {
    wallets.push_back(wallet);
}

void FinanceManager::addExpense(Expense expense) {
    expenses.push_back(expense);
}

double FinanceManager::calculateWeeklyExpense(time_t startDate) const {
    double weeklyExpense = 0.0;
    for (const auto& exp : expenses) {
        if (exp.getTimestamp() >= startDate) {
            weeklyExpense += exp.getAmount();
        }
    }
    return weeklyExpense;
}

double FinanceManager::calculateMonthlyExpense(time_t startDate) const {
    double monthlyExpense = 0.0;
    for (const auto& exp : expenses) {
        if (exp.getTimestamp() >= startDate) {
            monthlyExpense += exp.getAmount();
        }
    }
    return monthlyExpense;
}

std::map<std::string, double> FinanceManager::getTop3WeeklyCategories(time_t startDate) const {
    std::map<std::string, double> weeklyCategories;
    for (const auto& exp : expenses) {
        if (exp.getTimestamp() >= startDate) {
            weeklyCategories[exp.getCategory()] += exp.getAmount();
        }
    }

    std::map<std::string, double> top3WeeklyCategories;
    int count = 0;
    for (const auto& categoryAmount : weeklyCategories) {
        top3WeeklyCategories[categoryAmount.first] = categoryAmount.second;
        count++;
        if (count == 3) {
            break;
        }
    }
    return top3WeeklyCategories;
}

std::map<std::string, double> FinanceManager::getTop3MonthlyCategories(time_t startDate) const {
    std::map<std::string, double> monthlyCategories;
    for (const auto& exp : expenses) {
        if (exp.getTimestamp() >= startDate) {
            monthlyCategories[exp.getCategory()] += exp.getAmount();
        }
    }

    std::map<std::string, double> top3MonthlyCategories;
    int count = 0;
    for (const auto& categoryAmount : monthlyCategories) {
        top3MonthlyCategories[categoryAmount.first] = categoryAmount.second;
        count++;
        if (count == 3) {
            break;
        }
    }
    return top3MonthlyCategories;
}

void FinanceManager::saveReportsToFile(std::string filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    file << "Weekly Expenses:" << std::endl;
    file << "================" << std::endl;
    // Calculate and write weekly expenses

    file << "Monthly Expenses:" << std::endl;
    file << "=================" << std::endl;
    // Calculate and write monthly expenses

    file.close();
}
