#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
#define INF (1e18)
int main(){ 
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,K;
    ll A[100010], B[100010];
    cin >> N >> M >> K;
    rep(i,0,N) cin >> A[i];
    rep(i,0,M) cin >> B[i];
    sort(A, A+N);
    sort(B, B+M);
    ll lv = -1, rv = INF;
    while(rv - lv > 1){
        ll mid = (rv + lv) / 2;
        ll cnt = 0;
        ll nn = 0, mm = 0;
        while(nn < N && mm < M){
            if(abs(A[nn] - B[mm]) <= mid){
                nn++; mm++; cnt++;
            }else if(A[nn] < B[mm]){
                nn++;
            }else{
                mm++;
            }
        }
        // ll check[100010] = {};
        // multiset<ll> ms;
        // rep(i,0,M) ms.insert(B[i]);
        // rep(i,0,N){
        //     auto iter = ms.upper_bound(A[i] + mid);
        //     if(iter == ms.begin()) continue;
        //     iter--;
        //     // print(*iter);
        //     if(abs(A[i] - *iter) <= mid){
        //         ms.erase(iter);
        //         cnt++;
        //     }
        // }
        if(cnt >= K){
            rv = mid;
        }else{
            lv = mid;
        }   
    }
    print(rv);
}