#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)

int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    ll T[200010], L[200010], R[200010];
    cin >> N >> M;
    rep(i,0,M){
        cin >> T[i] >> L[i] >> R[i];
        L[i]--; R[i]--;
    }
    set<ll> st;
    rep(i,0,N){
        st.insert(i);
    }
    ll ans = 0;
    rrep(i,M-1,0){
        auto it = st.lower_bound(L[i]);
        while(it != st.end() && *it <= R[i]){
            auto it2 = it;
            ans += T[i];
            it2++;
            st.erase(it);
            it = it2;
        }
    }
    print(ans);


}
