#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> num;
vector<char> op;

void cal(){
    if(op.size() != 0 && (op[op.size()-1] == '*' || op[op.size()-1] == '/')){
        string en = num[num.size()-1];
        num.pop_back();
        string st = num[num.size()-1];
        num.pop_back();
        string ret = st + en + op[op.size()-1];
        num.push_back(ret);
        op.pop_back();
    }
    return;
}

int main(){
    string str;
    cin >> str;

    for(int i=0;i<str.size();i++){
        if(str[i] >= 'A' && str[i] <= 'Z') {
            string tmp = "";
            tmp += str[i];
            num.push_back(tmp);
            cal();
        }else{
            if(str[i] == ')') {
                vector<string> nn;
                vector<char> oo;
                char cur = op[op.size()-1];
                nn.push_back(num[num.size()-1]);
                num.pop_back();
                while(cur != '('){
                    nn.push_back(num[num.size()-1]);
                    num.pop_back();
                    oo.push_back(cur);
                    op.pop_back();
                    cur = op[op.size()-1];
                }
                op.pop_back();
                string tmp = nn[nn.size()-1];
                nn.pop_back();
                while(!nn.empty()){
                    tmp += nn[nn.size()-1];
                    nn.pop_back();
                    tmp += oo[oo.size()-1];
                    oo.pop_back();
                }
                num.push_back(tmp);
                cal();
            }else{
                op.push_back(str[i]);
            }
        }
    }

    string ans = num[0];
    for(int i=1;i<num.size();i++){
        ans += num[i];
        ans += op[i-1];
    }

    cout << ans << "\n";
}