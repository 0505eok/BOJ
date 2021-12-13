#include <iostream>
#include <vector>
using namespace std;
int n,m,t;
int parent[51];
int tm[51];
int moim[51];
int Find(int x){
    if(parent[x] == x)
        return x;
    else
        return parent[x] = Find(parent[x]);
}
void Union(int a, int b){
    int A = Find(a);
    int B = Find(b);
    if(tm[A] == 1)
        parent[B] = A;
    else
        parent[A] = B;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    cin >> t;
    for(int i=1;i<=n;i++)
        parent[i] = i;
    for(int i=0;i<t;i++){
        int x;
        cin >> x;
        tm[x] = 1;
    }
    for(int i=1;i<=m;i++){
        int k;
        cin >> k;
        int x;
        cin >> x;
        moim[i] = x;
        for(int j=1;j<k;j++){
            int y;
            cin >> y;
            Union(x,y);
            x = y;
        }
    }
    int cnt = 0;
    for(int i=1;i<=m;i++){
        int x = Find(moim[i]);
        if(tm[x] == 1)
            continue;
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
