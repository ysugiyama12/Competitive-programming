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
    ll t;
    cin >> t;

    rep(tt,0,t){
        ll N;
        // N = tt+1;
        cin >> N;
        ll pos = N;
        ll cur = 1;
        while(pos > 0){
            if(pos <= cur * 3){
                break;
            }else{
                pos -= cur * 3;
                cur *= 4;
            }
        }
        ll a = cur, b = cur * 2, c = cur * 3;
        ll n = cur;
        ll res = 0;
        // print(pos, cur);
        ll abc = (pos-1) % 3;
        pos = (pos-1) / 3;

        while(n > 0){
            ll amari = pos % n;
            if(amari < n/4){
                res += (n/4) * 0;
            }else if(amari < 2 * (n/4)){
                res += (n/4) * 2;
            }else if(amari < 3 * (n/4)){
                res += (n/4) * 3;
            }else{
                res += (n/4) * 1;
            }
            n /= 4;
            if(n == 1) break;
        }
        ll res2 = 0;
        n = cur;
        while(n > 0){
            ll amari = pos % n;
            if(amari < n/4){
                res2 += (n/4) * 0;
            }else if(amari < 2 * (n/4)){
                res2 += (n/4) * 3;
            }else if(amari < 3 * (n/4)){
                res2 += (n/4) * 1;
            }else{
                res2 += (n/4) * 2;
            }
            n /= 4;
            if(n == 1) break;
        }

        if(abc == 0){
            print(a + pos);
        }else if(abc == 1){
            print(b + res);
        }else{
            print(c + res2);
        }

        // bool used[100010] = {};
        // rep(tt,0,500){
        //     ll cur = 1;
        //     rep(i,1,10000){
        //         if(used[cur] == false){
        //             break;
        //         }
        //         cur++;
        //     }
        //     ll nxt = cur+1;
        //     while(1){
        //         if(used[nxt] == true){
        //             nxt++;
        //         }else{
        //             ll v = (cur^nxt);
        //             if(used[v] == true){
        //                 nxt++;
        //             }else{
        //                 break;
        //             }
        //         }
        //     }
        //     print(cur,nxt, (cur^nxt));
        //     if(tt % 4 == 0) print("=====");
        //     used[cur] = true;
        //     used[nxt] = true;
        //     used[cur^nxt] = true;

        // }
    }
    

}