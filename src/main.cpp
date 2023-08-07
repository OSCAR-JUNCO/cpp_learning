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
	for (auto p: ans) cout << p << endl;

    return 0;
}