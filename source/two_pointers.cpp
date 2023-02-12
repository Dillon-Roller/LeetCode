#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

bool is_palindrone(const string& word) {
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

vector<int> merge_vectors(const vector<int>& v1, const vector<int>& v2) {
    vector<int> v;
    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size()) {
        if(v1[i] < v2[j]) {
            v.push_back(v1[i++]);
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

bool is_subsequence(const string& word, const string& target) {
    
}

int main() {
    assert(is_palindrone("racecar"));
    assert(find_pairwise_sum({1, 2, 4, 6, 8, 9, 14, 15}, 13));
    assert(merge_vectors({1, 3, 5}, {2, 4, 6}) == vector<int>({1, 2, 3, 4, 5, 6}));

}