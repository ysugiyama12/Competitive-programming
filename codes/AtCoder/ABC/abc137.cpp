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
struct compare{
    bool operator() (lpair l1, lpair l2){
         if(l1.second == l2.second){
             return l1.first < l2.first;
         }
         return l1.second < l2.second;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll A[100010], B[100010];
    rep(i,0,N) cin >> A[i] >> B[i];
    rep(i,0,N) A[i] = M - A[i];
    vector<lpair> lp;
    rep(i,0,N) lp.push_back(make_pair(A[i], B[i]));
    sort(lp.begin(), lp.end(), greater<lpair>());
    ll ans = 0;
    priority_queue<lpair, vector<lpair>, compare> pq;
    priority_queue<lpair, vector<lpair>, compare > pq2;
    rep(i,0,N) pq.push(lp[i]);
    sort(lp.begin(), lp.end(), greater<lpair>());
    ll idx = 0;
    // rep(i,0,N) print2(lp[i].first, lp[i].second);
    rrep(i,M,0){
        while(!pq2.empty()){
            lpair l1 = pq2.top();
            // print2(l1.first, l1.second);
            ans += l1.second;
            pq2.pop();
            break;
        }
        while(idx < N && lp[idx].first >= i-1){
            pq2.push(lp[idx]);
            idx++;
        }

    }
    print(ans);
    
}