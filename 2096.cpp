#include<iostream>
#include<algorithm>
using namespace std;

int v[3];
int dp[3];
int dp2[3];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++)
            cin >> v[j];
        if(i == 0){
            dp[0] = v[0];
            dp[1] = v[1];
            dp[2] = v[2];

            dp2[0] = v[0];
            dp2[1] = v[1];
            dp2[2] = v[2];
        }else{
            int a1,a2;
            int b1,b2;
            int c1,c2;
            a1 = v[0] + max(dp[0],dp[1]);
            a2 = v[0] + min(dp2[0],dp2[1]);

            int tmp = max(dp[0],dp[1]);
            int tmp2 = min(dp2[0],dp2[1]);
            b1 = v[1] + max(tmp, dp[2]);
            b2 = v[1] + min(tmp2, dp2[2]);

            c1 = v[2] + max(dp[1],dp[2]);
            c2 = v[2] + min(dp2[1],dp2[2]);

            dp[0] = a1;
            dp[1] = b1;
            dp[2] = c1;

            dp2[0] = a2;
            dp2[1] = b2;
            dp2[2] = c2;
        }

    }

    int cur = max(dp[0], dp[1]);
    cur = max(cur, dp[2]);

    int cur2 = min(dp2[0], dp2[1]);
    cur2 = min(cur2, dp2[2]);

    cout << cur << " " << cur2 << "\n";
}