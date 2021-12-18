#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v, w;
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        v.push_back(m);
        w.push_back(m);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i=0;i<w.size();i++){
        cout << lower_bound(v.begin(), v.end(), w[i]) - v.begin() << " ";
    }
    cout << "\n";

    return 0;
}


//int main() {
//    int n;
//    cin >> n;
//    map<int,int> ma;
//    vector<int> v;
//    vector<int> w;
//    for(int i=0;i<n;i++){
//        int m;
//        cin >> m;
//        v.push_back(m);
//        w.push_back(m);
//    }
//
//    sort(v.begin(), v.end());
//
//    int cnt = 0;
//    for(int i=0;i<v.size();i++){
//        if(ma.find(v[i]) == ma.end()){
//            ma.insert(make_pair(v[i], cnt));
//            cnt++;
//        }
//    }
//
//    for(int i=0;i<w.size();i++){
//        cout << ma[w[i]] << " ";
//    }
//    cout << "\n";
//
//    return 0;
//}
