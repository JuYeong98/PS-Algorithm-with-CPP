# include <iostream>
# include <algorithm>
using namespace std;
string str;

int cnt0 = 0;
int cnt1 = 1;

int main() {
	cin >> str;
	if (str[0] == '1')cnt0++;
	else cnt1++;

	for (int i = 1; i< str.size()-1 ; i++) {
		if (str[i] != str[i + 1]) {
			if (str[i + 1] == '1')cnt0++;
			else cnt1++;
		}
	}
	cout << min(cnt0, cnt1);
}