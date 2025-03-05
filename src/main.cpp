#include <iostream>
#include <string>
#include "spreadsheet.h"

int main()
{
    Spreadsheet sheet("btc_dca.csv");

    std::string date, amountSpent, btcPrice;
    std::cout << "Enter the following details:\n";

    std::cout << "Date: ";
    std::getline(std::cin, date);

    std::cout << "Amount Spent ($): ";
    std::getline(std::cin, amountSpent);

    std::cout << "Bitcoin Price ($): ";
    std::getline(std::cin, btcPrice);

    sheet.addHeader();
    sheet.addEntry(date, amountSpent, btcPrice);
    sheet.save();

    std::cout << "Entry added successfully.\n";
    return 0;
}