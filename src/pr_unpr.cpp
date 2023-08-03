#include "pr_unpr.h"

string ans {""};

string skip_char(string str, char c){
    helper_sc(str, c);
    return ans;
}

void helper_sc(string p, char c){
    // Base condition
    if (p.size() == 0) {
        return;
    }

    // Logic
    if (p[0] != c) {
        ans += p[0];
    }

    // Recursive call
    helper_sc(p.substr(1), c);
}