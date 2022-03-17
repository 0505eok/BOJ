#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n,m;
int xp[4] = {-1,0,1,0};
int yp[4] = {0,-1,0,1};
char arr[101][101];
int dist[101][101] = {-1,};

int main(){
    cin >> m >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
            dist[i][j] = -1;
        }
    }

    priority_queue<pair<int,pair<int,int>>> q;
    q.push({0,{1,1}});
    dist[1][1] = 0;

    while(!q.empty()){
        int cur = -q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();

        if(dist[x][y] != -1 && dist[x][y] < cur)
            continue;
        //dist[x][y] = cur;

        if(x == n && y == m) {
            break;
        }

        for(int i=0;i<4;i++){
            int xx = x + xp[i];
            int yy = y + yp[i];
            if(xx<=0||xx>n||yy<=0||yy>m)
                continue;
            int tmp = cur;
            if(arr[xx][yy] == '1')
                tmp += 1;
            if(dist[xx][yy] != -1 && dist[xx][yy] <= tmp)
                continue;
            dist[xx][yy] = tmp;
            q.push({-tmp, {xx,yy}});
        }
    }
    cout << dist[n][m] << "\n";
}