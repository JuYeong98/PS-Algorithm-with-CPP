#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq; //작은 수 부터 빠져나갈 수 있도록 하는 우선순위 큐 만든다.
    int answer = 0;
    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]); // 우선순위큐에 스코빌 지수 값을 넣어준다. 자동으로 정렬이 된다. 
    }
    while (pq.top()<K){
        if (pq.size() == 1 & pq.top() < K) {
            answer = -1;
            break;
        }
        //cout << "pq.top(): " << pq.top();
        int a = pq.top(); pq.pop(); //가장 작은 값을 뺀다.
        int b = pq.top(); pq.pop();//가장 작은 값을 뺀다. 
        int c = a + (b *2);
        pq.push(c); //가장 작았던 값 두개를 계산을 통해 새로 넣어준다.
        answer++;
    }
    return answer;
}