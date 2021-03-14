/**** disjoint set 쓴거 ****/
#include<iostream>
#include<algorithm>

using namespace std;
int n,m,k;
int money[10001];
int f[10001];
int Find(int a){
    if(f[a] == 0) return a;
    else return f[a] = Find(f[a]);
}
void Union(int a, int b){
    int aa = Find(a);
    int bb = Find(b);
    if(aa == bb)
        return;
    if(money[aa] > money[bb])
        swap(aa,bb);
    f[bb] = aa;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        cin >> money[i];
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        Union(a,b);
    }
    int mon = 0;
    for(int i=1;i<=n;i++){
        if(f[i] == 0)
            mon += money[i];
    }
    if(mon > k)
        cout << "Oh no\n";
    else
        cout << mon << "\n";
    return 0;
}
/**** bfs 쓴거 ****/
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n,m,k;
vector<pair<int,int>> v;
vector<int> f[10001];
int visited[10001];
int bfs(int s){
    if(visited[s] == 1)
        return 0;

    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<f[x].size();i++){
            if(visited[f[x][i]] == 1)
                continue;
            visited[f[x][i]] = 1;
            q.push(f[x][i]);
        }
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        v.push_back(make_pair(x,i));
    }
    sort(v.begin(), v.end());
    for(int i=0;i<m;i++){
        int s,e;
        cin >> s >> e;
        f[s].push_back(e);
        f[e].push_back(s);
    }

    int money = 0;
    for(int i=0;i<n;i++){
        int tmp = bfs(v[i].second);
        if(tmp == 0)
            continue;
        else
            money += v[i].first;
    }

    if(money > k)
        cout << "Oh no\n";
    else
        cout << money << "\n";
    return 0;
}
*/