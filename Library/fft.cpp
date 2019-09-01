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
using Complex = complex<double>;

vector<Complex> dft(vector<Complex> A, ll N, ll sgn = 1){
    if(N == 1) return A;
    vector<Complex> F(N/2), G(N/2);
    rep(i,0,N/2){
        F[i] = A[2*i + 0];
        G[i] = A[2*i + 1];
    }

    F = dft(F, N/2, sgn);
    G = dft(G, N/2, sgn);

    Complex zeta(cos(2.0 * M_PI / N), sin(2.0 * M_PI / N) * sgn);
    Complex pow_zeta = 1;

    rep(i,0,N){
        A[i] = F[i % (N/2)] + pow_zeta * G[i % (N/2)];
        pow_zeta *= zeta;
    }

    return A;

}
vector<Complex> inv_dft(vector<Complex> A, ll N){
    A = dft(A, N, -1);
    rep(i,0,N) A[i] /= N;
    return A;
}

vector<Complex> multiply(vector<Complex> A, vector<Complex> B){
    ll sz = A.size() + B.size() + 1;
    ll N = 1;
    while(N < sz) N *= 2;

    A.resize(N);
    B.resize(N);
    A = dft(A, N);
    B = dft(B, N);
    vector<Complex> F(N);
    rep(i,0,N) F[i] = A[i] * B[i];
    return inv_dft(F, N);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    scanf("%lld", &N);
    vector<Complex> A(N+1), B(N+1);
    A[0] = B[0] = Complex(0);
    rep(i,0,N){
        ll a,b;
        scanf("%lld %lld", &a, &b);
        A[i+1] = Complex(a);
        B[i+1] = Complex(b);
    }

    vector<Complex> ans = multiply(A, B);
    rep(i,1,2*N+1) printf("%d\n", (int)(ans[i].real() + 0.5));
}