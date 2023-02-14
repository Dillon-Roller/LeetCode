#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

bool is_palindrome(const string& word) {
    int left = 0;
    int right = word.size() - 1;

    for(int i = 0; i < word.size(); i++) {
        if (word[left] != word[right]) {
            return false;
        }
    }
    return true;
}

bool find_pairwise_sum(const vector<int>& numbers, const int target) {
    int left = 0;
    int right = numbers.size() - 1;
    int sum = 0;
    while(left < right) {
        int sum = numbers[left] + numbers[right];
        if(sum == target) {
            return true;
        }
        else if(sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
    return false;
}

bool is_sorted(const vector<int> v) {
    for(int i = 0; i < v.size() - 1; i++) {
        if(v[i] > v[i + 1]) {
            return false;
        }
    }
    return true;
}

vector<int> merge_sorted(const vector<int>& v1, const vector<int>& v2) {
    vector<int> v;
    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size()) {
        if(v1[i] < v2[j]) {
            v.push_back(v1[i]);
            i++;
        }
        else {
            v.push_back(v2[j]);
            j++;
        }
    }

    while(i < v1.size()) {
        v.push_back(v1[i]);
        i++;
    }

    while(j < v2.size()) {
        v.push_back(v2[j]);
        j++;
    }

    return v;

}

bool is_subsequence(const string& s, const string& t) {
    int i = 0;
    int j = 0;

    while(i < s.size() && j < t.size()) {
        if(s[i] == t[j]) {
            i++;
        }
        j++;
    }

    return i == s.size();
}

void reverse_string(string& s) {
    for(int i = 0; i < s.size() / 2; i++) {
        swap(s[i], s[s.size() - i - 1]);
    }
}

vector<int> sorted_squares(const vector<int>& numbers) {
    vector<int> squares = numbers;
    for(int i = 0; i < squares.size(); i++) {
        squares[i] = squares[i] * squares[i];
    }

    return squares;
}

int find_longest_subarray(const vector<int>& v, const int k) {
    int left = 0;
    int sum = 0;
    int max_length = 0;

    for (int right = 0; right < v.size(); right++) {
        sum += v[right];
        while(sum > k) {
            sum -= v[left];
            left++;
        }

        max_length = max(max_length, right - left + 1);
    }

    return max_length;
}

double find_max_average(const vector<int>& nums, int k) {
    double sum = 0;
    double max_sum;

    for(int i = 0; i < k; i++) {
        sum += nums[i];
    }

    max_sum = sum;
    for(int i = k; i < nums.size(); i++) {
        sum += nums[i] - nums[i - k];
        max_sum = max(max_sum, sum);
    }
    return max_sum / k;
}

int longest_ones(const vector<int>& nums, int k) {
    int left = 0;
    int right;

    for(right = 0; right < nums.size(); right++) {
        if(nums[right] == 0) {
            k--;
        }

        if (k < 0) {
            if(nums[left] == 0) {
                k++;
            }
            left++;
        }
    }

    return right - left;
}

vector<int> build_prefix(const vector<int>& nums) {
    vector<int> prefix = {nums[0]};
    for (int i = 1; i < nums.size(); i++) {
        prefix.push_back(prefix.back() + nums[i]);
    }
    return prefix;
}

vector<bool> answer_queries(vector<int>& nums, vector<vector<int>>& queries, int limit) {
    vector<int> prefix = build_prefix(nums);
    
    vector<bool> ans;
    for (vector<int>& query: queries) {
        int x = query[0], y = query[1];
        int curr = prefix[y] - prefix[x] + nums[x];
        ans.push_back(curr < limit);
    }
    
    return ans;
}


int main() {
    assert(is_palindrome("racecar"));
    assert(!is_palindrome("racecars"));

    assert(find_pairwise_sum({1, 2, 4, 6, 8, 9, 14, 15}, 13));
    assert(!find_pairwise_sum({1, 2, 4, 6, 8, 9, 14, 15}, 100));

    assert(is_sorted({1, 2, 3}));
    assert(!is_sorted({3, 2, 1}));

    assert(is_sorted(merge_sorted({1, 3, 5}, {2, 4, 6})));

    assert(is_subsequence("ace", "abcde"));
    assert(!is_subsequence("ace", "cbade"));
    
    string s = "hello";
    reverse_string(s);
    assert(s == "olleh");

    assert(sorted_squares({10, 6, 3, 1}) == vector<int>({100, 36, 9, 1}));

    assert(find_longest_subarray({10, 20, 30}, 50) == 2);

    assert(find_max_average({1,12,-5,-6,50,3}, 4) == 12.75);

    assert(longest_ones({0, 1, 1, 1, 0, 1, 0, 1}, 1) == 5);

    vector<int> nums = {1, 6, 3, 2, 7, 2};
    vector<vector<int>> query = {{0, 3}, {2, 5}, {2, 4}};
    assert(answer_queries(nums, query, 13) == vector<bool>({true, false, true}));
}