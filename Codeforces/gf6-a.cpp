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
    ll N;
    cin >> N;
    rep(t,0,N){
        string S;
        cin >> S;
        bool ok = true;
        ll nn = S.size();
        ll cnt[11] = {};
        ll sum = 0;
        ll cnt2 = 0;
        rep(i,0,nn){
            cnt[S[i]-'0']++;
            sum += (S[i] - '0');
            if((S[i] - '0') % 2 == 0) cnt2++;
        }
        if(sum % 3 != 0) ok = false;
        if(cnt[0] <= 0 || cnt2 <= 1){
            ok = false;
        }

        if(ok){
            print("red");
        }else{
            print("cyan");
        }
    }

    

}