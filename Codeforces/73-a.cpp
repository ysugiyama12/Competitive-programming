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
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    while(Q--){
        ll N;
        cin >> N;
        ll s[110];
        rep(i,0,N) cin >> s[i];
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        rep(i,0,N) pq.push(s[i]);
        bool ok = false;
        while(not pq.empty()){
            if(pq.size() == 1) break;
            ll p1 = pq.top();
            pq.pop();
            ll p2 = pq.top();
            if(p1 == 2048){
                ok = true;
                break;
            }else{
                if(p1 == p2){
                    pq.pop();
                    pq.push(p1*2);
                }else{
                    continue;
                }
            }
        }
        if(ok){
            print("YES");
        }else if(pq.top() == 2048){
            print("YES");
        }else{
            print("NO");
        }
    }
}