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

// verify: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=ja
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string T,P;
    cin >> T >> P;
    ll nt = T.size(), np = P.size();
    map<char, ll> table;
    map<char, bool> mp;
    rep(i,0,np){
        table[P[i]] = np - i - 1;
        mp[P[i]] = true;
    }
    ll i = np-1, p = 0;
    ll cnt = 0;
    while(i < nt){
        p = np-1;
        ll sz = 0;
        while(p >= 0 && i < nt){
            if(T[i] == P[p]){
                i--; p--;
                sz++;
            }else{
                break;
            }
        }

        if(p < 0){
            print(i+1);
        }
        ll v1 = mp[P[p]] ? table[P[p]] : np;
        ll v2 = np - p;
        // if(p < 0){
        //     print(v1,v2);
        // }
        // print(max(v1,v2));
        i += max(v1, v2);
        i += np;
        print(i, sz, max(v1,v2));
    }
    print(cnt);
    // print(-1);

}