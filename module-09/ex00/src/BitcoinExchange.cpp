#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
  _databaseFile.open(DATABASE_FILENAME);

  if (!_databaseFile.is_open()) {
    throw std::runtime_error("data.csv not found");
  }

  {
    std::string firstLine;
    std::getline(_databaseFile, firstLine);
    if (firstLine != "date,exchange_rate") {
      throw std::runtime_error("Invalid data.csv format");
    }
  }

  {
    std::string line;
    while (getline(_databaseFile, line)) {
      std::stringstream ss(line);
      std::string date;
      std::string exchangeRate;
      std::getline(ss, date, ',');
      date = date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2);
      unsigned int dateInt = std::stoul(date);
      std::getline(ss, exchangeRate, ',');
      _database[dateInt] = std::stod(exchangeRate);
    }
  }

  _databaseFile.close();
}

double BitcoinExchange::getExchangeRate(const std::string &date) const {
  unsigned int dateInt =
      std::stoul(date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2));

  try {
    return _database.at(dateInt);
  } catch (std::out_of_range &e) {
    while (dateInt > 0) {
      dateInt--;
      try {
        return _database.at(dateInt);
      } catch (std::out_of_range &e) {
        continue;
      }
    }
  }
  return 0;
}

BitcoinExchange::~BitcoinExchange() {}
