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
    ll N,Q;
    cin >> N >> Q;
    ll L[5010], R[5010];
    rep(i,0,Q) cin >> L[i] >> R[i];
    ll pos[5010] = {};
    rep(i,0,Q){
        pos[L[i]]++;
        pos[R[i]+1]--;
    }
    rep(i,0,N+1) pos[i+1] += pos[i];
    ll sum = 0;
    rep(i,1,N+1){
        if(pos[i] != 0) sum++;
    }
    ll cnt1[5010] = {}, cnt2[5010] = {};
    rep(i,1,N+1){
        if(pos[i] == 1){
            cnt1[i]++;
        }else if(pos[i] == 2){
            cnt2[i]++;
        }
    }
    rep(i,0,N+1){
        cnt1[i+1] += cnt1[i];
        cnt2[i+1] += cnt2[i];
    }
    // printa(cnt1, N+1);
    ll ans = 0;
    rep(i,0,Q){
        rep(j,0,Q){
            if(i <= j) continue;
            ll v = sum;
            v -= cnt1[R[i]] - cnt1[L[i]-1];
            v -= cnt1[R[j]] - cnt1[L[j]-1];
            ll v1 = max(L[i], L[j]);
            ll v2 = min(R[i], R[j]);
            if(v1 <= v2){
                v -= cnt2[v2] - cnt2[v1-1];
            }
            ans = max(ans, v);
        }
    }
    // rep(i,0,Q){
    //     rep(j,0,Q){
    //         ll v = sum;
    //         if(i == j) continue;
    //         if(L[i] < L[j]){
    //             if(R[i] <= L[j]){
    //                 v -= cnt1[R[i]] - cnt1[L[i]-1];
    //                 v -= cnt1[R[j]] - cnt1[L[j] - 1];
    //             }else if(R[i] > L[j] && R[i] <= R[j]){
    //                 v -= cnt1[L[j]] - cnt1[L[i]-1];
    //                 v -= cnt1[R[j]] - cnt1[R[i]-1];
    //                 v -= cnt2[R[i]] - cnt2[L[j]-1];
    //             }else{
    //                 v -= cnt1[R[i]] - cnt1[L[i]-1];
    //                 v -= cnt2[R[j]] - cnt2[L[j]-1];
    //             }
    //         }else if(L[i] > L[j]){ 
    //             if(R[j] <= L[i]){
    //                 v -= cnt1[R[j]] - cnt1[L[j]-1];
    //                 v -= cnt1[R[i]] - cnt1[L[i] - 1];
    //             }else if(R[j] > L[i] && R[j] <= R[i]){
    //                 v -= cnt1[L[i]] - cnt1[L[j]-1];
    //                 v -= cnt1[R[i]] - cnt1[R[j]-1];
    //                 v -= cnt2[R[j]] - cnt2[L[i]-1];
    //             }else{
    //                 v -= cnt1[R[j]] - cnt1[L[j]-1];
    //                 v -= cnt2[R[i]] - cnt2[L[i]-1];
    //             }
    //         }else{
    //             if(R[i] == R[j]){
    //                 v -= cnt2[R[i]] - cnt2[L[i]-1];
    //             }else{
    //                 v -= cnt1[max(R[i],R[j])] - cnt1[min(R[i],R[j])-1];
    //                 v -= cnt2[min(R[i],R[j])] - cnt2[L[i]-1];
    //             }
    //         }
    //         // if(v == 4)print2(i,j);
    //         ans = max(ans, v);
    //     }
    // }
    print(ans);

    
}