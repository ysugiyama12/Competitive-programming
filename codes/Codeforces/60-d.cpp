#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

typedef vector<ll> vec;
typedef vector<vec> mat;
mat mult(mat &A, mat &B){
    mat C(A.size(), vec(B[0].size()));
    rep(i,0,A.size()){
        rep(k,0,B.size()){
            rep(j,0,B[0].size()){
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}

mat pow_mat(mat A, ll n){
    if(n == 1) return A;
    if(n % 2 == 0){
        mat B = pow_mat(A, n/2);
        return mult(B, B);
    }else{
        mat B = pow_mat(A, n-1);
        return mult(A,B); 
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    mat A(M, vec(M,0));
    A[0][0] = 1; A[0][M-1] = 1;
    rep(i,0,M-1){
        A[i+1][i] = 1;
    }
    mat ans = pow_mat(A, N);
    print(ans[0][0]);
    

}
