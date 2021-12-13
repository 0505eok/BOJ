#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
    string str = "";
    cin >> str;
    vector<int> num;
    vector<char> op;
    string tmp = "";
    for(int i=0;i<str.size();i++){
        if(str[i] == '+' || str[i] == '-'){
            op.push_back(str[i]);
            num.push_back(stoi(tmp));
            tmp = "";
        }else{
            tmp += str[i];
        }
    }
    num.push_back(stoi(tmp));

    int ans = num[0];
    int flag = 0;
    for(int i=0;i<op.size();i++){
        if(op[i] == '-'){
            flag = 1;
        }
        if(flag == 1){
            ans -= num[i+1];
        }else{
            ans += num[i+1];
        }
    }
    cout << ans << "\n";
//
//    int ans = num[0];
//    for(int i=0;i<op.size();i++){
//        if(op[i] == '-'){
//            int a = num[i+1];
//            while(op[i+1] == '+') {
//                i++;
//                a += num[i+1];
//            }
//            ans -= a;
//        }else{
//            ans += num[i+1];
//        }
//    }
//    cout << ans << "\n";

    return 0;
}
