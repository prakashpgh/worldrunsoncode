#pragma once
#include<vector>
#include<map>

/**
 * @brief Space O(N)
 *  Time O(N)
 
    Strategy: Hashtable
 */
class TwoSum {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> numIndexMap;
        std::vector<int> result;
        result.reserve(2);
        int index = 0;
        for(int num : nums ) {
            auto iter = numIndexMap.find(target - num);
            if(iter != numIndexMap.end()) {
                result.push_back(index);        
                result.push_back(iter->second);
                return result;
            }
            numIndexMap[num] = index;        
            index++;
            
        }
        return result;
    }
};