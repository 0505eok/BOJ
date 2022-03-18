#include<iostream>
#include<vector>

using namespace std;

int n;
int m;
vector<int> v;
int dp[2001][2001];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    v.push_back(-1);
    for(int i=1;i<=n;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        dp[i][i] = 1;
    }

    for(int i=1;i<n;i++){ // 파악 갯수
        for(int j=1;j<=n-i;j++){ // 각 경우
            if(v[j] == v[j+i]){
                if(i == 1 || dp[j+1][j+i-1] == 1) // 길이가 2 이거나 j+1,j+i-1일때 펠린드롬이면
                    dp[j][j+i] = 1;
            }
        }
    }

    cin >> m;
    for(int i=0;i<m;i++){
        int s,e;
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }
}