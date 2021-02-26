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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K,Q;
    cin >> N >> K >> Q;
    vector<ll> A(2010);
    ll a2[2010];
    rep(i,0,N) cin >> A[i];
    rep(i,0,N) a2[i] = A[i];
    sort(a2, a2+N);
    // SegmentTree st(A);
    ll ans = INF;
    rep(i,0,N){
        ll X = A[i];
        bool ok[2010];
        rep(j,0,N){
            if(A[j] < X){
                ok[j] = false;
            }else{
                ok[j] = true;
            }
        }
        vector<lpair> pos;
        ll v = 0;
        rep(j,0,N){
            if(not ok[j]){
                if(v != 0) pos.push_back(make_pair(v, j-1));
                v = 0;
            }else{
                v++;
            }
        }
        if(v != 0) pos.push_back(make_pair(v, N-1));
        ll cnt = 0;
        rep(j,0,pos.size()){
            cnt += max(0LL, pos[j].first - K+1);
        }
        if(cnt >= Q){
            vector<ll> tt;
            for(auto &e: pos){
                if(e.first < K) continue;
                vector<ll> tmp;
                rep(k,e.second-e.first+1, e.second+1){
                    tmp.push_back(A[k]);
                }
                
                sort(tmp.begin(), tmp.end());
                rep(k,0,e.first- K+1){
                    tt.push_back(tmp[k]);
                }
            }
            sort(tt.begin(), tt.end());
            ll Y = tt[Q-1];
            ans = min(ans, Y-X);
        }
    }
    print(ans);




    
}