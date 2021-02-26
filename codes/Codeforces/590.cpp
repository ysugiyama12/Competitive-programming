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
ll cnt_left[200010] = {}, cnt_right[200010] = {};
ll sum_left[200010] = {}, sum_right[200010] = {};
ll cnt[200010] = {};
vector<ll> v[200010];
ll x[200010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    rep(i,0,M) cin >> x[i];
    ll sum = 0;
    rep(i,0,M-1){
        sum += abs(x[i] - x[i+1]);
        v[x[i]].push_back(x[i+1]);
        v[x[i+1]].push_back(x[i]);
        ll a = x[i], b = x[i+1];
        if(abs(a - b) <= 1) continue;
        if(a > b) swap(a,b);
        cnt[a+1]++; cnt[b]--;
    }
    rep(i,0,N+1) cnt[i+1] += cnt[i];
    rep(i,1,N+1){
        for(auto &e: v[i]){
            if(e < i){
                sum_left[i] += abs(e-i);
                cnt_left[i]++;
            }else if(e > i){
                sum_right[i] += abs(e-i);
                cnt_right[i]++;
            }
        }
    }
    vector<ll> res;
    rep(i,1,N+1){
        if(i == 1){
            res.push_back(sum);
        }else{
            ll diff = i;
            ll ans = sum - cnt[i];
            ans += diff * cnt_left[i] - 2 * sum_left[i];
            ans += (i - 1) * cnt_right[i];
            res.push_back(ans);
        }
    }
    printa(res, N);

    
    
    

}