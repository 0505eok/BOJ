#include<iostream>
#include<vector>

using namespace std;

int N,M,T;
int num[51][51];
int checked[51][51];
int cur[51];
vector<pair<int,pair<int,int>>> v;

void solution(){
    for(int i=0;i<v.size();i++){
        int x = v[i].first;
        int d = v[i].second.first == 0 ? -1 : 1;
        int k = v[i].second.second;
        d *= k;
        d %= M;
        if(d < 0)
            d += M;
        for(int j=x;j<=N;j+=x) { // 회전
            cur[j] += d;
            cur[j] %= M;
            if(cur[j] == 0)
                cur[j] = M;
        }

        for(int j=1;j<=N;j++){
            for(int l=1;l<=M;l++){
                if(checked[j][l] != 0 && checked[j][l] != i+1)
                    continue;
                for(int ll=-1;ll<2;ll+=2){
                    int idx = l + ll;
                    if(idx == 0)
                        idx = M;
                    if(idx == M+1)
                        idx = 1;
                    if(checked[j][idx] != 0 && checked[j][idx] != i+1)
                        continue;
                    if(num[j][l] == num[j][idx]) {
                        checked[j][l] = i + 1;
                        break;
                    }
                }
            }
        }

        for(int j=1;j<=M;j++){
            for(int l=1;l<=N;l++){
                int a = cur[l] + j;
                a %= M;
                if(a == 0)
                    a = M;
                if(checked[l][a] != 0 && checked[l][a] != i+1)
                    continue;
                for(int ll = -1;ll<2;ll+=2){
                    int idx = l + ll;
                    if(idx == 0 || idx == N+1)
                        continue;
                    int b = cur[idx] + j;
                    b %= M;
                    if(b == 0)
                        b = M;
                    if(checked[idx][b] != 0 && checked[idx][b] != i+1)
                        continue;
                    if(num[l][a] == num[idx][b]){
                        checked[l][a] = i+1;
                        break;
                    }
                }
            }
        }

        int flag = 0;
        int total = 0;
        int cnt = 0;
        for(int ii=1;ii<=N;ii++){
            for(int j=1;j<=M;j++){
                if(checked[ii][j] == i+1)
                    flag = 1;
                if(checked[ii][j] != 0)
                    continue;
                total += num[ii][j];
                cnt++;
            }
        }
        if(flag == 1)
            continue;

        for(int ii=1;ii<=N;ii++){
            for(int j=1;j<=M;j++){
                if(checked[ii][j] != 0)
                    continue;
                if((double)num[ii][j] > (double)total/(double)cnt)
                    num[ii][j]--;
                else if((double)num[ii][j] < (double)total/(double)cnt)
                    num[ii][j]++;
            }
        }
    }

    int ans = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(checked[i][j] != 0)
                continue;
            ans += num[i][j];
        }
    }
    cout << ans << "\n";
}

int main(){
    cin >> N >> M >> T;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            int m;
            cin >> m;
            num[i][j] = m;
        }
    }

    for(int i=0;i<T;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back({a,{b,c}});
    }

    solution();
}