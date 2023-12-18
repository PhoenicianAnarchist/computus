#include <algorithm> // std::max
#include <iostream>

#include <cmath> // std::floor
#include <cstdlib> // std::atoi

std::string ordinal(const int n) {
  int r = n % 10;
  switch (r) {
    case 1: return "st";
    case 2: return "nd";
    case 3: return "rd";
    default: return "th";
  }
}

int main(int argc, const char *argv[]) {
  if (argc < 2) {
    std::cerr << "usage: " << argv[0] << " <year>\n" << std::endl;
    return 1;
  }

  int year = std::atoi(argv[1]);

  // Gauss's Easter Algorithm
  int a = year % 19;
  int b = year % 4;
  int c = year % 7;
  int k = std::floor(year / 100);
  int p = std::floor((13 + (8 * k)) / 25);
  int q = std::floor(k / 4);
  int m = (15 - p + k - q) % 30;
  int n = (4 + k - q) % 7;
  int d = ((19 * a) + m) % 30;
  int e = ((2 * b) + (4 * c) + (6 * d) + n) % 7;
  int mar = 22 + d + e;
  int apr = d + e - 9;

  std::cout << "In the year " << year << " Easter Sunday will fall on:\n";

  if (0 < mar && mar < 32) {
    std::cout << " " << mar << ordinal(mar) << " of March\n";
  } else {
    std::cout << " " << apr << ordinal(mar) << " of April\n";
  }

  return 0;
}
