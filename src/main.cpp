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
    string cris {"bactodtodartodaycdah"};
    string skip {"tod"};
    string not_skip {"today"};
    cout << skip_string_that_is_not(cris, skip, not_skip) << endl; 

    return 0;
}