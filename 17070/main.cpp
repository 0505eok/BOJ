#include <iostream>
#include <queue>
using namespace std;
int n;
int arr[17][17];
int xp[3] = {0,1,1};
int yp[3] = {1,1,0};
queue<pair<pair<int,int>,pair<int,int>>> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
        }
    }

    q.push(make_pair(make_pair(1,1), make_pair(1,2)));

    int cnt = 0;
    while(!q.empty()){
        int sx = q.front().first.first;
        int sy = q.front().first.second;
        int ex = q.front().second.first;
        int ey = q.front().second.second;
        q.pop();

        //cout << sx << " " << sy << " " <<ex << " " << ey << "\n";
        if(ex == n && ey == n)
            cnt++;

        if(sx == ex){ // 가로
            if(arr[ex][ey+1] == 0 && ey+1 <= n)
                q.push(make_pair(make_pair(ex,ey), make_pair(ex,ey+1)));
        }
        else if(sy == ey) { // 세로
            if(arr[ex+1][ey] == 0 && ex+1 <= n)
                q.push(make_pair(make_pair(ex,ey), make_pair(ex+1,ey)));
        }
        else if(sx == ex-1 && sy == ey-1) { // 대각선
            if(arr[ex][ey+1] == 0 && ey+1 <=n)
                q.push(make_pair(make_pair(ex,ey), make_pair(ex,ey+1)));
            if(arr[ex+1][ey] == 0 && ex+1 <=n)
                q.push(make_pair(make_pair(ex,ey), make_pair(ex+1,ey)));
        }

        int flag = 0;
        for(int i=0;i<3;i++){
            if(flag == 1)
                break;
            int x = ex + xp[i];
            int y = ey + yp[i];
            if(arr[x][y] == 1 || x > n || y > n)
                flag = 1;
        }
        if(flag == 0)
            q.push(make_pair(make_pair(ex,ey), make_pair(ex+1,ey+1)));
    }

    cout << cnt << "\n";
    return 0;
}
