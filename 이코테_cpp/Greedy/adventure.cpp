#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n; // 사람 수

	vector<int> arr;

	for (int i = 0; i < n; i++)
	{
		int fear; // 공포도 
		cin >> fear;
		arr.push_back(fear); // 공포도 입력
	}

	sort(arr.begin(), arr.end()); // 오름차순 정렬, begin과 end는 iterator

	int group = 0; // 총 그룹 수
	int cnt = 0; // 현재 포함된 모험가 수

	for (int i = 0; i < arr.size(); i++) // 정렬된 공포도 확인
	{
		cnt += 1; // 현재 그룹에 해당 모험가 포함
		if (cnt >= arr[i]){ // 현재 그룹에 포함된 모함가의 수가 현재 공포도 이상이라면, 그룹 결성
			group += 1; // 총 그룹의 수 증가
			cnt = 0; // 초기화
		}
	}
	cout << group << endl;
}