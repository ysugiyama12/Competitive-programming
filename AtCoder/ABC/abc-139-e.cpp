/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
ll A[1010][1010];
vector<ll> tree[1000010];
int cnt[1000010] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    rep(i,0,N){
        rep(j,0,N-1){
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    
    ll M = N * (N-1) / 2;
    ll idx = 0;
    map<lpair,ll> pos;
    rep(i,0,N){
        rep(j,i+1,N){
            pos[make_pair(i,j)] = idx;
            idx++;
        }
    }
    rep(i,0,N){
        rep(j,0,N-2){
            ll p1 = i, p2 = A[i][j];
            if(p1 > p2) swap(p1, p2);
            ll v1 = pos[make_pair(p1, p2)];
            p1 = i; p2 = A[i][j+1];
            if(p1 > p2) swap(p1, p2);
            ll v2 = pos[make_pair(p1, p2)];
            tree[v1].push_back(v2);
            cnt[v2]++;
        }
    }
    stack<ll> st;
    rep(i,0,M){
        if(cnt[i] == 0) st.push(i);
    }
    vector<ll> res;
    ll ans = 0;
    while(not st.empty()){
        ans++;
        ll sz = st.size();
        vector<ll> v;
        rep(i,0,sz){
            ll t = st.top();
            res.push_back(t);
            st.pop();
            v.push_back(t);
        }
        for(auto &e: v){
            for(auto &e2: tree[e]){
                cnt[e2]--;
                if(cnt[e2] == 0) st.push(e2);
            }
        }
    }
    if(res.size() != M){
        print(-1);
    }else{
        print(ans);
    }
}