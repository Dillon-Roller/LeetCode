#include <iostream>
#include <string>
#include <cassert>

using namespace std;

bool is_palindrone(string word) {
    int left = 0;
    int right = word.size() - 1;

    for(int i = 0; i < word.size(); i++) {
        if (word[left] != word[right]) {
            return false;
        }
    }
    return true;
}

int main() {
    assert(is_palindrone("racecar"));
}