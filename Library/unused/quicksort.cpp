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
typedef pair<char, ll> P;

ll partition(P A[], ll p, ll r){
    ll x = A[r].second;
    ll i = p-1;
    rep(j,p,r){
        if(A[j].second <= x){
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

void quicksort(P A[], ll p, ll r) {
    if(p < r){
        ll q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

void merge(P A[], ll lv, ll mid, ll rv){
    ll n1 = mid - lv;
    ll n2 = rv - mid;
    vector<P> L(n1+1), R(n2+1);
    rep(i,0,n1) L[i] = A[lv+i];
    rep(i,0,n2) R[i] = A[mid+i];
    L[n1] = make_pair('a', INF);
    R[n2] = make_pair('a', INF);
    ll i = 0, j = 0;
    rep(k, lv, rv){
        if(L[i].second <= R[j].second){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(P A[], ll lv, ll rv){
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
    P A[100010], prev[100010];
    cin >> N;
    rep(i,0,N){
        char c;
        ll a;
        cin >> c >> a;
        A[i] = make_pair(c, a);
        prev[i] = make_pair(c, a);
    }

    quicksort(A, 0, N-1);
    mergeSort(prev, 0, N);
    bool is_stable = true;
    rep(i,0,N){
        if(A[i] != prev[i]) is_stable = false;
    }
    if(is_stable){
        print("Stable");
    }else{
        print("Not stable");
    }
    rep(i,0,N){
        print2(A[i].first, A[i].second);
    }



    
}