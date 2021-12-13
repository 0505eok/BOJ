#include <iostream>

using namespace std;
int n,m,h;
int ladder[31][11];
int mi = 4;
int check_ladder(){
    for(int i=1;i<=n;i++){
        int r = i;
        for(int j=1;j<=h;j++){
            if(ladder[j][r] == 1)
                r++;
            else if(ladder[j][r-1] == 1)
                r--;
        }
        if(r != i)
            return -1;
    }
    return 0;
}
void draw_ladder(int c, int cnt){
    if(cnt == 4)
        return;
    if(check_ladder() == 0) {
        mi = min(mi, cnt);
        return;
    }
    for(int i=c;i<=h;i++){
        for(int j=1;j<n;j++){
            if(ladder[i][j] == 1 || ladder[i][j-1] == 1 || ladder[i][j+1] == 1)
                continue;
            ladder[i][j] = 1;
            draw_ladder(i,cnt+1);
            ladder[i][j] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h;

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        ladder[a][b] = 1;
    }

    draw_ladder(1,0);
    if(mi == 4)
        mi = -1;
    cout << mi << "\n";
    return 0;
}
