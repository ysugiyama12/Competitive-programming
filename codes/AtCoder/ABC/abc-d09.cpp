#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)

typedef vector<ll> vec;
typedef vector<vec> mat;
mat mult(mat &A, mat &B){
    mat C(A.size(), vec(B[0].size(),0));
    rep(i,0,A.size()){
        rep(k,0,B.size()){
            rep(j,0,B[0].size()){
                C[i][j] ^= (A[i][k] & B[k][j]);
                // C[i][j] %= MOD;
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
    ll K,M;
    ll A[110], C[110];
    cin >> K >> M;
    rep(i,0,K) cin >> A[i];
    rep(i,0,K) cin >> C[i];
    mat B(K, vec(K,0));
    rep(i,0,K){
        B[0][i] = C[i];
    }
    rep(i,0,K-1){
        B[i+1][i] = (1LL<<32) - 1;
    }
    if(M - K <= 0){
        print(A[M-1]);
        return 0;
    }
    mat bb = pow_mat(B, M-K);
    // rep(i,0,K){
    //     rep(j,0,K){
    //         cout << bb[i][j] << " \n"[j == K-1];
    //     }
    // }
    ll ans = 0;
    rep(i,0,K){
        ans ^= (A[K-1-i] & bb[0][i]);
        // print(ans);
    } 
    print(ans);
    // print((7&7)^ (19&1) ^ (13&0));
    
}
