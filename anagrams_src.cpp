/*
From given set of strings find the largest subset in which there are no two or more strings that are anagrams of each other.

Input
S
Each set S contains between 1 and 50 strings, each of them with length between 1 and 50.

Ouput
The number of strings in the subset

Example input:
abcd abac aabc bacd
wlrb m bhc arz wk yhi dqs dxr mowfr        sjyb
ab                                         ba
z   

Answer:
2
10
1
1
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int anagramSubset(std::vector<std::string>& arr){
    std::unordered_map<std::string, int> count;

    for (int i = 0; i < arr.size(); ++i) {
        std::sort(arr[i].begin(), arr[i].end());
        count[arr[i]] += 1;
    }

    return count.size();
}

int main()
{
    std::string input;
    while (std::getline(std::cin, input)) {
        std::vector<std::string> S;
        std::istringstream stre(input);
        std::string current;
        while (stre >> current)
            S.push_back(current);
        std::cout << anagramSubset(S) << std::endl;
    }
    return 0;
}
