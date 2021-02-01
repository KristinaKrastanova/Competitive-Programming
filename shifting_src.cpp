/*
"a" is natural number. By shifting the digits of the number "a", a set of different numbers can be constructed. Find the number "m" of the elements of this set and the nth largest number in the set.

Input
a and n

Restrictions
0 < a < 1013
0 < n <  m + 1

Output
For every example print nth largest number in the set.

Example input:
12345 2
10023 5
222 1

Answers:
12354 120
312 60
222 1
*/

#include <iostream>
#include <algorithm>

int main()
{
    std::string a;
    unsigned long long n, m = 0;
    //a - input num; m - number of all numbers; n- nth number in the set
    while (std::cin >> a >> n) {
        std::string result;

        std::sort(a.begin(), a.end());
        do {
            m++;
            if (m == n) {
                for (unsigned long long i = 0; i < a.length(); i++) {
                    if (!(result.empty() && a[i] == '0'))
                    result.push_back(a[i]);
                }
            }

        } while (std::next_permutation(a.begin(),a.end()));

        std::cout << result << " " << m << std::endl;
        m = 0;
   }
   return 0;
}
