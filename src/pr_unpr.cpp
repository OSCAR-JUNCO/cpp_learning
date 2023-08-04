#include "pr_unpr.h"


string skip_char(const string str, char c){
    string ans {""};
    helper_sc(ans, str, c);
    return ans;
}

void helper_sc(string& up, const string p, char c){
    // Base condition
    if (p.size() == 0) {
        return;
    }

    // Logic
    if (p[0] != c) {
        up += p[0];
    }

    // Recursive call
    helper_sc(up, p.substr(1), c);
}


string skip_string(string str, string skip){
	string ans {""};
	helper_ss(ans, str, skip);
	return ans;
}

void helper_ss(string& up, string p, string skip) {
	// Base condition
	if (p.size() == 0) {
		return;
	}

	// Logic
	if (p.substr(0, skip.size()) != skip) {
		up += p[0];
		helper_ss(up, p.substr(1), skip);
	} else {
		helper_ss(up, p.substr(skip.size()), skip);
	}

}