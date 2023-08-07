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

    vector<string> ans = permutations("", "abc");
	int count = count_permutations("", "abc");
	cout << count << " permutations!" << endl;
	for (auto p: ans) cout << p << endl;

    return 0;
}