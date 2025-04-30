/*
'''
https://leetcode.com/problems/binary-tree-vertical-order-traversal/

maintain a map of k,v  k = column-index,  v = list of (rowindex, node values)
    do a dfs, with dfs(node, row, col)

=================================
do a bfs..
in the q, add {node,0}
maintain std::unorderedmap(colindex, std::vector of values)

    for left node add col-1. 
    for right node, add col+1

    sort the colmap[col_index, node_value], get map[index]
'''
*/


#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>


std::vector<std::vector<int>> vertical_traversal(TreeNode* root) {
    std::vector<std::vector<int>> result;
    

    return result;
}