//#include "twosum.h"
#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_to_index;
        for (int i = 0; i < nums.size(); ++i){
            int complement = target - nums.at(i);
            auto it = num_to_index.find(complement);
            if (it != num_to_index.end()){
                return {it->second, i};
            }
            num_to_index[nums.at(i)] = i;
        }
        return {};
    }
};

int main(){

    vector<int> nums = {3,3};
    int target = 6;

    Solution solution;
    vector<int> result = solution.twoSum(nums,target);
    cout << result.at(0) << ":" << result.at(1) << endl;
    return 0;
}
