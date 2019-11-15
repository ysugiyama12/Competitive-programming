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
    ll N,K;
    cin >> N >> K;
    ll A[200010];
    rep(i,0,N) cin >> A[i];
    vector<ll> pos[200010];
    rep(i,0,N) pos[A[i]].push_back(i);
    ll cur = 0;
    ll cnt = 0;
    while(1){
        if(cur == N) break;
        ll num = A[cur];
        ll p = upper_bound(pos[num].begin(), pos[num].end(), cur) - pos[num].begin();
        if(p == pos[num].size()){
            p = 0;
            cnt++;
        }
        // print(cur, pos[num][p]);
        cur = pos[num][p]+1;
    }
    cnt++;
    ll k = K % cnt;
    // print(k);
    cur = 0;
    cnt = 0;
    ll start = -1;
    while(1){
        if(cur == N) break;
        ll num = A[cur];
        ll p = upper_bound(pos[num].begin(), pos[num].end(), cur) - pos[num].begin();
        if(p == pos[num].size()){
            p = 0;
            cnt++;
            if(cnt == k){
                start = cur;
                break;
            }
        }
        // print(cur, pos[num][p]);
        cur = pos[num][p]+1;
    }
    if(start == -1){
        return 0;
    }
    // print(start);
    stack<ll> res;
    map<ll,ll> mp;
    rep(i,start,N){
        if(mp[A[i]] == 0){
            res.push(A[i]);
            mp[A[i]]++;
        }else{
            while(mp[A[i]] > 0){
                ll v1 = res.top();
                mp[v1]--;
                res.pop();
            }
        }
    }
    vector<ll> ans;
    while(not res.empty()){
        ans.push_back(res.top());
        res.pop();
    }
    reverse(ans.begin(), ans.end());
    printa(ans, ans.size());


}