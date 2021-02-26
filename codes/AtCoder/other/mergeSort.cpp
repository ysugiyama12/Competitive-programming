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
ll cnt = 0;

void merge(ll A[], ll lv, ll mid, ll rv){
    ll n1 = mid - lv;
    ll n2 = rv - mid;
    vector<ll> L(n1+1), R(n2+1);
    rep(i,0,n1) L[i] = A[lv+i];
    rep(i,0,n2) R[i] = A[mid+i];
    L[n1] = INF;
    R[n2] = INF;
    ll i = 0, j = 0;
    rep(k, lv, rv){
        cnt++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(ll A[], ll lv, ll rv){
    if(rv - lv > 1){
        ll mid = (rv + lv) / 2;
        mergeSort(A, lv, mid);
        mergeSort(A, mid, rv);
        merge(A, lv, mid, rv);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A[500010];
    rep(i,0,N) cin >> A[i];
    mergeSort(A, 0, N);
    printa(A,N);
    print(cnt);
}
