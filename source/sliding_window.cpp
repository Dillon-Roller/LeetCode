#include <iostream>
#include <vector>

using namespace std;

int find_longest_subarray(const vector<int>& v, const int k);

int main() {
    cout << find_longest_subarray({10, 20, 30}, 50) << endl;
    return 0;
}

int find_longest_subarray(const vector<int>& v, const int k) {
    int left = 0, sum = 0, max_length = 0;

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