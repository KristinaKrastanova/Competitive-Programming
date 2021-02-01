/*
A sequence of integers is given. Check whether a number can be obtained as sum of numbers from the sequence.

Input
lenght of the sequence, numbers in the sequence, the number of verification numbers and the verification numbers themselves.
 
Output:
"yes" if the number can be obtained, else "no"
 
Example input:
4
2 4 5 9
2
15 10
2
10 20
1
25
 
Answer:
yes no
no
*/

#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <vector>

typedef unsigned long long ull;
std::vector<long long> seq;

bool hasSum(int n, long long sum)
{
    bool subset[2][sum + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {

            if (j == 0)
                subset[i % 2][j] = true;

            else if (i == 0)
                subset[i % 2][j] = false;
            else if (seq[i - 1] <= j)
                subset[i % 2][j] = subset[(i + 1) % 2]
                [j - seq[i - 1]] || subset[(i + 1) % 2][j];
            else
                subset[i % 2][j] = subset[(i + 1) % 2][j];
        }
    }

    return subset[n % 2][sum];
}

int main()
{
    int n;
    while (std::cin >> n) {
        int copyN = n;
        long long c;

        while (copyN) {
            std::cin >> c;
            seq.push_back(c);
            copyN--;
        }

        int nCheck;
        std::cin >> nCheck;
        while (nCheck) {
            std::cin >> c;
            hasSum(n, c) ? std::cout << "yes " : std::cout << "no ";
            nCheck--;
        }
        std::cout << std::endl;
        seq.clear();
    }
    return 0;
}
