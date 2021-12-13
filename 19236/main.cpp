#include <iostream>
using namespace std;
int xp[9] = {0,-1,-1,0,1,1,1,0,-1};
int yp[9] = {0,0,-1,-1,-1,0,1,1,1};
int arr[4][4][2];
int mac;
void dfs(int x,int y,int d, int w){
    int aqua[4][4][2];
    arr[x][y][0] = 0;
    for(int i=1;i<=16;i++){
        int fw,fx,fy,fd;
        int flag = 0;
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                if(arr[j][k][0] == i){
                    fx = j;
                    fy = k;
                    fw = arr[j][k][0];
                    fd = arr[j][k][1];
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0)
            continue;
        int tmp = fd;
        int tx,ty,tw,td;
        while(1) {
            tx = fx + xp[fd];
            ty = fy + yp[fd];
            if (tx < 0 || tx >= 4 || ty < 0 || ty >= 4 || (tx == x && ty == y)) {
                fd++;
                if(fd == 9)
                    fd = 1;
                if(fd == tmp)
                    break;
                continue;
            }
            tw = arr[tx][ty][0];
            td = arr[tx][ty][1];
            arr[tx][ty][0] = fw;
            arr[tx][ty][1] = fd;
            arr[fx][fy][0] = tw;
            arr[fx][fy][1] = td;
            break;
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            aqua[i][j][0] = arr[i][j][0];
            aqua[i][j][1] = arr[i][j][1];
            if(arr[i][j][0] == 0)
                continue;
        }
    }

    int sx,sy,sw;
    for(int i=1;i<4;i++){
        sx = x + i * xp[d];
        sy = y + i * yp[d];
        if(sx < 0 || sx >= 4 || sy < 0 || sy >= 4 || arr[sx][sy][0] == 0)
            continue;
        sw = w + arr[sx][sy][0];
        dfs(sx,sy,arr[sx][sy][1],sw);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                arr[i][j][0] = aqua[i][j][0];
                arr[i][j][1] = aqua[i][j][1];
            }
        }
    }
    mac = max(w,mac);
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >> arr[i][j][0] >> arr[i][j][1];
        }
    }
    dfs(0,0,arr[0][0][1],arr[0][0][0]);
    cout << mac << "\n";
    return 0;
}
