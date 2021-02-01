/*
A positive integer n-digit number is given.
Find the smallest and largest n-digit numbers that can be obtained by exchanging the digits of the given number.

Input
Sequence of positive integers smaller than 10200

Ouput
For every number, print the smallest and largerst n-digit numbers

Example input:
238
3001
100

Answer:
238 832
1003 3100
100 100
*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

int main()
{
    std::string a;
    while (std::getline(std::cin, a)) {
        
        std::string min = a;
        std::sort(min.begin(), min.end());

        int i = 0;
        while (min[i] == '0')
            i++;

        std::swap(min[0], min[i]);
        std::sort(a.begin(), a.end(), std::greater<char>());
        std::cout << min << " " << a << std::endl;
        
    }
    return 0;
}
