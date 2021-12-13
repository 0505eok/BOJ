#include <iostream>

using namespace std;

int arr[10][10];
int paper[6];
int mi = 100;
void dfs(int x, int y, int cnt){
    if(y == 10){
        y = 0;
        x += 1;
    }

    if(x == 10){
        mi = min(cnt, mi);
        return;
    }

    if(arr[x][y]==0)
        dfs(x,y+1,cnt);
    else{
        for(int i=1;i<=5;i++){
            if(paper[i] == 0)
                continue;
            if(x + i > 10 || y + i > 10)
                break;
            int flag = 0;
            for(int j=0;j<i;j++){
                for(int k=0;k<i;k++){
                    if(arr[x+j][y+k] == 0){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1)
                    break;
            }
            if(flag == 0){
                for(int j=0;j<i;j++){
                    for(int k=0;k<i;k++){
                        arr[x+j][y+k] = 0;
                    }
                }
                paper[i]--;
                dfs(x,y+1,cnt+1);
                paper[i]++;
                for(int j=0;j<i;j++){
                    for(int k=0;k<i;k++){
                        arr[x+j][y+k] = 1;
                    }
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin >> arr[i][j];
        }
    }

    for(int i=1;i<6;i++){
        paper[i] = 5;
    }

    dfs(0,0,0);

    if(mi == 100)
        mi = -1;
    cout << mi << "\n";
    return 0;
}
