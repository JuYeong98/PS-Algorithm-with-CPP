#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int target = 1;
    for (int i = 0; i < n; i++) {
        // 타겟보다 큰 화폐 단위가 주어지면, 만들 수 없는 금액으로 판단
        if (target < v[i]) 
            break; 

        // 타켓보다 작은 화폐 단위일 경우, 해당 화폐 단위를 더한 값으로 타겟 금액 갱신
        target += v[i];
    }

    // 만들 수 없는 금액 출력
    cout << target << '\n';
}