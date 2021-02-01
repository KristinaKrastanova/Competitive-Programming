/*
Program that finds the coefficient before the kth power of x in the polynomial
p(x) = (x - 1)n(x + 1)m.

Input
Integer numbers: n, m and k. 

Restrictions
n, m >= 0
n + m <= 60
0 <= k <= n + m

Example input:
3 1 3
4 0 2

Answer:
-2
6
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

std::vector<long double> getCoef(int rowIndex) {
    std::vector<long double> row;
    row.push_back(1);
    if (rowIndex == 0)
        return row;
    row.push_back(1);
    if (rowIndex == 1)
        return row;

    std::vector<long double> result;
    for (int j = 2; j <= rowIndex; j++) {
        result.clear();
        result.push_back(1);
        for (int i = 1; i <= j - 1; i++) {
            result.push_back(row[i - 1] + row[i]);
        }
        result.push_back(1);
        row = result;
    }
    return row;
}

long long multiply(std::vector<long double>& A, std::vector<long double>& B, int k)
{
    std::vector<long double> prod (A.size() + B.size() - 1);
 
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
            prod[i + j] += A[i] * B[j];
    }

    return prod[k];
}
  
int main()
{
    std::string input;
    while (std::getline(std::cin, input)) {
        std::istringstream inpStr(input);
        int n, m, k;
        inpStr >> n >> m >> k;
        std::vector<long double> firstB = getCoef(n);

        for (int i = 0; i < firstB.size(); i++) {
            if (i % 2 != 0) firstB[i] *= (-1);
        }

        std::vector<long double> secondB = getCoef(m);

        std::reverse(firstB.begin(),firstB.end());
        std::reverse(secondB.begin(), secondB.end());

        std::cout << multiply(firstB, secondB, k) << std::endl;

    }
    return 0;
}
