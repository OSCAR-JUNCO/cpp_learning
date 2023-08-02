#ifndef PATTERNS_H
#define PATTERNS_H

#include <iostream>
#include <vector>

using namespace std;

void triangle_one(int row, int column);
void triangle_two(int row, int column);

void bubble_sort(vector<int>& vec);
void helper_bubble_sort(vector<int>& vec, int row, int column);

void selection_sort(vector<int>& vec);
void helper_selection_sort(vector<int>& vec, int row, int column, int max);

vector<int> merge_sort(vector<int>& vec);
vector<int> merge(vector<int>& vec1, vector<int>& vec2);

void in_place_merge_sort(vector<int>& vec);
void helper_in_place_merge_sort(vector<int>& vec, int start, int end);
void merge_in_place(vector<int>& vec, int start, int mid, int end);

#endif //PATTERNS_H 