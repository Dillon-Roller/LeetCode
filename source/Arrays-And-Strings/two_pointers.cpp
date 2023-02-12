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
}