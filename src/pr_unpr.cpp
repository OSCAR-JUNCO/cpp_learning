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


string skip_string_that_is_not(const string str, string skip, string not_skip){
    string ans {""};
    helper_sstin(ans, str, skip, not_skip);
    return ans;
}

void helper_sstin(string& up, const string p, string skip, string not_skip){
	// Base condition
	if (p.size() == 0) {
		return;
	}

	// Logic
	if (p.substr(0, skip.size()) == skip && p.substr(0, not_skip.size()) != not_skip) {
		helper_sstin(up, p.substr(skip.size()), skip, not_skip);
	} else {
		up += p[0];
		helper_sstin(up, p.substr(1), skip, not_skip);
	}
}


void print_subseqs(string str){
    helper_ps("", str);
}
void helper_ps(string p, string up){
    if (up.size() == 0) {
        cout << p << endl;
        return;
    }
    // Take
    helper_ps(p+up[0], up.substr(1));
    // Ignore
    helper_ps(p, up.substr(1));
}


vector<string> subseqs(string str){
    vector<string> ans;
    helper_s(ans, "", str);
    return ans;
}
void helper_s(vector<string>& ans, string p, string up){
    if (up.size() == 0) {
        ans.push_back(p);
        return;
    }
    // Take
    helper_s(ans, p+up[0], up.substr(1));
    // Ignore
    helper_s(ans, p, up.substr(1));
}


vector<string> subseqs_direct(string p, string up){
    if (up.size() == 0) {
        vector<string> processed;
        processed.push_back(p);
        return processed;
    }
    // Take
    vector<string> left = subseqs_direct(p+up[0], up.substr(1));
    // Ignore
    vector<string> right = subseqs_direct(p, up.substr(1));

    // Fusione the vectors and return
    left.insert(left.end(), right.begin(), right.end());
    return left;
}


vector<vector<int>> subset_iteration(const vector<int>& nums){
	vector<vector<int>> subsets {};
	vector<int> inner {};
	subsets.push_back(inner);
	for (auto num: nums) {
		int subsets_size = (int)subsets.size();
		for (int i = 0; i < subsets_size; ++i) {
			vector<int> take {subsets[i]};
			// Take the element, ignore by default
			take.push_back(num);
			subsets.push_back(take);
		}
	}

	return subsets;
}

vector<vector<int>> subset_duplicate(vector<int>& nums){
	std::sort(nums.begin(), nums.end());
	vector<vector<int>> subsets {};
	vector<int> first {};
	subsets.push_back(first);
	
	int start = 0;
	int end = 0;

	for (int i = 0; i < (int) nums.size(); i++)
	{
		start = 0;
		// If current and previous element are the same, s = e + 1
		if (i > 0 && nums[i] == nums[i-1]){
			start = end + 1;
		}
		end = subsets.size()-1;

		int n = (int) subsets.size();
		for (int j = start; j < n; j++)
		{
			vector<int> take {subsets[j]};
			// Take the element, ignore by default
			take.push_back(nums[i]);
			subsets.push_back(take);
		}
	}

	return subsets;
}