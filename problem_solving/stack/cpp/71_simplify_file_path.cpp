/*
'''
https://leetcode.com/problems/simplify-path/description/

use of stack
    .. => pop
    no token or . => ignore
    
#meta
'''
*/
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


std::string simplify_path(const std::string& path) {
    std::string result;
    return result;
}


int main() {
    std::string path = "/home/";
    //#"/home"
    std::string new_path = simplify_path(path);
    std::cout << "new_path: " <<  new_path << std::endl;


    path = "/home//foo/";
    //#"/home/foo"
    new_path = simplify_path(path);
    std::cout << "new_path: " <<  new_path << std::endl;

    path = "/home/user/Documents/../Pictures";
    //#Output: "/home/user/Pictures"
    new_path = simplify_path(path);
    std::cout << "new_path: " <<  new_path << std::endl;


    path = "/../";
    //#Output: "/"
    new_path = simplify_path(path);
    std::cout << "new_path: " <<  new_path << std::endl;


    path = "/.../a/../b/c/../d/./";
    //#Output: "/.../b/d"
    new_path = simplify_path(path);
    std::cout << "new_path: " <<  new_path << std::endl;

}
