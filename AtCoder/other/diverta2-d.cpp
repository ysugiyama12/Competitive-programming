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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll gA, sA, bA, gB, sB, bB;
    cin >> gA >> sA >> bA >> gB >> sB >> bB;
    ll ans = 0;
    ll vg = gB - gA, vs = sB - sA, vb = bB - bA;
    if(vg >= 0 && vs < 0 && vb < 0){
        ll tt = N % gA + (N / gA) * gB;
        rep(i,0,tt+1){
            ll i2 = tt - i;
            ans = max(ans, (i/sB) * sA + (i2/bB) * bA + i%sB + i2%bB);
        }
    }else if(vg < 0 && vs >= 0 && vb < 0){
        ll tt = N % sA + (N / sA) * sB;
        rep(i,0,tt+1){
            ll i2 = tt - i;
            ans = max(ans, (i/gB) * gA + (i2/bB) * bA + i%gB + i2%bB);
        }

    }else if(vg < 0 && vs < 0 && vb >= 0){
        ll tt = N % bA + (N / bA) * bB;
        rep(i,0,tt+1){
            ll i2 = tt - i;
            ans = max(ans, (i/gB) * gA + (i2/sB) * sA + i%gB + i2%sB);
        }

    }else if(vg >= 0 && vs >= 0 && vb < 0){
        ll tt = 0;
        rep(i,0,N+1){
            ll i2 = N - i;
            tt = max(tt, (i/gA) * gB + i % gA + (i2/sA) * sB + i2 % sA);
        }
        ans = (tt / bB) * bA + tt % bB;
    }else if(vg >= 0 && vs < 0 && vb >= 0){
        ll tt = 0;
        rep(i,0,N+1){
            ll i2 = N - i;
            tt = max(tt, (i/gA) * gB + i % gA + (i2/bA) * bB + i2 % bA);
        }
        ans = (tt / sB) * sA + tt % sB;
    }else if(vg < 0 && vs >= 0 && vb >= 0){
        ll tt = 0;
        rep(i,0,N+1){
            ll i2 = N - i;
            tt = max(tt, (i/sA) * sB + i % sA + (i2/bA) * bB + i2 % bA);
        }
        ans = (tt / gB) * gA + tt % gB;      
    }else if(vg >= 0 && vs >= 0 && vb >= 0){
        rep(i,0,N+1){
            rep(j,0,N+1){
                ll k = N - i - j;
                if(k < 0) continue;
                ans = max(ans, (i / gA) * gB + i % gA + (j / sA) * sB + j % sA + (k / bA) * bB + k % bA);
            }
        }
    }else{
        rep(i,0,N+1){
            rep(j,0,N+1){
                ll k = N - i - j;
                if(k < 0) continue;
                ans = max(ans, (i / gB) * gA + i % gB + (j / sB) * sA + j % sB + (k / bB) * bA + k % bB);
            }
        }
    }
    print(ans);



}