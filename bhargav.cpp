// Addition of two numbers using C++

#include <iostream>

int main() {
	long long firstNumber = 0;
	long long secondNumber = 0;

	if (!(std::cin >> firstNumber >> secondNumber)) {
		return 1;
	}

	const long long sum = firstNumber + secondNumber;
	std::cout << sum << '\n';
	return 0;
}
