/*
Program to calculate arithmetic expressions (sum and diff) of fractions. The answer should be irreducible fraction.

Restrictions
All numbers are positive integers < 10000

Example input
1/2 + 1/3 - 1/6
10/4 - 2/4
Answer:
2/3
2
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

class Fraction {
private:
	long long num;
	long long denom;

	long long gcd(long long a, long long b)
	{
		return (0 == b) ? a : gcd(b, a % b);
	}

public:
	Fraction() {
		num = 1;
		denom = 1;
	}

	Fraction(long long n, long long d = 1) {
		if (d == 0) throw "ERROR ATTEMPT TO DIVIDE BY ZERO";
		
		if (n == 0) {
			num = 0;
			denom = 1;
		}else{
			num = n / gcd(n, d);
			denom = d / gcd(n, d);
		}
		
		if (denom < 0) {
			denom = abs(denom);
			num = -num;
		}
	}

	Fraction operator+(const Fraction& otherFraction)
	{
		return Fraction(num * otherFraction.denom + otherFraction.num * denom, denom * otherFraction.denom);
	}

	Fraction operator-(const Fraction& otherFraction)
	{
		return Fraction(num * otherFraction.denom - otherFraction.num * denom, denom * otherFraction.denom);
	}

	void print() {
		if (denom != 1 && num != 0)
			std::cout << num << "/" << denom << std::endl;
		else {
			if (denom == 1)
				std::cout << num << std::endl;
		}
	}
};

int main()
{
	std::string input;
	while (std::getline(std::cin, input)) {
		std::istringstream stream(input);
		std::vector<Fraction> fractions;
		std::vector<char>operations;
		std::string current;

		while (stream >> current) {
			if (current.size() == 1 && !isdigit(current[0])) {
				char op = current[0];
				operations.push_back(op);
			}
			else {
				int index = -1;
				long long first = 0;
				long long second = 1;
				for (int i = 0; i < current.size(); i++) {
					if (current[i] == '/') {
						index = i + 1;
						break;
					}
					else {
						first = first * 10 + (current[i] - '0');
					}
				}

				if (index < current.size()) {
					second = 0;
					while (index < current.size()) {
						second = second * 10 + (current[index] - '0');
						index++;
					}
				}
				fractions.push_back(Fraction(first, second));
			}
		}

		Fraction currentF;
		for (int i = 0, j = 0; i < operations.size() && j < fractions.size(); i++, j++) {
			if (i == 0 && j == 0) {
				if (operations[i] == '+') {
					currentF = fractions[j] + fractions[j + 1];
				}
				else {
					currentF = fractions[j] - fractions[j + 1];
				}
				j++;
			}
			else {
				if (operations[i] == '+') {
					currentF = currentF + fractions[j];
				}
				else {
					currentF = currentF - fractions[j];
				}
			}
		}

		currentF.print();
	}
}
