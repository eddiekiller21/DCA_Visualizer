#include <iostream>
#include <string>
#include "spreadsheet.h"

int main()
{
    Spreadsheet sheet("btc_dca.csv");

    while (true)
    {
        std::string choice;
        std::cout << "Would you like to remove the last entry, make a new entry, or exit? (remove/new/exit): ";
        std::getline(std::cin, choice);

        if (choice == "remove")
        {
            sheet.removeLastEntry();
            sheet.save();
            std::cout << "Last entry removed.\n";
        }
        else if (choice == "exit")
        {
            break;
        }
        else if (choice == "new")
        {
            std::string date, amountSpent, btcPurchased;
            std::cout << "Enter the following details:\n";

            std::cout << "Date (MM-DD-YYYY): ";
            std::getline(std::cin, date);

            std::cout << "Amount Spent ($): ";
            std::getline(std::cin, amountSpent);

            std::cout << "BTC Purchased (BTC): ";
            std::getline(std::cin, btcPurchased);

            sheet.addHeader();
            sheet.addEntry(date, amountSpent, btcPurchased);
            sheet.save();

            std::cout << "Entry added successfully.\n";
            std::cout << "Date: " << date << "\n";
            std::cout << "Amount Spent ($): " << amountSpent << "\n";
            std::cout << "BTC Purchased (BTC): " << btcPurchased << "\n";
        }
        else
        {
            std::cout << "Invalid choice. Please enter 'remove', 'new', or 'exit'.\n";
        }
    }

    return 0;
}