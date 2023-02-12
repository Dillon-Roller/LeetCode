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

int main() {
    assert(is_palindrone("racecar"));
    assert(find_pairwise_sum({1, 2, 4, 6, 8, 9, 14, 15}, 13));
}