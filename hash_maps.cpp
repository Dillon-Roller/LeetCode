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
    unordered_map<int, vector<int>> dic;
    
    for (int i = 0; i < cards.size(); i++) {
        dic[cards[i]].push_back(i);
    }
    
    int ans = INT_MAX;
    for (auto [key, arr]: dic) {
        for (int i = 0; i < arr.size() - 1; i++) {
            ans = min(ans, arr[i + 1] - arr[i] + 1);
        }
    }
    
    return ans == INT_MAX ? -1 : ans;
}