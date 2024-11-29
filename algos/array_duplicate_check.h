#include<vector>
#include<set>

bool duplicate_check(const std::vector<int>& array) {
    std::set<int> numInArray;
    for( const int i : array ) {
        if( numInArray.find(i) != numInArray.end() )
            return true;
        numInArray.insert(i);
    }    
    return false;
}