#include <iostream>

using namespace std;
int r,c;
char arr[10001][501];
int xp[3] = {0,1,-1};
int yp[1] = {1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> arr[i][j];
        }
    }


    return 0;
}
