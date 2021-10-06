#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


template <typename T>
void printVec(vector<T> vec)
{
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}

template <typename T>
void printArr(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> tosort = {1,47,69,22,101,13,34,2,7,4};
    printVec(tosort);
    vector<char> chr = {'a', ' ', 'c','h','a', 'r', ' ', 'v','e','c','t','o','r'};
    printVec(chr);
    vector<string> str = {"a", "vector", "of", "strings"};
    printVec(str);
    int nums[] = {1, 35, 16, 17, 8};
    printArr(nums, 5);
    char *astring = "A string";
    printArr(astring, strlen(astring));
    return 0;
}