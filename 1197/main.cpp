#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int v,e;
int node[10001];
priority_queue<pair<int,int>> q;
vector<pair<int,int>> g[10001];
int cnt;

void prim(){
    q.push(make_pair(0,1));

    while(!q.empty()){
        int cur = q.top().second;
        int tmp = q.top().first;
        q.pop();
        if(node[cur] == 1)
            continue;
        cnt += -tmp;
        node[cur] = 1;
        for(int i=0;i<g[cur].size();i++){
            if(node[g[cur][i].first] == 0)
                q.push(make_pair(-g[cur][i].second, g[cur][i].first));
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
    }
    prim();
    cout << cnt << "\n";
    return 0;
}
/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int v,e;
vector<pair<int, pair<int,int>>> g;
int parent[10001];
int Find(int a){
    if(parent[a] == 0)
        return a;
    else
        return parent[a] = Find(parent[a]);
}
void Union(int a, int b){
    if(a > b)
        swap(a,b);
    parent[b] = a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e;

    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        g.push_back(make_pair(c,make_pair(a,b)));
    }

    sort(g.begin(), g.end());
    int cnt = 0;
    for(int i=0;i<g.size();i++){
        int a = Find(g[i].second.first);
        int b = Find(g[i].second.second);
        if(a == b)
            continue;
        else {
            //parent[b] = a;
            Union(a,b);
            cnt += g[i].first;
        }
    }
    cout << cnt << "\n";
    return 0;
}
*/