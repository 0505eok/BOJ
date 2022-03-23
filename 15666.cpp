#include<iostream>
#include<vector>
#include<set>
using namespace std;

int n,m;
set<int> s;
vector<string> ans;
void dfs(set<int>::iterator it, int cur, string str){
    if(cur == m){
        ans.push_back(str);
        return;
    }

    for(auto iter = it;iter != s.end();iter++){
        string tmp = str;
        tmp += ' ';
        tmp += to_string(*iter);
        dfs(iter, cur+1, tmp);
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    for(auto iter=s.begin(); iter != s.end(); iter++){
        string str = to_string(*iter);
        dfs(iter, 1, str);
    }

    for(int i=0;i<ans.size();i++)
        cout << ans[i] << "\n";
}