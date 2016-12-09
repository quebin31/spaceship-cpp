//
// Created by kevin on 7/12/16.
//

#include <iostream>
#include "int_to_string.h"

std::string int_to_string(int number)
{
  std::vector<char> chars;
  char c;
  while (number >= 10)
  {
    c = (number % 10) + 48;
    number = number/10;
    chars.push_back(c);
  }
  c = number + 48;
  chars.push_back(c);

  std::string converted = "";
  while (!chars.empty())
  {
    c = chars.back();
    converted.push_back(c);
    chars.pop_back();
  }
  return converted;
}