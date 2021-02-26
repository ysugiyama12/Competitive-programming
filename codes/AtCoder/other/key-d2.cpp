#include <bits/stdc++.h>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    ll A[1010], B[1010];
    map<ll,ll> mp_a, mp_b;
    cin >> N >> M;
    bool flg = true;
    rep(i,0,N){
        cin >> A[i];
        mp_a[A[i]]++;
        if(mp_a[A[i]] == 2) flg = false;
    }
    rep(i,0,M){
        cin >> B[i];
        mp_b[B[i]]++;
        if(mp_b[B[i]] == 2) flg = false;
    }
    sort(A,A+N);
    sort(B,B+M);
    // printa(A,N);
    // printa(B,M);
    ll ans = 1;
    ll cnt = 0;
    rrep(i,N*M,1){
        ll v1 = lower_bound(A, A+N, i) - A;
        ll v2 = lower_bound(B, B+M, i) - B;
        // print2("i=",i);
        // print2(v1,v2);
        if(v1 == N || v2 == M){
            flg = false;
            break;
        }
        ll alt = (N - v1) * (M - v2);
        // print(alt);
        alt -= cnt;
        if(alt < 0){
            flg = false;
            break;   
        }
        if(mp_a[i] == 1 && mp_b[i] == 1){
            ans *= 1;
            cnt++;
        }else if(mp_a[i] == 1){
            ans *= (M-v2);
            ans %= MOD;
            cnt++;

        }else if(mp_b[i] == 1){
            ans *= (N-v1);
            ans %= MOD;
            cnt++;

        }else{ 
            ans *= alt;
            ans %= MOD;
            cnt++;
        }
    }
    if(!flg){
        print(0);
    }else{
        print(ans % MOD);
    }
}
