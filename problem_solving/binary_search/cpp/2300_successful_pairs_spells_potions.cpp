/*
https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

for each, spell, do a binary search
t: O( (m+n) * log(m) )  => sorting: mlogm   binarysearch: n * logm
s: 
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<algorithm>
#include<math.h>


std::vector<int> successful_pairs_spells_potions( std::vector<int> spells, std::vector<int> potions, long long success) {
    std::sort(potions.begin(), potions.end());
    int s = spells.size();
    int p = potions.size();
    std::vector<int> result(s);
    for(int i = 0; i < s; ++i)  {
        long long min_strength = (success + spells[i] - 1)/spells[i];
        int l =0;
        int r = p-1;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(potions[m] < min_strength) {
                l = m + 1;
            } else  {
                r = m-1;
            }
        }
        result[i] = p - l;
    }
    return result;
}


int main() {
    std::vector<int> spells = {5,1,3};
    std::vector<int> potions = {1,2,3,4,5};
    int success = 7;
    //#Output: [4,0,3]
    auto result = successful_pairs_spells_potions(spells, potions, success);
    print_vector(result);
    
    
    
    spells = {3,1,2};
    potions = {8,5,8};
    success = 16;
    //#Output: [2,0,2]
    result = successful_pairs_spells_potions(spells, potions, success);
    print_vector(result);

    return 0;
}
