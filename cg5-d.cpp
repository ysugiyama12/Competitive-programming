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
    ll a[100010], a2[100010];
    rep(i,0,N) cin >> a[i];
    ll m1 = -INF, m2 = INF;
    rep(i,0,N){
        m1 = max(m1, a[i]);
        m2 = min(m2, a[i]);
    }
    if(2*m2 >= m1){
        rep(i,0,N){
            cout << "-1" << " \n"[i==N-1];
            return 0;
        }
    }
    rep(i,0,N) a2[i] = a[i];
    vector<lpair> lp;
    rep(i,0,N) lp.push_back({a[i], i});
    sort(lp.begin(), lp.end(), greater<lpair>());
    vector<lpair> lp2;
    rep(i,0,N) lp2.push_back({(a[i]-1)/2, i});
    sort(lp2.begin(), lp2.end(), greater<lpair>());
    ll idx = 0;
    set<ll> st;
    rep(i,0,N) st.insert(i);
    ll dist[100010] = {};
    rep(i,0,N){
        ll v = lp[i].first;
        ll pos = lp[i].second;
        while(idx < N && lp2[idx].first >= v){
            ll pos2 = lp2[idx].second;
            auto iter = st.lower_bound(pos2);
            ll val = 0;
            if(iter == st.end()){
                val = *st.begin();
            }else{
                val = *iter;
            }
            // print(lp2[idx].second, val, i);
            if(val - pos2 > 0){
                // print(lp2[idx].second, val);
                dist[lp2[idx].second] = val - pos2;
            }else{
                // print(lp2[idx].second, val);
                dist[lp2[idx].second] = N + val - pos2;
            }
            idx++;
        }
        st.erase(pos);
    }
    // printa(dist, N);
    vector<ll> ans;
    ll res = dist[N-1];
    if(res == 0) res = INF;
    rep(i,0,N){
        if(dist[i] != 0) res = min(res, dist[i] + i+1);
    }
    // print(res);
    ans.push_back(res);
    rrep(i,N-2,0){
        if(dist[i] == 0){
            res++;
        }else{
            res = min(res+1, dist[i]);
        }
        ans.push_back(res);
    }
    reverse(ans.begin(), ans.end());
    printa(ans, N);

}