#include <iostream>
#include <string>

#include "recursion.h"
#include "functions.h"
#include "array_recursion.h"
#include "patterns.h"
#include "templates.h"
#include "sort.h"

using namespace std;

int main(){
    vector<int> nums = {5, 7, 3, 4, 1, 6, 2};
    quick_sort(nums);
    for (auto num : nums) cout << num << " ";
    cout << endl;

    return 0;
}