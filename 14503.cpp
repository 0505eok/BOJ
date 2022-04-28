#include<iostream>
#include<vector>
using namespace std;

int N,M;
int x,y,d;
int arr[51][51];
int clean[51][51];
int xp[4] = {-1,0,1,0};
int yp[4] = {0,-1,0,1};
pair<int,int> dir[4] = {{-1,0},{0,1},{1,0},{0,-1}};

void solution(){
    int cnt = 0;
    while(1){
        if(clean[x][y] == 0){
            cnt++;
            clean[x][y] = 3;
        }
        int flag = 0;
        for(int i=0;i<4;i++){
            d--;
            if(d == -1)
                d = 3;
            int xx = x + dir[d].first;
            int yy = y + dir[d].second;
            if(xx < 0 || xx >= N || yy < 0 || yy >= M)
                continue;
            if(arr[xx][yy] == 1)
                continue;
            if(clean[xx][yy] != 0)
                continue;
            flag = 1;
            break;
        }

        if(flag == 0){
            x -= dir[d].first;
            y -= dir[d].second;
            if(x < 0 || x >= N || y < 0 || y >= M) {
                cout << cnt << '\n';
                return;
            }

            if(arr[x][y] == 1) {
                cout << cnt << '\n';
                return;
            }
            continue;
        }

        x += dir[d].first;
        y += dir[d].second;
    }
}

int main(){
    cin >> N >> M;
    cin >> x >> y >> d;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
            clean[i][j] = arr[i][j];
        }
    }

    solution();
}