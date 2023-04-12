#ifndef MODULE_09_BITCOINEXCHANGE_HPP
#define MODULE_09_BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

#define DATABASE_FILENAME "data.csv"

class BitcoinExchange {
 public:
  BitcoinExchange();
  ~BitcoinExchange();

  double getExchangeRate(const std::string &date) const;

 private:
  std::ifstream _databaseFile;
  std::map<unsigned int, double> _database;
};

#endif  // MODULE_09_BITCOINEXCHANGE_HPP
