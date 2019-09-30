/*** author: yuji9511 ***/
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
typedef vector<ll> vec;
typedef vector<vec> mat;
mat mult(mat &A, mat &B){
    mat C(A.size(), vec(B[0].size(),0));
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
        return mult(B,B);
    }else{
        mat B = pow_mat(A, n-1);
        return mult(A,B); 
    }
}

// verify: https://yukicoder.me/problems/no/891
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll a,b,n;
	cin >> a >> b >> n;
	if(n <= 1){
		print(n);
		return 0;
	}
	mat A(2, vec(2,0));
	A[0][0] = a;
	A[0][1] = b;
	A[1][0] = 1;
	A[1][1] = 0;
	mat ans = pow_mat(A, n-1);
	ll res = ans[0][0];
	print(res);
    
}