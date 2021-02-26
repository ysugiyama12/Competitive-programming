#include <bits/stdc++.h>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
typedef struct{
    ll T;
    ll prev;
    ll next;

} pp;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,X;
    cin >> N >> X;
    ll T[5010];
    rep(i,0,N){
        cin >> T[i];
    }
    ll sum = X;
    ll v[5010] = {};
    rep(i,1,N){
        sum += min(X, T[i]-T[i-1]);
    }
    v[N-1] = sum;
    ll checked[5010] = {};
    vector<pp> st;
    rep(i,0,N){
        pp P = {T[i], i-1,i+1};
        st.push_back(P);
    }
    rep(i,0,N) checked[i] = 1;
    rrep(i,N-2,0){
        ll pos = -1;
        ll val = -INF;
        rep(j,0,N){
            if(checked[j] == 0) continue;
            ll ps = st[j].prev;
            ll ns = st[j].next;
            ll val_tmp;
            if(ns == N && ps == -1){
                val_tmp = 0;
            }else if(ns == N){
                val_tmp = -min(X,st[j].T-st[ps].T);
            }else if(ps == -1){
                val_tmp = -min(X,st[ns].T-st[j].T);
            }else{
                val_tmp = -min(X,st[j].T-st[ps].T) - min(X,st[ns].T-st[j].T) + min(X, st[ns].T-st[ps].T);
                // print(-min(X,st[j].T-st[ps].T));
                // print(- min(X,st[ns].T-st[j].T));
                // print(st[ns].T-st[ps].T);
            }
            // print2("j=",j);
            // print(val_tmp);
            if(val_tmp > val){
                pos = j;
                val = val_tmp;
            }
            

            // if(checked[j] == 0) continue;
            // checked[j] = 0;
            // ll prev_val = T[0];
            // ll val_tmp = X;
            // rep(k,1,N){
            //     if(checked[k] == 0) continue;
            //     ll dist = T[k] - prev_val;
            //     prev_val = T[k];
            //     val_tmp += min(dist, X);
            // }
            // if(val_tmp > val){
            //     val = val_tmp;
            //     pos = j;
            // }
            // checked[j] = 1;
        }
        checked[pos] = 0;
        if(st[pos].prev >= 0){
            st[st[pos].prev].next = st[pos].next;
        } 
        if(st[pos].next <= N-1){
            st[st[pos].next].prev = st[pos].prev;
        }
        v[i] = v[i+1]+val;
    }
    rep(i,0,N){
        print(v[i]);
    }


    
}
