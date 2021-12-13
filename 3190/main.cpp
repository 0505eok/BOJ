#include <iostream>
#include <vector>
using namespace std;
int n,k,l;
int arr[101][101];
int xpo[4] = {0,1,0,-1};
int ypo[4] = {1,0,-1,0};
vector<pair<int,char>> w;
typedef struct Pos{
    int x;
    int y;
}pos;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j] = -1;
        }
    }

    for(int i=0;i<k;i++){
        int x,y;
        cin >> x >> y;
        arr[x][y] = 10;
    }
    cin >> l;
    for(int i=0;i<l;i++){
        int x;
        char c;
        cin >> x >> c;
        w.push_back(make_pair(x,c));
    }

    int cnt = 0;
    int idx = 0;
    pos head,tail;
    head.x = 1;
    head.y = 1;
    tail.x = 1;
    tail.y = 1;
    arr[1][1] = 0;
    int fwd = 0;
    while(1){
        cnt++;
        int flag = 0;
        head.x += xpo[fwd];
        head.y += ypo[fwd];

        if(head.y == 0 || head.y == n+1 || head.x == 0 || head.x == n+1)
            break;
        if(arr[head.x][head.y] != -1) {
            if(arr[head.x][head.y] == 10)
                flag = 1;
            else
                break;
        }
        if(w[idx].first == cnt){
            if(w[idx].second == 'D') {
                fwd++;
                if(fwd == 4)
                    fwd = 0;
            }
            else if(w[idx].second == 'L') {
                fwd--;
                if (fwd == -1)
                    fwd = 3;
            }
            idx++;
        }
        arr[head.x][head.y] = fwd;
        if(flag == 0){
            int tmp = arr[tail.x][tail.y];
            arr[tail.x][tail.y] = -1;
            tail.x += xpo[tmp];
            tail.y += ypo[tmp];
        }

    }
    cout << cnt << "\n";
    return 0;
}
