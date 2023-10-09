#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <numeric>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> plusOne(vector<int>& digits);
vector<vector<string>> groupAnagrams(vector<string>& strs);
vector<int> anagramKey(string s);
bool isAnagram(string s, string t);
vector<int> spiralOrder(vector<vector<int>>& matrix);
bool cmp(pair<int, int> pair_a, pair<int, int> pair_b);
vector<int> topKFrequent(vector<int>& nums, int k);
vector<int> productExceptSelf(vector<int>& nums);
bool isValidSudoku(vector<vector<char>>& board);
int longestConsecutive(vector<int>& nums);
bool isValid(string s);
int evalRPN(vector<string>& tokens);

// Graphs exercises 
bool is_adjacent(std::string& first, std::string& second);
int shortestChainLen(std::string& start, std::string& target, set<std::string>& D);

void BFS(int x, int start);
void jumpingNumbers(int x);

#endif