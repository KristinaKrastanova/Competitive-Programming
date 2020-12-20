/*
From given sequence a1, a2, ..., an of integer numbers. Find the biggest number, which is difference of two consistent members of the sequence a[i+1]- a[i] for i = 1, 2, ..., n - 1. 
Input
n - length of the sequence
n numbers separated with space
Restrictions
2 <= n <= 1000
Each number in the sequence is in the interval [-1000, 1000].
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::string diff(int size, std::vector<int>& numbers) {
    int bgDif = 0;
    for (int i = 0; i < size - 1; i++) {
        int currentDif = 0;

        if (numbers[i + 1] < 0) {
            currentDif = numbers[i] + numbers[i + 1];
        }
        else {
            currentDif = abs(numbers[i] - numbers[i + 1]);
        }

        if (currentDif > bgDif) {
            bgDif = currentDif;
        }
    }
    return std::to_string(bgDif);
}

int main()
{
    int size;
    while (std::cin >> size) {
        std::cin.ignore();
        std::string input;
        std::getline(std::cin, input);
        std::istringstream inputStr(input);
        int num;
        std::vector<int>vecNum;
        while (inputStr >> num) {
            vecNum.push_back(num);
        }
        std::cout << diff(size, vecNum);
        std::cout << std::endl;
    }
    return 0;
}

