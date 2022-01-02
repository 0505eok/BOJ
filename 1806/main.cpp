#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, s;
    cin >> n >> s;

    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    int l = 0;
    int r = 0;
    int sum = v[0];
    int ans = 100001;

    while(1){
        if(sum >= s) {
            ans = min(ans, r-l+1);
            if(l == r){
                break;
            }else {
                sum -= v[l];
                l++;
            }
        }else {
            r++;
            if(r >= v.size())
                break;
            sum += v[r];
        }
    }

    if(ans == 100001)
        ans = 0;
    cout << ans << "\n";
    return 0;
}
