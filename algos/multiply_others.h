/*
input [1 2 3 4]
output [24 12 8 6]

[-1 1 0 -3 3]
[ 0 0 9  0 0]


*/
#include<vector>

std::vector<int> productExceptSelf(const std::vector<int>& vec) {
    std::vector<int> result;
    result.resize(vec.size());
    int prefix = 1;
    int postFix = 1;
    int len = vec.size();
    for( int i = 0; i < len; ++i ) {
        int tempPrefix = prefix;
        prefix *= vec[i];
        result[i] = tempPrefix;
    }
    postFix = 1;
    for( int i = len - 1; i >= 0; --i ) {
        int tempPostFix = postFix;
        postFix *= vec[i];
        result[i] *= tempPostFix;
    }
    return result;
}