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
ll A[200010], B[200010];
ll cntA[200010] = {}, cntB[200010] = {};
vector<ll> pos[200010];

void solve(){
    ll N;
    cin >> N;
    rep(i,0,N) cin >> A[i];
    rep(i,0,N) cin >> B[i];
    rep(i,0,N){
        pos[A[i]].push_back(i);
    }

    rep(i,0,N){
        cntA[A[i]]++;
        cntB[B[i]]++;
    }
    rep(i,0,N+1){
        if(cntA[i] + cntB[i] > N){
            print("No");
            return;
        }
    }
    vector<lpair> lp;
    rep(i,0,N+1){
        if(cntA[i] > 0 && cntB[i] > 0){
            lp.push_back({N - cntA[i] - cntB[i], i});
        }
    }

    sort(lp.begin(), lp.end(), [&](lpair l1, lpair l2){
        if(l1.first == l2.first){
            return cntB[l1.second] < cntB[l2.second];
        }
        return l1.first < l2.first;
    });

    queue<ll> que;
    vector<lpair> v;
    if(lp.size() == 0){
        print("Yes");
        printa(B,N);
        return;
    }
    rep(i,0,N){
        if(A[i] != lp[0].second){
            v.push_back({N- cntB[A[i]], i});
        }
    }
    sort(v.begin(), v.end());
    for(auto &e: v){
        que.push(e.second);
    }
    ll ans[200010] = {};
    ll idx = 0;
    for(auto &e: lp){
        // print(e.second);
        // printa(ans, N);
        ll n = cntB[e.second];
        vector<ll> mine;
        while(n--){
            ll q;
            while(true){
                q = que.front();
                if(A[q] == e.second){
                    que.push(q);
                    que.pop();
                }else{
                    que.pop();
                    break;
                }
            }
            // ll q = que.front();
            // if(A[q] == e.second){

            // }
            // que.pop();
            ans[q] = e.second;
        }
        if(idx == 0){
            for(auto &f: pos[e.second]){
                if(ans[f] == 0){
                    que.push(f);
                }
            }
        }
        idx++;
    }
    stack<ll> st;

    rep(i,0,N){
        if(cntA[B[i]] == 0 && cntB[B[i]] > 0){
            st.push(B[i]);
        }
    }
    rep(i,0,N){
        if(ans[i] == 0){
            ans[i] = st.top();
            st.pop();
        }
    }
    print("Yes");
    printa(ans, N);

    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
