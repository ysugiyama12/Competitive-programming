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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A[100001], B[100001], C[100001];
    int N;
    cin >> N;
    rep(i,0,N){
        cin >> A[i];
    }
    rep(i,0,N){
        cin >> B[i];
    }
    rep(i,0,N){
        cin >> C[i];
    }
    sort(A,A+N);
    sort(B,B+N);
    sort(C,C+N);

    ll ans = 0;
    rep(i,0,N){
        ll pos_a = lower_bound(A, A+N, B[i]) - A;
        ll pos_c = upper_bound(C, C+N, B[i]) - C;
        ans += (pos_a * (N - pos_c));

    }
    print(ans);
    
    // int arr[5] = {0,2,4,6,8};
    // int a = lower_bound(arr,arr+5, 2) - arr;
    // int b = upper_bound(arr,arr+5, 2) - arr;
    // print(a);
    // print(b);


}
