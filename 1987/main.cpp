#include <iostream>

using namespace std;

int R,C;
char arr[21][21];
int visited[27];
int xp[4] = {-1,1,0,0};
int yp[4] = {0,0,-1,1};
int cnt;
int m = 1;
int dfs(int x, int y){
    visited[arr[x][y] - 'A'] = 1;
    cnt++;
    for(int i=0;i<4;i++){
        int xx = x + xp[i];
        int yy = y + yp[i];
        if(xx < 0 || xx >= R || yy < 0 || yy >= C)
            continue;
        if(visited[arr[xx][yy] - 'A'] != 0)
            continue;
        m = max(cnt,dfs(xx,yy));
        cnt--;
        visited[arr[xx][yy] - 'A'] = 0;
    }
    return m;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++){
            cin >> arr[i][j];
        }
    }

    cout << dfs(0,0) << "\n";
    return 0;
}
