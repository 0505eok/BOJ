#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
vector<int> v[32001];
int arr[32001];
queue<int> q;
void sol(){
    while(!q.empty()){
        int x = q.front();
        q.pop();

        cout << x << " ";

        for(int i=0;i<v[x].size();i++){
            arr[v[x][i]]--;
            if(arr[v[x][i]] == 0)
                q.push(v[x][i]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        arr[b]++;
    }

    for(int i=1;i<=n;i++){
        if(arr[i] == 0)
            q.push(i);
    }
    sol();
    return 0;
}
