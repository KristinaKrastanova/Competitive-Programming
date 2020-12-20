/*Program to print positive integers in p numeral system.
Input:
The first number on each row is the base. Then there is a sequence of decimal numbers to be tranfrormed.
Restrictions:
2 <= p <= 32
The length of the sequence <= 1000.
All numbers from the input are in the interval [0, 106].*/

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

char addSingleDigit(int n)
{
    if (n < 10) {
        return n + '0';
    }
    else{
        return 'A' + (n - 10);
    }
}

std::string decimalToOther(int decimal, int base)
{
    std::stack<char> remaining;
    if (decimal == 0) return "0";

    while (decimal > 0)
    {
        char rem = addSingleDigit(decimal % base);
        decimal = decimal / base;
        remaining.push(rem);
    }
    std::string newBase;
    while (!remaining.empty())
    {
        newBase += remaining.top();
        remaining.pop();
    }
    return newBase;
}

int main()
{
    std::string input;

    while (std::getline(std::cin, input)) {
        std::istringstream is(input);
        int base;
        is >> base;
        int currentNum;
        while (is >> currentNum) {
            std::cout << decimalToOther(currentNum, base) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
