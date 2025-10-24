#include <iostream>
using namespace std;

int main() {
    int nums[4] = {2, 7, 11, 15};
    int length = sizeof(nums) / sizeof(int);
    int target = 9;

    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (nums[i] + nums[j] == target) {
                cout << "[" << i << ", " << j << "]" << endl;
            }
        }
    }

    return 0;
}
