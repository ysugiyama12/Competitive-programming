/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--){
        ll H,W;
        cin >> H >> W;
        string S[65];
        rep(i,0,H) cin >> S[i];
        ll cntA = 0;
        rep(i,0,H){
            rep(j,0,W){
                if(S[i][j] == 'A') cntA++;
            }
        }
        if(cntA == 0){
            print("MORTAL");
            continue;
        }
        if(cntA == H*W){
            print(0);
            continue;
        }
        // 1回
        bool ok = true, ok1 = true, ok2 = true, ok3 = true;
        rep(i,0,H){
            if(S[i][0] == 'P') ok = false;
            if(S[i][W-1] == 'P') ok1 = false;
        }
        rep(j,0,W){
            if(S[0][j] == 'P') ok2 = false;
            if(S[H-1][j] == 'P') ok3 = false;
        }
        if(ok || ok1 || ok2 || ok3){
            print(1);
            continue;
        }
        // ok = false; ok1 = false; ok2 = false; ok3 = false;
        // rep(i,0,H){
        //     if(S[i][0] == 'A') ok = true;
        //     if(S[i][W-1] == 'A') ok1 = true;
        // }
        // rep(j,0,W){
        //     if(S[0][j] == 'A') ok2 = true;
        //     if(S[H-1][j] == 'A') ok3 = true;
        // }
        if(S[0][0] == 'A' || S[0][W-1] == 'A' || S[H-1][0] == 'A' || S[H-1][W-1] == 'A'){
            print(2);
            continue;
        }
        bool end_flg = false;
        rep(i,0,H){
            bool ok_middle = true;
            rep(j,0,W){
                if(S[i][j] == 'P') ok_middle = false;
            }
            if(ok_middle){
                end_flg = true;
            }
        }
        rep(j,0,W){
            bool ok_middle = true;
            rep(i,0,H){
                if(S[i][j] == 'P') ok_middle = false;
            }
            if(ok_middle){
                end_flg = true;
            }
        }
        if(end_flg){
            print(2);
            continue;
        }
        bool is_A = false;
        rep(i,0,H){
            if(S[i][0] == 'A') is_A = true;
            if(S[i][W-1] == 'A') is_A = true;
        }
        rep(j,0,W){
            if(S[0][j] == 'A') is_A = true;
            if(S[H-1][j] == 'A') is_A = true;
        }
        if(is_A){
            print(3);
        }else{
            print(4);
        }

    }
    

}