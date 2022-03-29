#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,l,r;
int land[51][51];
int xp[4] = {-1,0,1,0};
int yp[4] = {0,-1,0,1};

int main(){
    cin >> n >> l >> r;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> land[i][j];
        }
    }

    int d = 0;
    while(1){
        int visited[n][n];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j] = 0;
            }
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j] == 1)
                    continue;
                visited[i][j] = 1;
                queue<pair<int,int>> q; // x y 개수
                vector<pair<int,int>> v;
                q.push({i,j});
                v.push_back({i,j});
                int cc = 1;
                int total = land[i][j];
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int xx = x + xp[k];
                        int yy = y + yp[k];
                        if(xx < 0 || xx >= n || yy < 0 || yy >= n)
                            continue;
                        if(abs(land[x][y] - land[xx][yy])< l || abs(land[x][y] - land[xx][yy])> r)
                            continue;
                        if(visited[xx][yy] == 1)
                            continue;
                        visited[xx][yy] = 1;
                        q.push({xx,yy});
                        v.push_back({xx,yy});
                        cc++;
                        total += land[xx][yy];
                        cnt++;
                    }
                }
                for(int k=0;k<v.size();k++) {
                    int x = v[k].first;
                    int y = v[k].second;
                    land[x][y] = total / cc;
                }
            }
        }
        if(cnt == 0) {
            break;
        }
        d++;
    }

    cout << d << "\n";

}