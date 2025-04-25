/*
https://leetcode.com/problems/course-schedule-ii/


'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>
#include<iostream>

std::vector<int> courses_order(int n, const std::vector<std::vector<int>>& prereq) {
    std::vector<int> course_order;
    return course_order;
}



int main() {
    int numCourses = 2;
    std::vector<std::vector<int>> prerequisites = {{1,0}};
    std::vector<int> order = courses_order(numCourses, prerequisites);
    print_vector(order);
    //#output = [0,1]

    numCourses = 4;
    prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    order = courses_order(numCourses, prerequisites);
    print_vector(order);
    //#output: [0,2,1,3]

    numCourses = 1;
    prerequisites = {};
    order = courses_order(numCourses, prerequisites);
    print_vector(order);
    //#output: [0]

    numCourses = 6;
    prerequisites = {{2,0},{1,0},{0,3},{3,4},{3,5}};
    order = courses_order(numCourses, prerequisites);
    std::cout << "order: " << std::endl;
    print_vector(order);
    //#output: [4,5,3,0,1,2]
    return 0;
}

