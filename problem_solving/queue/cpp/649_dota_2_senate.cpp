/*'''
https://leetcode.com/problems/dota2-senate/

use of q.
maintain 2 different qs... fill the indexes r and d in the q
traverse the qs... pop(),  the one with lowers index... append i+N... 
basically we are removing the one with later index from the q...
final result: the q that remains is the winner
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>
#include<queue>


std::string predict_party_victory(std::string senate) {
    std::queue<int> radiant;
    std::queue<int> dire;
    for(int i = 0; i < senate.length(); ++i) {
        if(senate[i] == 'R') {
            radiant.push(i);
        } else if(senate[i] == 'D') {
            dire.push(i);
        } 
    }
    while( !radiant.empty() && !dire.empty())  {
        int r = radiant.front();
        radiant.pop();
        int d = dire.front();
        dire.pop();
        if(r < d) {
            radiant.push(r+senate.length());
        } else {
            dire.push(d+senate.length());
        }
    }
    if(radiant.empty() ) {
        return "Dire";
    } else {
        return "Radiant";
    }
}


int main() {
    std::string senate = "RD";
    //#Output: "Radiant"
    std::string result = predict_party_victory(senate);
    std::cout << "result= " << result << std::endl;

    senate = "RDD";
    //#Output: "Dire"
    result = predict_party_victory(senate);
    std::cout << "result= " << result << std::endl;
}