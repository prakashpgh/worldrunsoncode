#include <iostream>
#include <map>
#include <vector>
using namespace std;

void arrays_static()
{
    std::cout << "arrays_static" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    for (int n : arr)
    {
        std::cout << n << std::endl;
    }
}

void arrays_dynamic()
{
    std::cout << "arrays_dynamic" << std::endl;
    int *arr = new int[5];
    int i = 0;
    int size = 6;
    while (i < size)
    {
        arr[i] = i;
        i++;
    };
    for (int j = 0; j < size; j++)
    {
        std::cout << arr[j] << std::endl;
    }
}

class ArrayList
{
public:
    ArrayList(int size)
        : data(nullptr),
          capacity(size),
          num_elements(0)
    {
        data = new int[capacity];
    }

    void resize()
    {
        // new memory & copy from old...
        int *new_data = new int[capacity * 2];
        for (auto index = 0; index < num_elements; ++index)
        {
            new_data[index] = data[index];
        }
        // delete the old data
        delete[] data;
        // point old to new.
        data = new_data;
        capacity *= 2;
    }

    void insert(int val)
    {
        if (num_elements + 1 >= capacity)
        {
            resize();
        }
        data[num_elements++] = val;
    }

    int length()
    {
        return num_elements;
    }

private:
    int *data;
    int num_elements;
    int capacity;
};

void two_dim_array_static()
{
    // 2-dim array
    int rows = 3;
    int cols = 3;
    int two_dim[rows][cols] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << two_dim[i][j] << "     ";
        }
        std::cout << std::endl;
    }
}

void two_dim_array_dynamic()
{
    std::cout << "dynamic array" << std::endl;
    // 2-dim array
    int rows = 3;
    int cols = 3;
    int **dyn = new int *[rows];
    for (int row = 0; row < rows; ++row)
    {
        dyn[row] = new int[cols];
    }

    int count = 1;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            dyn[i][j] = count++;
        }
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << dyn[i][j] << "     ";
        }
        std::cout << std::endl;
    }
}

void two_sum(int *array, int size, int target)
{
    std::map<int, int> num_index;
    for (int i = 0; i < size; ++i)
    {
        int req = target - array[i];
        if (num_index.find(req) != num_index.end())
        {
            std::cout << "found it";
        }
        num_index.insert(std::pair<int, int>(array[i], i));
    }
}

/**
2   4   0   6
0   0   48  0
*/
void product_all_except_itself(const std::vector<int> &input)
{
    std::vector<int> pre(input.size());
    std::vector<int> post(input.size());
    pre[0] = 1;
    int prefix = 1;
    post[input.size() - 1] = 1;
    int postfix = 1;
    for (int i = 1; i < input.size(); ++i)
    {
        pre[i] = prefix * input[i - 1];
        prefix = pre[i];
    }
    for (int i = input.size() - 2; i >= 0; --i)
    {
        post[i] = postfix * input[i + 1];
        postfix = post[i];
    }

    std::cout << "pre";
    for (auto m : pre)
    {
        std::cout << m << " ";
    }
    std::cout << std::endl;

    std::cout << "post";
    for (auto m : post)
    {
        std::cout << m << " ";
    }
    std::cout << std::endl;
    std::vector<int> result(input.size());
    for (int i = 0; i < input.size(); ++i)
    {
        result[i] = pre[i] * post[i];
    }
    for (auto m : result)
    {
        std::cout << m << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "main start" << std::endl;
    arrays_static();

    arrays_dynamic();
    std::cout << "main end" << std::endl;

    // 2-dim
    two_dim_array_static();

    two_dim_array_dynamic();

    // post and prefix
    std::vector arr = {2, 4, 0, 6};
    product_all_except_itself(arr);
}
