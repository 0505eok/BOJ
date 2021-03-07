#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> v[32001];
int ind[32001];
int n,m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        ind[b]++;
    }

    priority_queue<int> q;
    for(int i=1;i<=n;i++){
        if(ind[i] == 0)
            q.push(-i);
    }

    while(!q.empty()){
        int x = -q.top();
        q.pop();

        cout << x << " ";
        for(int i=0;i<v[x].size();i++){
            ind[v[x][i]]--;
            if(ind[v[x][i]] == 0)
                q.push(-v[x][i]);
        }
    }
    return 0;
}
