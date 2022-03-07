#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(){
    string str;
    cin >> str;

    string bomb;
    cin >> bomb;

    vector<char> s;
    for(int i=0;i<str.size();i++){
        s.push_back(str[i]);
        int p = bomb.size()-1;
        int cur = s.size()-1;
        while(s.size() != 0 && bomb[p] == s[cur]){
            p--;
            cur--;
            if(p == -1) {
                for(int j=0;j<bomb.size();j++)
                    s.pop_back();
                break;
            }
        }
    }

    if(s.size() == 0)
        cout << "FRULA\n";
    else{
        string ans = "";
        for(int i=0;i<s.size();i++)
            ans += s[i];
        cout << ans << "\n";
    }

}