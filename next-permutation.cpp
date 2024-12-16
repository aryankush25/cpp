#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > findAllPermutations(vector<int> nums, vector<int> fixedNums = vector<int>()) {
        vector<vector<int> > permutations;

        if (nums.size() == 1) {
            fixedNums.push_back(nums[0]);
            permutations.push_back(fixedNums);
            return permutations;
        }

        for (int i = 0; i < nums.size(); i++) {
            vector<int> fns = fixedNums;
            fns.push_back(nums[i]);

            vector<int> ns = nums;
            ns.erase(ns.begin() + i);

            vector<vector<int> > permus = findAllPermutations(ns, fns);

            for (int j = 0; j < permus.size(); j++) {
                permutations.push_back(permus[j]);
            }
        }

        return permutations;
    }

    void nextPermutation(vector<int>& nums) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<vector<int> > allPermutations = findAllPermutations(sortedNums);

        int index;

        for (int k = 0; k < allPermutations.size(); k++) {
            vector<int> permutations = allPermutations[k];
            bool isMatching = true;

            for (int i = 0; i < permutations.size(); i++) {
                if (permutations[i] != nums[i]) {
                    isMatching = false;
                }
            }

            if (isMatching) {
                index = k;
            }
        }

        if (index + 1 == allPermutations.size()) {
            nums = allPermutations[0];
        } else {
            nums = allPermutations[index + 1];
        }
    }
};

int main() {
    Solution solution;

    // Test case 1: [1,2,3]
    int arr1[] = {1, 2, 3};
    vector<int> nums1(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]));
    cout << "Original: [1,2,3]" << endl;
    solution.nextPermutation(nums1);
    cout << "Next permutation: [";
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i];
        if (i < nums1.size() - 1) cout << ",";
    }
    cout << "]" << endl << endl;

    // Test case 2: [3,2,1]
    int arr2[] = {3, 2, 1};
    vector<int> nums2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
    cout << "Original: [3,2,1]" << endl;
    solution.nextPermutation(nums2);
    cout << "Next permutation: [";
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i];
        if (i < nums2.size() - 1) cout << ",";
    }
    cout << "]" << endl << endl;

    // Test case 3: [1,1,5]
    int arr3[] = {1, 1, 5};
    vector<int> nums3(arr3, arr3 + sizeof(arr3)/sizeof(arr3[0]));
    cout << "Original: [1,1,5]" << endl;
    solution.nextPermutation(nums3);
    cout << "Next permutation: [";
    for (int i = 0; i < nums3.size(); i++) {
        cout << nums3[i];
        if (i < nums3.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
