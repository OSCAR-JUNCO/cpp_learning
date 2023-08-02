#include "patterns.h"

void triangle_one(int row, int column) {
    if (row == 0) return;

    if (column < row) {
        cout << "*";
        triangle_one(row, ++column);
    } else {
        cout << endl;
        triangle_one(--row, 0);
    }
}

void triangle_two(int row, int column) {
    if (row == 0) return;
    if (column < row) {
        triangle_two(row, column+1);
        cout << "*";
    } else {
        triangle_two(row-1, 0);
        cout << endl;
    }
}


void bubble_sort(vector<int>& vec) {
    int column = 0;
    int row = vec.size() - 1;
    helper_bubble_sort(vec, row, column);
}

void helper_bubble_sort(vector<int>& vec, int row, int column) {
    if (row == 0) return;
    
    if (column < row) {
        // Swap
        if(vec[column] > vec[column+1]) {
            int first = vec[column];
            vec[column] = vec[column+1];
            vec[column+1] = first;
        }
        helper_bubble_sort(vec, row, column+1);
    } else {
        helper_bubble_sort(vec, row-1, 0);
    }
}


void selection_sort(vector<int>& vec) {
    int row = vec.size();
    int column = 0;
    int index_max = 0;
    helper_selection_sort(vec, row, column, index_max);
}

void helper_selection_sort(vector<int>& vec, int row, int column, int index_max) {
    if (row == 0) {
        return;
    }
    
    if (column < row) {
        if(vec[column] > vec[index_max]) {
            helper_selection_sort(vec, row, column+1, column);
        } else {
            helper_selection_sort(vec, row, column+1, index_max);
        }
    } else {
        // Swap
        int temp = vec[index_max];
        vec[index_max] = vec[row-1];
        vec[row-1] = temp;
        helper_selection_sort(vec, row-1, 0, 0);
    }
}


vector<int> merge_sort(vector<int>& vec) {
    if (vec.size() == 1) {
        return vec;
    }

    int mid = vec.size()/2;
    vector<int> first(vec.begin(), vec.begin()+mid);
    vector<int> second(vec.begin()+mid, vec.end());

    vector<int> first_half = merge_sort(first);
    vector<int> second_half = merge_sort(second);

    return merge(first_half, second_half); 
}

vector<int> merge(vector<int>& first, vector<int>& second) {
    int size {first.size()+second.size()};
    vector<int> mix(size);
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < first.size() && j < second.size()) {
        if (first[i] < second[j]) {
            mix[k] = first[i];
            i++;

        } else {
            mix[k] = second[j];
            j++;
        }
        ++k;
    }

    // It may be possible that one of the arrays is not completely iterated
    // Copy the remaining elements
    while(i < first.size()) {
        mix[k] = first[i];
        ++i;
        ++k;
    }

    while(j < second.size()) {
        mix[k] = second[j];
        ++j;
        ++k;
    }
    return mix;
}


void in_place_merge_sort(vector<int>& vec){
    int start = 0;
    int end = vec.size();
    helper_in_place_merge_sort(vec, start, end);
}

void helper_in_place_merge_sort(vector<int>& vec, int start, int end){
    if (end - start == 1){
        return;
    }
    
    int mid = (start+end)/2;

    helper_in_place_merge_sort(vec, start, mid);
    helper_in_place_merge_sort(vec, mid, end);

    merge_in_place(vec, start, mid, end); 

}

void merge_in_place(vector<int>& vec, int start, int mid, int end){
    int size {end-start};
    vector<int> mix(size);
    int i = start;
    int j = mid;
    int k = 0;

    while (i < mid && j < end) {
        if (vec[i] < vec[j]) {
            mix[k] = vec[i];
            i++;

        } else {
            mix[k] = vec[j];
            j++;
        }
        ++k;
    }

    // It may be possible that one of the arrays is not completely iterated
    while(i < mid) {
        mix[k] = vec[i];
        ++i;
        ++k;
    }

    while(j < end) {
        mix[k] = vec[j];
        ++j;
        ++k;
    }

    for (int l = 0; l < mix.size(); l++)
    {
        vec[start+l] = mix[l];
    }
    
}