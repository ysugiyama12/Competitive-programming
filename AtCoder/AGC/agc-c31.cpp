#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
#define INF (1e18)
vector<ll> tree[1LL<<18];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,A,B;
    cin >> N >> A >> B;
    ll nn = (1LL<<N);
    rep(bit,0,nn){
        rep(i,0,N){
            if((bit >> i) & 1){
                ll v = bit - (1LL<<i);
                tree[bit].push_back(v);
            }else{
                ll v = bit | (1LL<<i);
                tree[bit].push_back(v);
            }
        }
    }
    ll dp[1LL<<18][18] = {};
    rep(i,0,nn){
        rep(j,0,N){
            dp[i][j] = INF;
        }
    }
    // dp[1LL<<A][A] = 0;
    // rep(bit,0,nn){
    //     rep(i,0,N){
    //         if(bit & (1LL<<i)){
    //             rep(j,0,N){
    //                 if(dp[bit|(1<<j)] > dp[bit][j] + 1){

    //                 }
    //             }
    //         }


    //     }
    // }
    if(dp[nn-1][B] == INF){
        print("NO");
    }else{
        print("YES");
    }
    // bool ok1 = true;
    // rep(i,0,nn){
    //     if(tree[i].size() % 2 == 1){
    //         ok1= false;
    //     }
    // }
    // bool ok2 = true;
    // rep(i,0,nn){
    //     if(i == A || i == B){
    //         if(tree[i].size() % 2 == 0) ok2 = false;
    //     }else{
    //         if(tree[i].size() % 2 == 1) ok2 = false;
    //     }
    // }
    // if(ok1 || ok2){
    //     print("YES");
    // }else{
    //     print("NO");
    // }
    // rep(i,0,nn){
    //     print2("---", i);
    //     for(auto &e: tree[i]){
    //         print(e);
    //     }
    // }
    
}