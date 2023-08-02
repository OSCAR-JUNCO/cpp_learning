#include "array_recursion.h"

bool sorted_array(const vector<int>& vec) {
    int index = 0;
    return helper_sorted_array(vec, index);
}

bool helper_sorted_array(const vector<int>& vec, int index) {
    if (index == vec.size()-1) {
        return true;
    }
    return vec[index] < vec[index+1] && helper_sorted_array(vec, ++index);
    
    // Another way
    // if (vec[index] < vec[index+1]) {
    //     return helper_sorted_array(vec, ++index);
    // }
    // return false;
}


int linear_search(const vector<int>& vec, int target) {
    int index = 0;
    return helper_linear_search(vec, target, index);
}

int helper_linear_search(const vector<int>& vec, int target, int index) {
    if (index >= vec.size()) {
        return -1;
    }
    if (vec[index] == target) {
        return index;
    }
    return helper_linear_search(vec, target, ++index);
}


bool bool_linear_search(const vector<int>& vec, int target) {
    int index = 0;
    return bool_helper_linear_search(vec, target, index);
}

bool bool_helper_linear_search(const vector<int>& vec, int target, int index) {
    if (index >= vec.size()) {
        return false;
    }
    return vec[index] == target || bool_helper_linear_search(vec, target, ++index);
}


vector<int> linear_search_all(const vector<int>& vec, int target) {
    vector<int> ans;
    int index = 0;
    return helper_linear_search_all(vec, target, ans, index);
}

vector<int> helper_linear_search_all(const vector<int>& vec, int target, vector<int>& ans, int index) {
    if (index >= vec.size()) {
        return ans;
    }
    if (vec[index] == target) {
        ans.push_back(index);
    }
    return helper_linear_search_all(vec, target, ans, ++index);
}


vector<int> linear_search2(const vector<int>& vec, int target) {
    int index = 0;
    return helper_linear_search2(vec, target, index);
}

vector<int> helper_linear_search2(const vector<int>& vec, int target, int index) {
    vector<int> localAns;
    if (index >= vec.size()) {
        return localAns;
    }
    // This will contain answier fot that function call only
    if (vec[index] == target) {
        localAns.push_back(index);
    }
    vector<int> ansFromBelowCalls = helper_linear_search2(vec, target, ++index);
    if (!ansFromBelowCalls.empty()) {
        localAns.insert(localAns.end(), ansFromBelowCalls.begin(), ansFromBelowCalls.end());
    }
    return localAns;
}


int rotated_binary_search(const vector<int>& vec, int target) {
    int start = 0;
    int end = vec.size() - 1;
    return helper_rbs(vec, target, start, end);
}

int helper_rbs(const vector<int>& vec, int target, int start, int end) {
    if (start > end) return -1;

    int middle = start + (end - start )/2;

    if (vec[middle] == target) return middle;

    // First half is sorted
    if (vec[start] <= vec[middle]) {
        if (target >= vec[start] && target <= vec[middle]) return helper_rbs(vec, target, start, middle-1);
        else return helper_rbs(vec, target, middle+1, end);
    }

    // Second half is sorted
    if (target >= vec[middle] && target <= vec[end]) return helper_rbs(vec, target, middle+1, end); 
    return helper_rbs(vec, target, start, middle-1);
}

