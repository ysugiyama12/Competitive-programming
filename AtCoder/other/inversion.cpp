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
int L[100010], R[100010];

ll merge(int a[], int N, int left, int mid, int right){
    ll cnt = 0;
    int n1 = mid - left;
    int n2 = right - mid;
    rep(i,0,n1){
        L[i] = a[left + i];
    }
    rep(i,0,n2){
        R[i] = a[mid + i];
    }
    L[n1] = 1e9; // sentinel
    R[n2] = 1e9;

    int p = 0, q = 0;

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

ll mergeSort(int a[], int N, int left, int right){
    int mid;
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
    int a[100010] = {};
    cin >> N;
    rep(i,0,N){
        cin >> a[i];
    }
    ll ans = mergeSort(a, N, 0, N);
    print(ans);
}
