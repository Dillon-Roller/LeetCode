#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

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
    cout << max_sum / k << endl;
    return max_sum / k;
}

int longest_ones(const vector<int>& nums, int k) {
    int left = 0;
    int right;
    int zero_count = 0;

    for(int right = 0; right < nums.size(); right++) {
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

int main() {
    assert(find_longest_subarray({10, 20, 30}, 50) == 2);

    assert(find_max_average({1,12,-5,-6,50,3}, 4) == 5.0/2);
}