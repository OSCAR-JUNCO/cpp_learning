#ifndef LEETCODE_H
#define LEETCODE_H

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

// 17. Letter combinations of a phone number
std::vector<std::string> letterCombinations(std::string digits);
void letterCombinations_helper(std::unordered_map<char, std::string>& keyboard, std::vector<std::string>& ans, std::string processed, std::string unprocessed);

#endif // LEETCODE_H