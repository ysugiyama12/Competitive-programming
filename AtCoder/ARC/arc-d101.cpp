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
int L[100010], R[100010];
ll merge(ll a[], ll N, ll left, ll mid, ll right){
    ll cnt = 0;
    ll n1 = mid - left;
    ll n2 = right - mid;
    rep(i,0,n1){
        L[i] = a[left + i];
    }
    rep(i,0,n2){
        R[i] = a[mid + i];
    }
    L[n1] = 1e9; // sentinel
    R[n2] = 1e9;
 
    ll p = 0, q = 0;
 
    rep(k,left, right){
        if(L[p] <= R[q]){
            a[k] = L[p];
            p++;
        }else{
            a[k] = R[q];
            q++;
            cnt += n1 - p;
        }
 
    }
    return cnt;
}
 
 


ll mergeSort(ll a[], ll N, ll left, ll right){
    ll mid;
    ll v1, v2, v3;
    if(left + 1 < right){
        mid = (left + right) / 2;
        v1 = mergeSort(a, N, left, mid);
        v2 = mergeSort(a, N, mid, right);
        v3 = merge(a, N, left, mid, right);
        return v1 + v2 + v3;
    }else{
        return 0;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll A[100010];
    cin >> N;
    rep(i,0,N) cin >> A[i];
    if(N == 1){
        print(A[0]);
        return 0;
    }
    // ll n = 2;
    // ll arr[2] = {5,3};
    // ll v = mergeSort(arr, n, 0, n);
    // print(v);
    // return 0;
    ll lv = 0, rv = 1e9+1;
    while(rv - lv > 1){
        ll mid = (rv + lv) / 2;
        ll b[100010] = {};
        rep(i,0,N){
            if(A[i] >= mid){
                b[i] = 1;
            }else{
                b[i] = -1;
            }
        }
        ll sum[100010] = {};
        rep(i,0,N) sum[i+1] = sum[i] + b[i];
        // ll sum2[100010] = {};
        // rep(i,0,N){
        //     sum2[i] = sum[i];
        // }
        ll ans = mergeSort(sum, N+1 , 0, N+1);
        ll v = N*(N-1)/2;
        ans = v - ans;
        print2("mid= ", mid);
        printa(b,N);
        printa(sum, N);
        print(ans);
        if(ans >= (v+1)/2){
            lv = mid;
        }else{
            rv = mid;
        }
        // 1 2 3 2 3 2

    }
    print(lv);

}
