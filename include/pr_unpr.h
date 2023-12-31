#ifndef PR_UNPR_H
#define PR_UNPR_H

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

string skip_char(const string str, char c);
void helper_sc(string& up, const string p, char c);

string skip_string(const string str, string skip);
void helper_ss(string& up, const string p, string skip);

string skip_string_that_is_not(const string str, string skip, string not_skip);
void helper_sstin(string& up, const string p, string skip, string not_skip);

void print_subseqs(string str);
void helper_ps(string p, string up);

vector<string> subseqs(string str);
void helper_s(vector<string>& ans, string p, string up);

vector<string> subseqs_direct(string p, string up);

vector<vector<int>> subset_iteration(const vector<int>& nums);

vector<vector<int>> subset_duplicate(vector<int>& nums);

// Permutations
void print_permutations(string p, string up);
vector<string> permutations(string p, string up);
int count_permutations(string p, string up);

// Dice combinations
std::vector<std::string> dice_combinations(int digit);
void dice_combinations_helper(std::vector<std::string>& ans, std::string processed, int unprocessed);


#endif // PR_UNPR_H
