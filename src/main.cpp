#include <iostream>
#include <string>

#include "recursion.h"
#include "functions.h"
#include "array_recursion.h"
#include "patterns.h"
#include "templates.h"

using namespace std;

int main(){
    string s1 = "Bonjour,";
    string s2 = "mon ami!";
    int i1 = 4;
    int i2 = 8;
    bool b1 = false;
    bool b2 = false;
    auto result = sum(s1, s2);
    cout << result << endl;

    return 0;
}