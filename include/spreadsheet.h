#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <string>
#include <vector>

class Spreadsheet
{
public:
    Spreadsheet(const std::string &filename);
    void addEntry(const std::string &date, const std::string &amountSpent, const std::string &btcPrice);
    void save();
    void addHeader(); // Move addHeader to public

private:
    std::string filename;
    std::vector<std::vector<std::string>> data;
    double totalInvested = 0.0;
    double totalBTC = 0.0;

    void load();
    void calculateTotals();
};

#endif // SPREADSHEET_H