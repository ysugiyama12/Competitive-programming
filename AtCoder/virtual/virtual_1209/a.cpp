#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    string S;
    cin >> N;
    cin >> S;
    ll sn = S.size();
    vector<ll> ss;
    ll num = 0;
    rep(i,0,sn){
        if(S[i] == 'A'){
            num++;
        }else{
            if(num != 0){
                ss.push_back(num);
                num = 0;
            }
        }
    }
    if(num != 0){
        ss.push_back(num);
    }
    // printa(ss, ss.size());
    ll tt = ss.size();
    if(tt == 0){
        print(0);
        return 0;
    }
    // printa(ss,tt);
    ll ans = 0;
    // print(S[0]);
    // print(S[sn-1]);
    if(S[0] == 'A' && S[sn-1] == 'A'){
        if(tt == 1){
            ll val = N * sn;
            ans = val * (val+1) / 2;
        }else{
            rep(i,1,tt-1){
                ans += N * ss[i] * (ss[i]+ 1)/2;
            }
            ans += ss[0] * (ss[0] + 1)/2;
            ans += ss[tt-1] * (ss[tt-1]+1)/2;
            ans += (N-1) * (ss[0]+ss[tt-1]) * (ss[0]+ss[tt-1]+1)/2;
        }
    }else{
        rep(i,0,tt){
            ans += N * ss[i] * (ss[i]+1)/2;
        }
    }
    print(ans);
    // if(tt == 0){
    //     print(0);
    //     return 0;
    // }else if(tt == 1){
    //     ll val = 
    //     ans += 

    // }
    // if(tt == 1){

    // }


    // ll pos = 0;
    // bool is_A = false;
    // if(S[0] == 'A'){
    //     pos = 0;
    // }else{
    //     pos = 1;
    // }
    // rep(i,0,sn){
    //     if(is_A && S[i] == 'B'){
    //         is_A = false;

    //     }

    // }


}
