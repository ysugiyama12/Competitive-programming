/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> lpair;
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
    string S;
    cin >> S;
    vector<ll> pa, pb;
    pa.push_back(-1);
    pb.push_back(-1);
    rep(i,0,N){
        if(S[i] == 'A'){
            pa.push_back(i);
        }else{
            pb.push_back(i);
        }
    }
    pa.push_back(N);
    pb.push_back(N);
    ll ans = N * (N-1) / 2;;
    rep(i,0,N){
        if(S[i] == 'A'){
            ll p = lower_bound(pa.begin(), pa.end(), i) - pa.begin();
            ll lv = i - pa[p-1] - 1;
            ll rv = pa[p+1] - i - 1;
            ans -= lv+rv;

        }else{
            ll p = lower_bound(pb.begin(), pb.end(), i) - pb.begin();
            ll lv = i - pb[p-1] - 1;
            ll rv = pb[p+1] - i - 1;
            ans -= lv+rv;
        }
    }
    rep(i,0,N-1){
        if(S[i] != S[i+1]) ans++;
    }
    print(ans);


    

}