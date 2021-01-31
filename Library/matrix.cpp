/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
using vll = vector<ll>;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
using mat = vector<vll>;

ll power(ll x, ll n, ll m = MOD){
    if(n == 0) return 1LL;
    ll res = power(x * x % m, n/2, m);
    if(n % 2 == 1) (res *= x) %= m;
    return res;
}

ll determinant(mat A, const ll MOD) {
    const int n = A.size();
    assert(n == (int)A[0].size());
    ll ans = 1;
    rep(i,0,n) {
        int pivot = -1;
        rep(j,i,n) if (A[j][i]) {
            pivot = j;
            break;
        }
        if (pivot == -1) return 0;
        if (i != pivot) {
            swap(A[i], A[pivot]);
            ans *= -1;
        }
        ll inv = power(A[i][i], MOD-2, MOD);
        rep(j,i+1,n){
            ll c = A[j][i] * inv % MOD;
            rep(k,i,n) {
                A[j][k] = (A[j][k] - c * A[i][k]) % MOD;
            }
        }
        (ans *= A[i][i]) %= MOD;
    }
    if (ans < 0) ans += MOD;
    return ans;
}


mat mult(mat &A, mat &B){
    mat C(A.size(), vll(B[0].size(),0));
    rep(i,0,(ll) A.size()){
        rep(k,0,(ll) B.size()){
            rep(j,0,(ll) B[0].size()){
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}

mat pow_mat(mat A, ll n){
    if(n == 0) exit(1);
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
	ll a,b,n;
	cin >> a >> b >> n;
	if(n <= 1){
		print(n);
		return 0;
	}
	mat A(2, vll(2,0));
	A[0][0] = a;
	A[0][1] = b;
	A[1][0] = 1;
	A[1][1] = 0;
	mat ans = pow_mat(A, n-1);
	ll res = ans[0][0];
	print(res);
    
}