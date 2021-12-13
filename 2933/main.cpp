#include <iostream>
#include <vector>
using namespace std;
int r,c,n;
char arr[101][101];
int xp[4] = {-1,1,0,0};
int yp[4] = {0,0,-1,1};
void cal(int x){
    x = r - x;
    int sx,sy;
    for(int i=0;i<c;i++){
        if(arr[x][i] == 'x') {
            sx = x;
            sy = i;
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> arr[i][j];
        }
    }

    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    for(int i=0;i<v.size();i++){
        cal(v[i]);
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
