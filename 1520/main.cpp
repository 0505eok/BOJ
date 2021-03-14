#include <iostream>
using namespace std;
int m,n;
int arr[501][501];
int visited[501][501];
int xp[4] = {-1,1,0,0};
int yp[4] = {0,0,-1,1};
int sol(int x, int y){
    visited[y][x] = 0;
    if(x == n-1 && y == m-1){
        visited[y][x] = 1;
        return visited[y][x];
    }
    for(int i=0;i<4;i++){
        int nx = x + xp[i];
        int ny = y + yp[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if(arr[ny][nx] >= arr[y][x])
            continue;
        if(visited[ny][nx] != -1) {
            visited[y][x] += visited[ny][nx];
            continue;
        }
        visited[y][x] += sol(nx,ny);
    }
    return visited[y][x];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            visited[i][j] = -1;
        }
    }

    cout << sol(0,0) << "\n";
    return 0;
}
