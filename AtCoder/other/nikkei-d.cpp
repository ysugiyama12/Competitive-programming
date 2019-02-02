#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
ll N,M;
ll A[200010], B[200010];
vector<ll> tree[100010];
vector<ll> tree_inv[100010];
ll h[100010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,0,N-1+M){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        tree[A[i]].push_back(B[i]);
        h[B[i]]++;
        tree_inv[B[i]].push_back(A[i]);
    }
    stack<ll> st;
    rep(i,0,N){
        if(h[i] == 0){
            st.push(i);
        }
    }
    vector<ll> ans;
    while(st.size()){
        ll k = st.top();
        st.pop();
        ans.push_back(k);
        for(auto &e: tree[k]){
            h[e]--;
            if(h[e] == 0) st.push(e);
        }
    }

    map<ll,ll> mp;
    rep(i,0,N){
        mp[ans[i]] = i;
    }
    ll v[100010] = {};
    rep(i,0,N){
        if(mp[i] == 0){
            v[i] = -1;
        }else{
            ll val = -1;
            ll tt = -1;
            for(auto &e: tree_inv[i]){
                if(val < mp[e]){
                    val = mp[e];
                    tt = e;
                }
            }
            v[i] = tt;
        }
    }
    rep(i,0,N){
        print(v[i]+1);
    }

}
