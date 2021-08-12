#include <iostream>
int sum(int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += i;
	}
	return sum;
}
int sum_recursive(int n) {
	if (n == 1) return 1;
	return n + sum_recursive(n - 1);
}