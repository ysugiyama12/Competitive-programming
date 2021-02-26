#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
#define INF (1e18)
string S,T;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S >> T;
    ll s0 = 0, s1 = 0;
    ll t0 = 0, t1 = 0;
    ll ns = S.size();
    ll nt = T.size();
    rep(i,0,ns){
        if(S[i] == '0') s0++;
        if(S[i] == '1') s1++;
    }
    rep(i,0,nt){
        if(T[i] == '0') t0++;
        if(T[i] == '1') t1++;
    }
    ll lv = -1, rv = nt+1;
    while(rv - lv > 1){
        ll mid = (rv + lv)/2;
        string s1 = T.substr(0,mid);
        string s2 = T.substr(nt-mid,mid);
        if(s1 == s2){
            lv = mid;
        }else{
            rv = mid;
        }
    }
    if(lv == nt) lv--;
    // print(lv);
    ll c0_top = 0, c1_top = 0, c0_bottom = 0, c1_bottom = 0;
    rep(i,0,nt){
        if(i < lv){
            if(T[i] == '0') c0_top++;
            if(T[i] == '1') c1_top++;
        }else{
            if(T[i] == '0') c0_bottom++;
            if(T[i] == '1') c1_bottom++;
        }
    }
    if(s0 < c0_top || s1 < c1_top){
        print(S);
        return 0;
    }
    s0 -= c0_top;
    s1 -= c1_top;
    ll v,diff0, diff1;
    if(c0_bottom == 0){
        v = s1/c1_bottom;
        diff0 = s0;
        diff1 = s1 - v*c1_bottom;
    }else if(c1_bottom == 0){
        v = s0/c0_bottom;
        diff0 = s0 - v*c0_bottom;
        diff1 = s1;
    }else{
        v = min(s1/c1_bottom, s0/c0_bottom);
        diff0 = s0 - v*c0_bottom;
        diff1 = s1 - v*c1_bottom;
    }
    // print(v);
    cout << T.substr(0,lv);
    rep(i,0,v){
        cout << T.substr(lv,nt-lv);
    }
    rep(i,0,diff0) cout << '0';
    rep(i,0,diff1) cout << '1';
    cout << endl;

    // print(T.substr(0,lv));

    // rep(i,0,nt){

    // }
    // ll v0=0,v1=0,diff0=0,diff1=0,v=0;
    // if(t0 == 0){
    //     v1 = s1/t1;
    //     diff0 = s0;
    //     diff1 = s1 - t1*v1;
    //     v = v1;

    // }else if(t1 == 0){
    //     v0 = s0/t0;
    //     diff0 = s0 - t0*v0;
    //     diff1 = s1;
    //     v = v0;
    // }else{
    //     v0 = s0 / t0;
    //     v1 = s1 / t1;
    //     v = min(v0,v1);
    //     diff0 = s0 - t0*v;
    //     diff1 = s1 - t1*v;
    // }

    // rep(i,0,v){
    //     cout << T;
    // }
    // rep(i,0,diff0){
    //     cout << '0';
    // }
    // rep(i,0,diff1){
    //     cout << '1';
    // }
    // cout << endl;
}