/*
Find the longest not diminishing sequence.

Input
n - number of elements in the sequence; the sequence of integers in the interval [-10, 105]

Ouput
The length of the longest not diminishing sequence

Example input:
6
6 6 6 2 2 7
6
1 1 1 1 1 2
15
1 2 1 2 1 2 1 2 1 2 1 2 1 2 1
3
4 3 2

Answer:
4
6
8
1
*/

#include <iostream>
#include <vector>
#include <algorithm>

long long longestSeq(std::vector<long long> arr)
{
    std::vector<long long> lis(arr.size());

    for (unsigned k = 0; k < arr.size(); k++)
    {
        lis[k] = 1;
        for (unsigned i = 0; i < k; i++)
            if (arr[i] <= arr[k])
                lis[k] = std::max(lis[k], lis[i] + 1);
    }

    std::vector<long long>::const_iterator it;
    it = std::max_element(lis.begin(), lis.end());
    return *it;
}

int main()
{
    unsigned long long n;
    while (std::cin >> n) {
        std::vector<long long> input;
        while (n) {
            long long current;
            std::cin >> current;
            input.push_back(current);
            n--;
        }
        std::cout << longestSeq(input) << std::endl;
    }
    return 0;
}
