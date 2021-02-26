/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
ll arr[] = {682498929LL, 632720431LL, 448943438LL, 116079221LL, 615142340LL, 6259027LL, 948197154LL, 145971945LL, 916800752LL, 202251309LL, 37983229LL, 837458921LL, 975495147LL, 518030386LL, 376072195LL, 622014712LL, 716809811LL, 934894288LL, 220366634LL, 464931331LL, 836796013LL, 577952413LL, 97313845LL, 283854312LL, 210437135LL, 88493197LL, 747521698LL, 110954347LL, 351437952LL, 531553513LL, 172279346LL, 633918352LL, 41789059LL, 743764606LL, 946214298LL, 462694068LL, 572856921LL, 493284479LL, 649230871LL, 878554427LL, 139060384LL, 73966192LL, 303719911LL, 720131873LL, 525952103LL, 497375585LL, 657945273LL, 935274198LL, 24382639LL, 490716262LL, 308431504LL, 321519436LL, 612968833LL, 593412210LL, 298137292LL, 622826075LL, 106009973LL, 824985246LL, 701967571LL, 239564185LL, 271700936LL, 900989749LL, 408066260LL, 484652396LL, 890515364LL, 950182975LL, 969238460LL, 498362772LL, 604180732LL, 550240872LL, 603837221LL, 139677594LL, 502054009LL, 924014287LL, 566254400LL, 71835811LL, 507367266LL, 497160223LL, 582441075LL, 592048491LL, 11579706LL, 322196210LL, 744436409LL, 359281663LL, 261077935LL, 391723090LL, 686167966LL, 732061422LL, 351968552LL, 384403496LL, 285632677LL, 858738739LL, 189667484LL, 482253650LL, 514650121LL, 78576211LL, 85412424LL, 498597530LL, 719338134LL, 799987210LL, 0LL, 87057359LL, 768138694LL, 794109565LL, 528998351LL, 170600929LL, 161280204LL, 557841721LL, 313174199LL, 899015368LL, 920674541LL, 660042853LL, 96753306LL, 247831107LL, 991211596LL, 913846238LL, 333086748LL, 582746625LL, 512764351LL, 136118538LL
};
struct BigCombination{
private:
    ll N;

public:
    BigCombination(ll n){
        N = n;
    }
    ll power(ll x, ll n){
        if(n == 0) return 1LL;
        ll res = power(x * x % MOD, n/2);
        if(n % 2 == 1) res = res * x % MOD;
        return res;
    }
    ll fac(ll n){
        ll v = 1;
        ll res = 1;
        ll cnt = 0;
        ll tt = 10000000;
        for(ll i = 1; (i+tt) <= n; i += tt){
            res *= arr[cnt];
            res %= MOD;
            v = i+tt;
            cnt++;
        }
        rep(i,v,n+1){
            res *= i;
            res %= MOD;
        }
        return res;
    }

    ll facinv(ll n){
        return power(fac(n), MOD-2);
    }

    ll nck(ll n, ll k){
        if(k == 0 || n == k) return 1LL;
        return fac(n) * facinv(k) % MOD * facinv(n-k) % MOD;      
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,A,B;
    cin >> N >> A >> B;
    BigCombination cb(200010);
    ll ans = (cb.power(2, N) - 1 + MOD) % MOD;
    ans = (ans - cb.nck(N, A) - cb.nck(N, B) + 2 * MOD) % MOD;
    print(ans);
}
