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
mt19937 mrand(random_device{}());

void calc(string ss){
    ll n = ss.size();
    vector<ll> cur;
    rep(i,0,n) cur.push_back(ss[i] - '1');
    rrep(t,n-1,1){
        vector<ll> nxt;
        rep(i,0,t){
            nxt.push_back(abs(cur[i] - cur[i+1]));
        }
        cur = nxt;
        // printa(cur, t);
    }
    if(cur[0] == 1) print(ss);
    // print(cur[0]);
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string A;
    cin >> A;
    // ll T = 10;
    ll M = N-1;
    ll cnt2 = 0;
    rep(i,0,N){
        if(A[i] == '2') cnt2++;
    }
    bool check[1000010] = {};
    check[0] = true;
    check[N-1] = true;
    rep(i,1,N-1){
        if((M&i) == i){
            check[i] = true;
        }else{
            check[i] = false;
        }
    }
    ll cnt = 0;
    if(cnt2 == 0){
        rep(i,0,N){
            if(check[i] == true && A[i] == '3') cnt++;
        }
        if(cnt % 2 == 1){
            print(2);
        }else{
            print(0);
        }
    }else{
        rep(i,0,N){
            if(check[i] == true && (A[i] - '0') % 2 == 1) cnt++;
        }
        if(cnt % 2 == 1){
            print(1);
        }else{
            print(0);
        }
    }

    // while(T--){
    //     ll N = 5;
    //     string ss = "";
    //     rep(i,0,N){
    //         ll r = mrand() % 2;
    //         ss += to_string(r);
    //     }
    //     calc(ss);
    // }
    // rep(bit,0,(1LL<<10)){
    //     string ss = "";
    //     rep(i,0,10){
    //         if((bit>>i) & 1) ss += '1';
    //         else ss += '0';
    //     }
    //     reverse(ss.begin(), ss.end());
    //     calc(ss);
    // }
    // ll n = 22;
    // rep(i,0,n){
    //     string ss = "";
    //     rep(j,0,n){
    //         if(i == j){
    //             ss += '1';
    //         }else{
    //             ss += '0';
    //         }
    //     }
    //     calc(ss);
    // }

    

}