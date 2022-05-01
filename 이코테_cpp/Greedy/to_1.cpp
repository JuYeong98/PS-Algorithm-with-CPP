#include<iostream>

int main() {
	int N, K;
	int result = 0;
	std::cin >> N >> K ;

	while (true) {
		if (N % K == 0) {
			N /= K;
		}
		else {
			N -= 1;
		}
		result++;
		if (N == 1) break;
	}

	std::cout << result;
	return 0;
}