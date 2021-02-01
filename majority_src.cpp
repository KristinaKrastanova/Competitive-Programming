/*
Find the majority element.
Input
n - number of strings 1 < n < 10^5
strings - they don't include spaces
Output
 If there is majority print the majority element else print "-".
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef unsigned long long ull;

ull checkTotalCount(std::vector<std::string>& all, std::string& cand) {
    ull res = 0;
    std::vector<std::string>::iterator it = std::find(all.begin(), all.end(), cand);
    while (it != all.end()) {
        if (*it == cand) res++;
        it++;
    }
    return res;
}

int main()
{
    long long n;
    while (std::cin >> n) {
        std::vector<std::string> all;
        ull count = 0;
        std::string cand;
        long double dn = static_cast<long double>(n) / 2;

        while (n) {
            std::string current;
            std::cin >> current;

            if (count == 0) {
                cand = current;
                count = 1;
            }
            else {
                if (current == cand) count++;
                else {
                    count--;
                    if (count == 0) {
                        cand = "";
                    }
                }

            }
            all.push_back(current);
            n--;
        }

        if (count == 0)
            std::cout << "-" << std::endl;
        else {
            ull res = checkTotalCount(all, cand);
            if (res <= dn)
                std::cout << "-" << std::endl;
            else
                std::cout << cand << std::endl;
        }
    }
}

