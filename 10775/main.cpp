#include <iostream>
#include <vector>

using namespace std;
int g,p;
int arr[100001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> g >> p;

    vector<int> v;
    for(int i=0;i<p;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    int cnt = 0;
    for(int i=0;i<v.size();i++){
        int x = v[i];
        arr[x]++;
        if(arr[x] == 1) {
            cnt++;
            continue;
        }
        while(1){
            x = x-arr[x]+1;
            if(x <=0){
                cout << cnt << "\n";
                return 0;
            }
            arr[x]++;
            if(arr[x] == 1){
                cnt++;
                break;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
