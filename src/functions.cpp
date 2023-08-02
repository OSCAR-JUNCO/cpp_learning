#include "functions.h"


vector<int> plusOne(vector<int>& digits) {
    for(auto it = digits.end()-1; it >= digits.begin(); --it)
    {
        if(*(it) != 9)
        {   
            cout << *(it) << endl;
            ++*(it);
            cout << *(it) << endl;
            break;
        }
        else
        {
            *(it) = 0;
        }
        if (it == digits.begin())
        {
            digits.insert(it, 1);
        }
    }
    return digits;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> group;
    map<vector<int>, vector<string>> groups_map;

    for(auto& s: strs){
        vector<int> key = anagramKey(s);
        groups_map[key].push_back(s);
    }

    for(auto& pair: groups_map){
        group.push_back(pair.second);
    }
    
    return group;
}

vector<int> anagramKey(string s){
    vector<int> key(26, 0);
    for(auto c: s){
        key[c-'a']++;
    }

    return key;
}

bool isAnagram(string s, string t) {
    int cs[26]={},ct[26]={};
    for(auto c:s){
        cs[(int)c-'a']++;
    }
    for(auto c:t){
        ct[(int)c-'a']++;
    }
    for(int i=0;i<26;i++){
        if(cs[i]!=ct[i]) return false;
    }
    return true;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    int size_res = m*n;
    vector<int> res(size_res);
    
    int row = 0, col = 0;
    int i = 1, j = 0;
    int mov = 1;
    
    for(size_t x = 0; x < size_res; ++x)
    {
        res[x] = matrix[row][col];
        
        switch(mov)
        {
            case 1:
                if(col == n-1)
                {
                    mov = 2;
                    --n;
                    ++row;
                }
                ++col;
                //else ++col;
                break;
                
            case 2:
                if(row == m-1)
                {
                    mov = 3;
                    --m;
                    --col;
                }
                else ++row;
                break;
                
            case 3:
                if(col == j)
                {
                    mov = 4;
                    ++j;
                    --row;
                }
                else --col;
                break;
                
            case 4:
                if(row == i)
                {
                    mov = 1;
                    ++i;
                    ++col;
                }
                else --row;
                break;
        }
    }
    return res;
    
    
}

bool cmp(pair<int, int> pair_a, pair<int, int> pair_b){
    return pair_a.second > pair_b.second;
}

vector<int> topKFrequent(vector<int>& nums, int k){
    vector<int> result;
    unordered_map<int, int> freq;
    vector<pair<int, int>> ordered_vector;
    for(auto& num: nums){
        freq[num]++;
    }
    for(auto& it: freq){
        ordered_vector.push_back(it);
    }    
    sort(ordered_vector.begin(), ordered_vector.end());
    for(int i=0; i<k; i++){
        result.push_back(ordered_vector[i].first);
    }

    return result;
}

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(), 1);
    // Compute the prefix product
    for(int i = 0; i < nums.size()-1; ++i){
        result[i+1] = result[i] * nums[i];
    } 

    // Compute the final result
    int suffixProduct = 1;
    for(int j = nums.size() -1; j > 0; --j){
        suffixProduct *= nums[j];
        result[j-1] *= suffixProduct;
    }
    return result;
}

bool isValidSudoku(vector<vector<char>>& board) {
    map<int, int> my_map;
    for (size_t i = 1; i <= 9; i++)
    {
        my_map[i] = 0;
    }
    for(auto& row: board)
    {
        for(auto& c: row)
        {
            cout << c << " ";

        }
        cout << endl;
    }
    return true;
}

int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> numsSet(begin(nums), end(nums));
        int max = 1, counter = 1;

        set<int>::iterator it = next(numsSet.begin());

        for(it; it != numsSet.end(); ++it)
        {
            cout << *it << " " << *prev(it) << " " << counter << endl;
            if(*it == *prev(it) + 1)
            {
                counter++;
            } 
            else
            {
                max = counter > max ? counter : max;
                counter = 1;
            }
            if (it == prev(numsSet.end()))
            {
                max = counter > max ? counter : max;
            }
        }
        cout << endl;
        cout << "max: " << max << endl;
        return max;
    }

bool isValid(string s) {
    stack<char> stack;
    for(auto &c : s){
        if (stack.empty())
        {
            stack.push(c);
            continue;
        }
        int diff = c - stack.top();
        if (diff == 1 || diff == 2) stack.pop();
        else stack.push(c);
    }
    
    if (stack.empty()) return true;
    return false;
}

int evalRPN(vector<string>& tokens) {
    stack<int> stack;
    vector<string> operations {"+", "-", "*", "/"};
    int first, second;
    for(const auto& token : tokens){
        auto it = find(operations.begin(), operations.end(), token);
        if (it != operations.end()){
            second = stack.top();
            stack.pop();
            first = stack.top();
            stack.pop();
            switch(token[0])
            {
                case '+':
                    stack.push(first+second);
                    break;
                case '-':
                    stack.push(first-second);
                    break;
                case '*':
                    stack.push(first*second);
                    break;
                case '/':
                    stack.push(first/second);
                    break;
            }

        }
        else stack.push(stoi(token));
    }
    return stack.top();
}
