#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int n;
vector<int> v;
int target = 2000000000;
void f1_tp(){
    int s = 0;
    int e = v.size()-1;
    int ans[2] = {-1,-1};

    while(s < e){
        int sum = v[s] + v[e];
        if(abs(sum) < target){
            ans[0] = v[s];
            ans[1] = v[e];
            target = abs(sum);
        }
        if(sum >= 0){
            e--;
        }else{
            s++;
        }
    }
    cout << ans[0] << " " << ans[1] << "\n";
}

void f2_bs(){
    int ans[2] = {-1,-1};
    for(int i=0;i<v.size();i++){
        int idx = lower_bound(v.begin(), v.end(), -v[i]) - v.begin();
        for(int j = idx-1;j<=idx;j++){ // idx-1 vs idx
            if(j == i || j<0 || j>=n)
                continue;
            if(v[j] + v[i] == 0){
                ans[0] = v[j];
                ans[1] = v[i];
                if(ans[0] > ans[1])
                    swap(ans[0], ans[1]);
                cout << ans[0] << " " << ans[1] << "\n";
                return;
            }else{
                if(target <= abs(v[j] + v[i]))
                    continue;
                ans[0] = v[j];
                ans[1] = v[i];
                target = abs(v[j] + v[i]);
            }
        }
    }
    if(ans[0] > ans[1])
        swap(ans[0], ans[1]);
    cout << ans[0] << " " << ans[1] << "\n";
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    //f1_tp(); // two pointer
    f2_bs(); // binary search
}