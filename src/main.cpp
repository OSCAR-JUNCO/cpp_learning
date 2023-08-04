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

    string str {"abc"};
    vector<string> ans = subseqs_direct("", str);

    for(auto subset: ans) cout << "'" <<  subset << "' ";
    cout << endl;

    return 0;
}