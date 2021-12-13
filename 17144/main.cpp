#include <iostream>
#include <queue>
using namespace std;
int r,c,t;
int arr[51][51];
int xp[4] = {-1,1,0,0};
int yp[4] = {0,0,-1,1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c >> t;
    queue<pair<pair<int,int>,int>> q;

    int u = -1;
    int d = -1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> arr[i][j];
            if(arr[i][j] > 0)
                q.push(make_pair(make_pair(i,j),arr[i][j]));
            if(arr[i][j] == -1){
                if(u == -1)
                    u = i;
                else
                    d = i;
            }
        }
    }

    for(int i=0;i<t;i++) {
        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dust = q.front().second;
            q.pop();

            int cnt = 0;
            for(int j=0;j<4;j++){
                int xx = x + xp[j];
                int yy = y + yp[j];
                if(xx < 0 || xx >= r || yy < 0 || yy >= c || (xx == u && yy == 0) || (xx == d && yy == 0))
                    continue;
                arr[xx][yy] += dust/5;
                cnt++;
            }
            arr[x][y] -= (dust/5)*cnt;
        }

        int ix = u-1;
        int iy = 0;
        while(1){
            if(ix > 0 && iy == 0){
                arr[ix][iy] = arr[ix-1][iy];
                ix--;
            }else if(ix == 0 && iy < c-1){
                arr[ix][iy] = arr[ix][iy+1];
                iy++;
            }else if(ix < u && iy == c-1){
                arr[ix][iy] = arr[ix+1][iy];
                ix++;
            }else if(ix == u && iy > 1) {
                arr[ix][iy] = arr[ix][iy - 1];
                iy--;
            }else if(ix == u && iy == 1){
                arr[ix][iy] = 0;
                break;
            }
        }
        ix = d+1;
        iy = 0;
        while(1){
            if(ix < r-1 && iy == 0){
                arr[ix][iy] = arr[ix+1][iy];
                ix++;
            }else if(ix == r-1 && iy < c-1){
                arr[ix][iy] = arr[ix][iy+1];
                iy++;
            }else if(ix > d && iy == c-1){
                arr[ix][iy] = arr[ix-1][iy];
                ix--;
            }else if(ix == d && iy > 1) {
                arr[ix][iy] = arr[ix][iy - 1];
                iy--;
            }else if(ix == d && iy == 1){
                arr[ix][iy] = 0;
                break;
            }
        }
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                if(arr[j][k] > 0)
                    q.push(make_pair(make_pair(j,k),arr[j][k]));
            }
        }
    }
    int ans = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j] > 0)
                ans += arr[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}