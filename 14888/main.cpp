#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n;
vector<int> v;
int op[4]; // + - * /
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    for(int i=0;i<4;i++){
        cin >> op[i];
    }

    queue<pair<pair<long long,int>,pair<pair<int,int>,pair<int,int>>>> q;
    q.push(make_pair(make_pair(v[0],0),make_pair(make_pair(op[0],op[1]), make_pair(op[2],op[3]))));
    long long Min = 1000000001;
    long long Max = -1000000001;
    while(!q.empty()){
        long long cur = q.front().first.first;
        int idx = q.front().first.second;
        int pl = q.front().second.first.first;
        int mi = q.front().second.first.second;
        int mul = q.front().second.second.first;
        int div = q.front().second.second.second;
        q.pop();

        if(pl == 0 && mi == 0 && mul == 0 && div == 0){
            Min = min(cur, Min);
            Max = max(cur, Max);
            continue;
        }

        idx++;
        if(pl != 0)
            q.push(make_pair(make_pair(cur+v[idx],idx),make_pair(make_pair(pl-1,mi),make_pair(mul,div))));
        if(mi != 0)
            q.push(make_pair(make_pair(cur-v[idx],idx),make_pair(make_pair(pl,mi-1),make_pair(mul,div))));
        if(mul != 0)
            q.push(make_pair(make_pair(cur*v[idx],idx),make_pair(make_pair(pl,mi),make_pair(mul-1,div))));
        if(div != 0)
            q.push(make_pair(make_pair(cur/v[idx],idx),make_pair(make_pair(pl,mi),make_pair(mul,div-1))));
    }

    cout << Max << "\n" << Min <<"\n";
    return 0;
}
