#include <iostream>
#include <string>

#include "recursion.h"
#include "functions.h"
#include "array_recursion.h"
#include "patterns.h"
#include "templates.h"
#include "sort.h"
#include "pr_unpr.h"

using namespace std;

int main(){

    vector<int> nums {1, 2, 2};
	vector<vector<int>> subsets = subset_duplicate(nums);
	for (auto subset: subsets) {
		cout << "[";
		for (auto num: subset) {
			cout << num;
		}
		cout << "] ";
		cout << endl;
	} 

    return 0;
}