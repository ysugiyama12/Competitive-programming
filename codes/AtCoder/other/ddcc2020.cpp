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
    ll M;
    cin >> M;
    ll d[200010], c[200010];
    rep(i,0,M) cin >> d[i] >> c[i];
    ll ans = 0;
    rep(i,0,M){
        ll val = (c[i] - 1) + max(0LL, (d[i] * c[i] - 1) / 9);
        ans += val;
    }
    vector<ll> nxt[10];
    rep(n,0,10){
        ll cur = n;
        nxt[n].push_back(cur);
        while(1){
            cur += n;
            if(cur >= 10){
                cur = cur / 10 + cur % 10;
            }
            // print(n, cur);
            if(cur == nxt[n][0]) break;
            nxt[n].push_back(cur);
        }
    }
    ll num[200010] = {};
    rep(i,0,M){
        ll sz = nxt[d[i]].size();
        ll amari = c[i] % sz;
        if(amari == 0){
            num[i] = nxt[d[i]][sz-1];
        }else{
            num[i] = nxt[d[i]][amari-1];
        }
    }
    // printa(num, M);
    // rep(i,0,10){
    //     rep(j,0,nxt[i].size()){
    //         cout << nxt[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // print(ans);
    ll idx = 0;
    while(idx != M-1){
        ll v1 = num[idx];
        ll v2 = num[idx+1];
        ll v3 = v1 + v2;
        ans++;
        if(v3 >= 10){
            num[idx] = v3 / 10;
            num[idx+1] = v3 % 10;
        }else{
            num[idx+1] = v3;
            idx++;
        }
    }

    print(ans);
    // vector<ll> v;
    // ll sum = 0;
    // while()
    // rep(i,0,M) sum += num[i];
    // ans += (M-1) + sum / 10;

    // print(ans);

    

}