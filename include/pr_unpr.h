#ifndef PR_UNPR_H
#define PR_UNPR_H

#include <iostream>
#include <string>

using namespace std;

string skip_char(const string str, char c);
void helper_sc(string& up, const string p, char c);

string skip_string(const string str, string skip);
void helper_ss(string& up, const string p, string skip);

string skip_string_that_is_not(const string str, string skip, string not_skip);
void helper_sstin(string& up, const string p, string skip, string not_skip);


#endif // PR_UNPR_H
