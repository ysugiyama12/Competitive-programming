#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printaa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ for(int j = 0; j < (sizeof(x[0])/sizeof(x[0][0])); j++){ cout << x[i][j] << " ";} cout << endl;}
#define INF (1e9)
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;

using namespace std;
ll L[100010], R[100010];

ll merge(ll a[], int N, ll left, ll mid, ll right){
    ll cnt = 0;
    ll n1 = mid - left;
    ll n2 = right - mid;
    rep(i,0,n1){
        L[i] = a[left + i];
    }
    rep(i,0,n2){
        R[i] = a[mid + i];
    }
    L[n1] = 1e12; // sentinel
    R[n2] = 1e12;

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

ll mergeSort(ll a[], int N, ll left, ll right){
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
    int N;
    ll a[100010];
    cin >> N;
    rep(i,0,N){
        cin >> a[i];
    }
    ll left = -100;
    ll right = 1e12;
    ll digit[100010] = {};
    ll sum[100010] = {};
    while(right - left > 1){
        ll x = (left + right)/2;
        // print(x);
        rep(i,0,N){
            if(a[i] >= x){
                digit[i] = 1;
            }else{
                digit[i] = -1;
            }
        }
        rep(i,0,N+1){
            sum[i] = 0;
        }
        rep(i,1,N+1){
            sum[i] = sum[i-1] + digit[i-1];
        }
        ll ans = mergeSort(sum, N+1, 0, N+1);
        ll M = N*(N+1)/2;
        ans = M - ans;
        ll val = 0;
        if(M % 2 == 0){
            val = M/2;
        }else{
            val = (M+1)/2;
        }
        if(ans >= val){
            left = x;
        }else{
            right = x;
        }
    }
    print(left);

}
