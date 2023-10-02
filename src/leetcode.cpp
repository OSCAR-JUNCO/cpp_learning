#include "leetcode.h"

std::vector<std::string> letterCombinations(std::string digits){
    // Empty case
    if (digits == "") {
        return {};
    }

    // Create a map with the digits and the corresponding letters
    std::unordered_map<char, std::string> keyboard;
    keyboard['2'] = "abc";
    keyboard['3'] = "def";
    keyboard['4'] = "ghi";
    keyboard['5'] = "jkl";
    keyboard['6'] = "mno";
    keyboard['7'] = "pqrs";
    keyboard['8'] = "tuv";
    keyboard['9'] = "wxyz";
    
    // Create the answer vector
    std::vector<std::string> ans;
    letterCombinations_helper(keyboard, ans, "", digits);
    return ans;

}
void letterCombinations_helper(std::unordered_map<char, std::string>& keyboard, std::vector<std::string>& ans, std::string processed, std::string unprocessed){
    // Base condition
    if (unprocessed.size() == 0) {
        ans.push_back(processed);
        return;
    }

    std::string current_digit = keyboard[unprocessed[0]];
    for (char letter: current_digit) {
        letterCombinations_helper(keyboard, ans, processed+letter, unprocessed.substr(1));
    }
}