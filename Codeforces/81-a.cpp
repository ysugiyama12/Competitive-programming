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
        ll N,X;
        cin >> N >> X;
        string S;
        cin >> S;
        ll ba = 0;
        vector<ll> cnt;
        map<ll,ll> mp;
        rep(i,0,N){
            if(S[i] == '0'){
                ba++;
            }else{
                ba--;
            }
            cnt.push_back(ba);
            mp[ba]++;
        }
        ll ans = 0;
        if(ba == 0 && mp[X] > 0){
            print(-1);
            continue;
        }else if(ba > 0){
            rep(i,0,N){
                if(cnt[i] <= X && (X - cnt[i]) % ba == 0){
                    ans++;
                }
            }
        }else if(ba < 0){
            ll b2 = abs(ba);
            rep(i,0,N){
                if(cnt[i] >= X && (cnt[i] - X) % b2 == 0){
                    ans++;
                } 
            }

        }else{
            rep(i,0,N){
                if(cnt[i] == X) ans++;
            }
        }
        if(X == 0) ans++;
        print(ans);


    }
    

}