#include "BitcoinExchange.hpp"

static bool isValidDate(const std::string &date) {
  if (date.size() != 11) {
    return false;
  }
  if (date[4] != '-' || date[7] != '-') {
    return false;
  }
  for (int i = 0; i < 11; i++) {
    if (i == 4 || i == 7 || i == 10) {
      continue;
    }
    if (!isdigit(date[i])) {
      return false;
    }
  }
  return true;
}

static void isValidDouble(const std::string &value) {
  int dotCount = 0;

  for (std::size_t i = 0; i < value.size(); i++) {
    if (value[i] == '.' && dotCount == 0) {
      dotCount++;
      continue;
    }
    if (!isdigit(value[i]) && value[0] != '-') {
      throw std::runtime_error("Error: bad input => " + value);
    }
  }

  double ret = std::stod(value);
  if (ret < 0) {
    throw std::runtime_error("Error: not a positive number.");
  } else if (ret > 1000) {
    throw std::runtime_error("Error: too large as number.");
  }
}

int main(int argc, char **argv) {
  if (argc == 2) {
    try {
      BitcoinExchange btcExchange;
      std::ifstream file(argv[1]);

      // Check if the file is open
      if (!file.is_open()) {
        std::cerr << "Input file not found" << std::endl;
        return EXIT_FAILURE;
      }

      // Check if the first line is valid
      {
        std::string line;
        std::getline(file, line);
        if (line != "date | value") {
          std::cerr << "Invalid input file format" << std::endl;
          return EXIT_FAILURE;
        }
      }

      // Go through the file line by line, and print the exchange rate
      {
        std::string line;
        while (getline(file, line)) {
          std::stringstream ss(line);
          std::string date, value;
          std::getline(ss, date, '|');
          if (isValidDate(date) == false) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
          }
          date.erase(date.size() - 1);
          std::getline(ss, value, '|');
          value.erase(0, 1);
          try {
            isValidDouble(value);  // throw if invalid
          } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            continue;
          }
          double newValue =
              btcExchange.getExchangeRate(date) * std::stod(value);
          std::cout << date << " => " << value << " = " << newValue
                    << std::endl;
        }
      }
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  }
  std::cerr << "Usage: ./btc <input_file>" << std::endl;
  return EXIT_FAILURE;
}
