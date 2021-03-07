#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<int> v[1001];
vector<int> ans;
queue<int> q;
int ind[1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0;i<m;i++){
        int a;
        cin >> a;
        int b;
        cin >> b;
        for(int j=1;j<a;j++){
            int c;
            cin >> c;
            v[b].push_back(c);
            ind[c]++;
            b=c;
        }
    }

    for(int i=1;i<=n;i++)
        if(ind[i] == 0)
            q.push(i);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for(int i=0;i<v[x].size();i++){
            ind[v[x][i]]--;
            if(ind[v[x][i]] == 0)
                q.push(v[x][i]);
        }
    }

    if(ans.size() != n)
        cout << 0 << "\n";
    else
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << "\n";

    return 0;
}
