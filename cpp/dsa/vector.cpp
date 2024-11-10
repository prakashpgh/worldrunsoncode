#include <iostream>
#include <vector>

void vectors()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (auto i : vec)
    {
        std::cout << i << std::endl;
    }
}

//O(i + j)
std::vector<int> merge_sorted_arrays(const std::vector<int> &vecA, const std::vector<int> &vecB)
{
    std::vector<int> result;
    int i = 0;
    int j = 0;
    while (i < vecA.size() && j < vecB.size())
    {
        if (vecA[i] <= vecB[j])
        {
            result.push_back(vecA[i]);
            i++;
        }
        else if (vecA[i] > vecB[j])
        {
            result.push_back(vecB[j]);
            j++;
        }
    }
    if (i < vecA.size())
    {
        result.insert(result.end(), vecA.begin() + i, vecA.end());
    }
    if (j < vecA.size())
    {
        result.insert(result.end(), vecB.begin() + j, vecB.end());
    }
    return result;
}

//O()
void merge_sorted_arrays_inplace(std::vector<int> &vecA, const std::vector<int> &vecB)
{
    std::vector<int> result;
    int i = 0;
    int j = 0;
    while (i < vecA.size() && j < vecB.size())
    {
        if (vecA[i] > vecB[j])
        {
            vecA.insert(vecA.begin() + i, vecB[j]);
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if (j < vecB.size())
    {
        vecA.insert(vecA.end(), vecB.begin() + j, vecB.end());
    }
}

int main()
{
    std::cout << "main start" << std::endl;
    std::vector<std::vector<int>> nums1 = {
        {23, 33, 35, 41, 44, 47, 56, 91, 105},
        {1, 2},
        {1, 1, 1},
        {6},
        {12, 34, 45, 56, 67, 78, 89, 99}};

    std::vector<std::vector<int>> nums2 = {
        {32, 49, 50, 51, 61, 99},
        {7},
        {1, 2, 3, 4},
        {-99, -45},
        {100}};

    std::vector<int> size1 = {9, 2, 3, 1, 8};
    std::vector<int> size2 = {6, 1, 4, 2, 1};

    for (size_t i = 0; i < nums1.size(); ++i)
    {
        std::cout << i + 1 << ".\tFirst array: [ ";
        for (size_t j = 0; j < size1[i]; ++j)
        {
            std::cout << nums1[i][j] << " ";
        }
        std::cout << "]" << std::endl;

        std::cout << "\tSecond array: [ ";
        for (size_t j = 0; j < size2[i]; ++j)
        {
            std::cout << nums2[i][j] << " ";
        }
        std::cout << "]" << std::endl;

        // std::vector<int> merged = merge_sorted_arrays(nums1[i], nums2[i]);
        merge_sorted_arrays_inplace(nums1[i], nums2[i]);
        auto merged = nums1[i];
        std::cout << "\tMerged array: [ ";
        for (int num : merged)
        {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;

        std::string line(100, '-');
        std::cout << line << std::endl;
    }
}