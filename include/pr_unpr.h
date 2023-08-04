#ifndef PR_UNPR_H
#define PR_UNPR_H

#include <iostream>
#include <string>

using namespace std;

string skip_char(const string str, char c);
void helper_sc(string& up, const string p, char c);

string skip_string(const string str, string skip);
void helper_ss(string& up, const string p, string skip);



#endif // PR_UNPR_H
