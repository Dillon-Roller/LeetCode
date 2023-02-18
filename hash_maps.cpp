#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <vector>
#include <climits>

using namespace std;


int findLongestSubstring(string s, int k) {
    unordered_map<char, int> counts;
    int left = 0, ans = 0;
    
    for (int right = 0; right < s.size(); right++) {
        counts[s[right]]++;
        while (counts.size() > k) {
            counts[s[left]]--;
            if (counts[s[left]] == 0) {
                counts.erase(s[left]);
            }
            left++;
        }
        
        ans = max(ans, right - left + 1);
    }
    
    return ans;
}

vector<int> intersection(vector<vector<int>>& nums) {
    unordered_map<int, int> counts;
    for (vector<int>& arr: nums) {
        for (int x: arr) {
            counts[x]++;
        }
    }
    
    int n = int(nums.size());
    vector<int> ans;
    for (auto [key, val]: counts) {
        if (val == n) {
            ans.push_back(key);
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}

bool areOccurrencesEqual(string s) {
    unordered_map<char, int> counts;
    for (char c: s) {
        counts[c]++;
    }
    
    unordered_set<int> frequencies;
    for (auto [key, val]: counts) {
        frequencies.insert(val);
    }
    
    return frequencies.size() == 1;
}

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    counts[0] = 1;
    int ans = 0, curr = 0;
    
    for (int num: nums) {
        curr += num;
        ans += counts[curr - k];
        counts[curr]++;
    }
    
    return ans;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    counts[0] = 1;
    int ans = 0, curr = 0;
    
    for (int num: nums) {
        curr += num % 2;
        ans += counts[curr - k];
        counts[curr] += 1;
    }
    
    return ans;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (string& s: strs) {
        string t = s;
        sort(t.begin(), t.end());
        groups[t].push_back(s);
    }
    
    vector<vector<string>> ans;
    for (auto [key, val]: groups) {
        ans.push_back(val);
    }
    
    return ans;
}

int minimumCardPickup(vector<int>& cards) {
    unordered_map<int, int> dic;
    int ans = INT_MAX;
    
    for (int i = 0; i < cards.size(); i++) {
        if (dic.find(cards[i]) != dic.end()) {
            ans = min(ans, i - dic[cards[i]] + 1);
        }
        
        dic[cards[i]] = i;
    }
    
    return ans == INT_MAX ? -1 : ans;
}

int maximumSum(vector<int>& nums) {
    unordered_map<int, int> dic;
    int ans = -1;
    
    for (int num: nums) {
        int digitSum = getDigitSum(num);
        if (dic.find(digitSum) != dic.end()) {
            ans = max(ans, num + dic[digitSum]);
        }
        dic[digitSum] = max(dic[digitSum], num);
    }

    return ans;
}

int getDigitSum(int num) {
    int digitSum = 0;
    while (num > 0) {
        digitSum += num % 10;
        num /= 10;
    }
    
    return digitSum;
}