#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq; //���� �� ���� �������� �� �ֵ��� �ϴ� �켱���� ť �����.
    int answer = 0;
    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]); // �켱����ť�� ���ں� ���� ���� �־��ش�. �ڵ����� ������ �ȴ�. 
    }
    while (pq.top()<K){
        if (pq.size() == 1 & pq.top() < K) {
            answer = -1;
            break;
        }
        //cout << "pq.top(): " << pq.top();
        int a = pq.top(); pq.pop(); //���� ���� ���� ����.
        int b = pq.top(); pq.pop();//���� ���� ���� ����. 
        int c = a + (b *2);
        pq.push(c); //���� �۾Ҵ� �� �ΰ��� ����� ���� ���� �־��ش�.
        answer++;
    }
    return answer;
}