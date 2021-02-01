/*
F(n) = (a * F(n - p) + b * F(n - q)) mod 1000000
for n >= k (a, b, p, q and k are positive integer numbers)
F(n) = 1 when n < 0,
F(0) = F(1) = 1,
F(n) = n when 1 < n < k.
Find the number of primer numbers in F(0), F(1), ..., F(1000).

Input
a, b, p, q and k

Restrictions
a, b, p, q and k < 100.

Output
For every example print the number
*/

#include <iostream>

bool isPrime(long long j)
{
	if (j <= 1) {
		return false;
	}

	long long i = 2;
	while ((i * i) <= j) {
		if (j % i == 0) {
			return false;
		}
		i++;
	}

	return true;
}

int main()
{
	int a, b, p, q, k;
	while (std::cin >> a >> b >> p >> q >> k) {
		int sum = 0;
		long long numbers[1001];

		for (int n = 0; n < 1001; n++) {
			if (n == 1 || n == 0) {
				numbers[n] = 1;
			}
			else if (n > 1 && n < k) {
				numbers[n] = n;
				if (isPrime(n))sum++;
			}
			else if (n >= k) {
				long long f1;
				long long f2;
				f1 = numbers[n - p];
				f2 = numbers[n - q];

				if ((n - p) <= 1 ) {
					f1 = 1;
				}

				if ((n - q) <= 1) {
					f2 = 1;
				}
				
				long long result = ((a * f1) + (b * f2)) % 1000000;
				numbers[n] = result;
				if (isPrime(result))sum++;
			}
		}
		std::cout << sum << std::endl;
	}
}

