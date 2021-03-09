#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
int n;
unordered_map<string, int> mm;
int f[200002];
int num[200002];
int Find(int i){
    if(f[i] == i)
        return i;

    return f[i] = Find(f[i]);
}
int Union(string s1, string s2){
    int x1 = Find(mm[s1]);
    int x2 = Find(mm[s2]);

    if(x1 == x2)
        return num[x1];

    if(num[x2] >= num[x1]){
        swap(x1,x2);
    }
    num[x1] += num[x2];
    f[x2] = x1;
    return num[x1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        int x = 1;
        for(int j=0;j<m;j++){
            string s1,s2;
            cin >> s1 >> s2;
            if(mm.find(s1) == mm.end()){
                mm.insert(make_pair(s1,x));
                f[x] = x;
                num[x] = 1;
                x++;
            }
            if(mm.find(s2) == mm.end()){
                mm.insert(make_pair(s2,x));
                f[x] = x;
                num[x] = 1;
                x++;
            }
            cout << Union(s1,s2) << "\n";
        }
        mm.clear();
        for(int j=0;j<m;j++){
            f[j] = 0;
            num[j] = 0;
        }
    }
    return 0;
}