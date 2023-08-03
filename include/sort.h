#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>

using namespace std;

// Sorting algorithms

void bubble_sort(vector<int>& vec);
void helper_bubble_sort(vector<int>& vec, int row, int column);

void selection_sort(vector<int>& vec);
void helper_selection_sort(vector<int>& vec, int row, int column, int max);

vector<int> merge_sort(vector<int>& vec);
vector<int> merge(vector<int>& vec1, vector<int>& vec2);

void in_place_merge_sort(vector<int>& vec);
void helper_in_place_merge_sort(vector<int>& vec, int start, int end);
void merge_in_place(vector<int>& vec, int start, int mid, int end);

void quick_sort(vector<int>& nums);
void helper_quick_sort(vector<int>& nums, int low, int high);


#endif // SORT_H

