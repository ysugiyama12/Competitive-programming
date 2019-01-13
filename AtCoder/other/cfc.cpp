#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << x << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ cout << (x[i]) << " ";} cout << endl;

typedef long long ll;

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,D;
    cin >> N >> D;
    vector<int> X(N);
    rep(i,0,N){ cin >> X[i];}
    
    vector<ll> left(N,0), right(N,0);
    rep(i,0,N){
        if(i != 0){
            int left_i = lower_bound(X.begin(), X.begin()+i, X[i] - D) - X.begin();
            left[i] = i - left_i;
        }
        if(i != N-1){
            int right_i = upper_bound(X.begin()+i+1, X.end(), X[i]+D) - X.begin();
            right[i] = right_i - i - 1;
            
        }
    }
    ll ans_1 = 0;
    ll ans_2 = 0;
    rep(i,0,N){
        ans_1 += left[i] * right[i];
        if(right[i] != 0){
            ans_2 += right[i] * (right[i] - 1) / 2;
        }
    }
    ll ans = ans_1 - ans_2;
    if(ans < 0){
        print(0);
    }else{
        print(ans);
    }

    //while(k != N-1 || j != N-2){
    //    if(X[j] - X[i] <= D && X[k] - X[j] <= D && X[k] - X[i] > D){
    //        ans++;
    //    }
    //    if(X[j] - X[i] > D){
    //        i++;
    //    }else if(j+1 ==
    //    if(pos_k == N-1){
    //        pos_i += 1;
    //        pos_k = pos_i+1;
    //    }else if(X[pos_k] - X[pos_i] > 2*D){
    //        pos_i += 1;
    //    }else{
    //        pos_k += 1;
    //    }

    //}
}
