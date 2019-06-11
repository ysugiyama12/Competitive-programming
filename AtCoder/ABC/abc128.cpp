#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const int INF = 1e9;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
typedef struct{
    ll S;
    ll T;
    ll X;
} P;

bool comp(P p1, P p2){
    return p1.X > p2.X;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,Q;
    cin >> N >> Q;
    ll S[200010], T[200010], X[200010];
    ll D[200010];
    rep(i,0,N){
        cin >> S[i] >> T[i] >> X[i];
        T[i]--;
    }
    rep(i,0,Q){
        cin >> D[i];
    }
    ll pos[200010];
    memset(pos, -1, sizeof(pos));
    vector<P> lp;
    rep(i,0,N){
        P tmp = {S[i], T[i], X[i]};
        lp.push_back(tmp);
    }
    sort(lp.begin(), lp.end(), comp);
    vector<lpair> ans;
    rep(i,0,N){
        ll s = lp[i].S;
        ll t = lp[i].T;
        ll x = lp[i].X;
        if(s < x) s = x;
        if(t < x) t = x;
        ll ss = max(0LL, s - x);
        ll tt = max(0LL, t - x);
        ll p1 = lower_bound(D, D+Q, ss) - D;
        ll p2 = upper_bound(D, D+Q, tt) - D;
        ans.push_back(make_pair(p1,p2));
    }
    reverse(ans.begin(), ans.end());
    set<ll> st;
    rep(i,0,Q) st.insert(i);
    rep(i,0,N){
        auto it1 = st.lower_bound(ans[i].first);
        auto it2 = st.upper_bound(ans[i].second-1);
        while(it1 != it2){
            auto it_tmp = it1;
            ll v = *it_tmp;
            pos[v] = lp[N-1-i].X;
            it_tmp++;
            st.erase(it1);
            it1 = it_tmp;
        }

    }
    rep(i,0,Q) print(pos[i]);
}