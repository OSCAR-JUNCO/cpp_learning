#ifndef ARRAY_RECURSION_H
#define ARRAY_RECURSION_H

#include <vector>

using namespace std;

bool sorted_array(const vector<int>& vec);
bool helper_sorted_array(const vector<int>& vec, int index);

int linear_search(const vector<int>& vec, int target);
int helper_linear_search(const vector<int>& vec, int target, int index);

bool bool_linear_search(const vector<int>& vec, int target);
bool bool_helper_linear_search(const vector<int>& vec, int target, int index);

vector<int> linear_search_all(const vector<int>& vec, int target);
vector<int> helper_linear_search_all(const vector <int>& vec, int target, vector<int>& ans, int index);

vector<int> linear_search2(const vector<int>& vec, int target);
vector<int> helper_linear_search2(const vector<int>& vec, int target, int index);

int rotated_binary_search(const vector<int>& vec, int target);
int helper_rbs(const vector<int>& vec, int target, int start, int end);

#endif // ARRAY_RECURSION_H