#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
int dp[5][5][100001];

int score(int cur, int idx){
    if(cur == 0)
        return 2;
    if(cur == v[idx])
        return 1;
    if(cur == 1 || cur == 3){
        if(v[idx] == 2 || v[idx] == 4)
            return 3;
        return 4;
    }
    if(cur == 2 || cur == 4){
        if(v[idx] == 1 || v[idx] == 3)
            return 3;
        return 4;
    }
}

int dfs(int l, int r, int next){
    if(next == v.size())
        return 0;
    if(dp[l][r][next] != 0)
        return dp[l][r][next];
    int left = dfs(v[next],r,next+1) + score(l,next);
    int right = dfs(l,v[next],next+1) + score(r,next);
    return dp[l][r][next] = min(left, right);
}

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == 0)
            break;
        v.push_back(n);
    }
    int ans = dfs(0,0,0);
    cout << ans << "\n";
}