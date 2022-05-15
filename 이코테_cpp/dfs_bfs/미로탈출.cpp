#include <iostream>
#include <queue>

using namespace std;

int n,m;
int map[200][200];

//상하좌우 좌표 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
    

int bfs(int x, int y){
    
     queue<pair<int, int> > q;
     q.push(pair<int,int>(x,y)); //큐에 쌍으로 값 넣기 
    
    // 큐가 빌 때까지 반복
    while(!q.empty()){
       int currentX = q.front().first; // 현재 x위치 
       int currentY = q.front().second; // 현재 y확인 
       
       q.pop(); // 큐에서 제거 
       // 현재 위치에서 상하좌우 방향으로의 위치 확인
        for(int i = 0; i < 4; i++){
            int nx = currentX + dx[i];
            int ny = currentY + dy[i];
            
             //주어진 범위를 벗어나면 무시 
            if(nx >= n || nx <= -1 || ny >= m || ny <= -1)
                continue;
            
            // 해당 노드를 처음 방문하는 경우에만 최단 거리 기록(0이거나 이미 방문한 경우는 무시) 
            if(map[nx][ny] == 1){
                map[nx][ny] = map[currentX][currentY] + 1;
                q.push(pair<int,int>(nx,ny)); 
            }
        }
    }
    
    return map[n-1][m-1];
}

int main(void)
{
    cin >> n >> m; // 공백을 기준으로 N, M값 받기 
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &map[i][j]); // 공백 없이 붙은 입력 받기 
        }
    }

     // 처음 위치부터 BFS를 수행한 결과 출력 
    cout << bfs(0, 0);

}
