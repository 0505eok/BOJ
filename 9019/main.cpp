#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int D(int n){
    return (n*2)%10000;
}

int S(int n){
    return (n-1+10000)%10000;
}

int L(int n){
    return (n%1000)*10 + n/1000;
}

int R(int n){
    return (n/10) + (n%10)*1000;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    vector<string> ans;
    for(int i=0;i<n;i++){
        int s1, s2;
        cin >> s1 >> s2;
        v.push_back(make_pair(s1,s2));
    }

    char func[4] = {'D','S','L','R'};
    int res[10000][4];
    for(int i=0;i<10000;i++){
        res[i][0] = D(i);
        res[i][1] = S(i);
        res[i][2] = L(i);
        res[i][3] = R(i);
    }

    for(int i=0;i<v.size();i++){
        vector<int> visited(10000);
        queue<pair<int, string>> q;
        int a = v[i].first;
        int b = v[i].second;
        q.push(make_pair(a,""));
        visited[a] = 1;
        while(!q.empty()){
            int num = q.front().first;
            string acc = q.front().second;
            q.pop();
            if(num == b){
                ans.push_back(acc);
                break;
            }
            for(int j=0;j<4;j++){
                if(visited[res[num][j]] == 1)
                    continue;
                visited[res[num][j]] = 1;
                q.push(make_pair(res[num][j], acc + func[j]));
            }
        }
    }

    for(int i=0;i<ans.size();i++)
        cout << ans[i] << "\n";
    return 0;
}
