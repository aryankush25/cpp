#include <iostream>
// #include <vector>
// #include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> findAllPermutations(vector<int> nums, vector<int> fixedNums = {}) {
        vector<vector<int>> permutations = {};

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

            vector<vector<int>> permus = findAllPermutations(ns, fns);

            for (int j = 0; j < permus.size(); j++) {
                permutations.push_back(permus[j]);
            }
        }

        return permutations;
    }

    void nextPermutation(vector<int>& nums) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<vector<int>> allPermutations =  findAllPermutations(sortedNums);

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
