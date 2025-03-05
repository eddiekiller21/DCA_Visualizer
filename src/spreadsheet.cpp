#include "spreadsheet.h"
#include <fstream>
#include <sstream>
#include <iomanip>

Spreadsheet::Spreadsheet(const std::string &filename) : filename(filename)
{
    load();
    calculateTotals();
}

void Spreadsheet::load()
{
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;
        while (std::getline(ss, cell, ','))
        {
            row.push_back(cell);
        }
        data.push_back(row);
    }
}

void Spreadsheet::calculateTotals()
{
    if (data.size() > 1)
    { // Skip header
        for (size_t i = 1; i < data.size(); ++i)
        {
            totalInvested += std::stod(data[i][1]);
            totalBTC += std::stod(data[i][2]);
        }
    }
}

void Spreadsheet::addHeader()
{
    if (data.empty())
    {
        data.push_back({"Date", "Amount Spent ($)", "BTC Purchased (BTC)", "Bitcoin Price ($)", "Total Amount Invested ($)", "Total BTC Purchased (BTC)", "DCA ($ per BTC)"});
    }
}

void Spreadsheet::addEntry(const std::string &date, const std::string &amountSpent, const std::string &btcPrice)
{
    double amount = std::stod(amountSpent);
    double price = std::stod(btcPrice);
    double btcPurchased = amount / price;

    totalInvested += amount;
    totalBTC += btcPurchased;
    double dca = totalInvested / totalBTC;

    std::vector<std::string> entry = {
        date,
        amountSpent,
        std::to_string(btcPurchased),
        btcPrice,
        std::to_string(totalInvested),
        std::to_string(totalBTC),
        std::to_string(dca)};

    data.push_back(entry);
}

void Spreadsheet::save()
{
    std::ofstream file(filename);
    for (const auto &row : data)
    {
        for (size_t i = 0; i < row.size(); ++i)
        {
            file << row[i];
            if (i < row.size() - 1)
            {
                file << ",";
            }
        }
        file << "\n";
    }
}