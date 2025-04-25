/*
https://leetcode.com/problems/isomorphic-strings/

maintain 2 hashmaps..for mapping from s=>t and t=>s
if the character repeats check if th mapping is correct.. if not return false.
we need 2 hashmaps - to make sure 2 different chars in s dont map to same character in t.

*/
#include<vector>
#include<unordered_map>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;


bool is_isomorphic(const std::string& s1, const std::string& s2) {
    int s1_l = s1.length();
    int s2_l = s2.length();

    if(s1_l != s2_l) {
        return false;
    }
    std::unordered_map<char, char> s_t;
    std::unordered_map<char, char> t_s;
    for(int i = 0; i < s1_l; ++i) {
        if (s_t.find(s1[i]) != s_t.end() && s_t[s1[i]] != s2[i]) {
            return false;
        }
        s_t[s1[i]] = s2[i];

        if (t_s.find(s2[i]) != t_s.end() && t_s[s2[i]] != s1[i]) {
            return false;
        }
        t_s[s2[i]] = s1[i];
    }
    return true;
}


int main() {
    std::string s = "egg";
    std::string t = "add";
    auto result = is_isomorphic(s, t);
    std::cout << "result: " << result << std::endl;
    //true

    s = "foo";
    t = "bar";
    result = is_isomorphic(s, t);
    std::cout << "result: " << result << std::endl;
    //false

    s = "paper";
    t = "title";
    result = is_isomorphic(s, t);
    std::cout << "result: " << result << std::endl;
    //true

    return 0;
}


