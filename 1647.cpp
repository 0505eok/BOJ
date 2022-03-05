#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int parent[100001];

int findParent(int n){
    if(parent[n] == n)
        return n;
    return parent[n] = findParent(parent[n]);
}

void join(int a, int b){
    if(a > b)
        swap(a,b);
    parent[a] = b;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,pair<int,int>>> v;
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }

    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back({c,{a,b}});
    }

    sort(v.begin(), v.end());

    int cnt = 1;
    int ans = 0;
    int ma = 0;
    for(int i=0;i<v.size();i++){
        if(cnt == n)
            break;
        int a = v[i].second.first;
        int b = v[i].second.second;
        int c = v[i].first;

        int ap = findParent(a);
        int bp = findParent(b);
        if(ap == bp)
            continue;
        join(ap,bp);
        cnt++;
        ans += c;
        ma = max(ma,c);
    }
    cout << ans - ma << "\n";
}