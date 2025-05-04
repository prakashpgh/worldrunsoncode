/*
'''
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

sort by end-points
if the start of next > end of previous, then arrow += 1
'''
*/

int minimum_number_of_arrows(const std::vector<int>& balloons) {
    int result = 0;
    return result;
}

def minimum_number_of_arrows(points: list[int]):
    #sort by end points
    if list is None or len(points) == 0:
        return 0
    points.sort(key = lambda t: t[1])
    print("after sort: " + str(points))
    arrows = 1
    previous_end = points[0][1]
    #iterate, if next start is greate that the previous end, then arrow += 1..
    for i in range(len(points)-1):
        #next starts afte the end of the previous
        if points[i+1][0] > previous_end:
            arrows += 1
            previous_end = points[i+1][1]
    return arrows


int main() {
    std::vector<int> points;
    points = {{10,16},{2,8},{1,6},{7,12}};
    #Output: 2
    #Explanation: The balloons can be burst by 2 arrows:
    #- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
    #- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
    arrows = minimum_number_of_arrows(points)
    print("arrows: " + str(arrows))
    
    
    points = {{1,2},{3,4},{5,6},{7,8}};
    #Output: 4
    #Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
    arrows = minimum_number_of_arrows(points)
    print("arrows: " + str(arrows))
    
    
    points = {{1,2},{2,3},{3,4},{4,5}};
    #Output: 2
    #Explanation: The balloons can be burst by 2 arrows:
    arrows = minimum_number_of_arrows(points)
    print("arrows: " + str(arrows))
    
}


