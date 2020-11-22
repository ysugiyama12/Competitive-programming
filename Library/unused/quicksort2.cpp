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

ll getPartition(ll A[], ll lv, ll rv){
    ll idx = lv-1;
    ll x = A[rv];
    rep(i,lv,rv){
        if(A[i] <= x){
            idx++;
            swap(A[idx], A[i]);
        }
    }
    swap(A[idx+1], A[rv]);
    return idx+1;
}

void quicksort(ll A[], ll lv, ll rv){
    if(rv - lv < 0) return;
    ll mid = getPartition(A, lv, rv);
    print(mid);
    printa(A, rv - lv+1);
    quicksort(A, lv, mid-1);
    quicksort(A, mid+1, rv);

}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A[100010];
    rep(i,0,N) cin >> A[i];
    quicksort(A, 0, N-1);
    printa(A, N);
    

}