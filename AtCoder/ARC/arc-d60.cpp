#include <bits/stdc++.h>
#include <unordered_map>
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
ll digit_sum(ll N, ll b){
    ll sum = 0;
    while(N > 0){
        sum += N % b;
        N /= b;
    }
    return sum;
}

inline vector<ll> divisor(ll M){ //約数の全列挙
    vector<ll> dd;
    for(ll i = 1; i*i <= M; i++){
        if(M % i == 0){
            dd.push_back(i);
            if(i * i != M){
                dd.push_back(M/i);
            }
        }
    }
    sort(dd.begin(), dd.end());
    return dd;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,S;
    cin >> N >> S;
    if(N == S){
        print(N+1);
        return 0;
    }
    ll v = sqrt(N);
    rep(b,2,v+1){
        ll ss = digit_sum(N, b);
        if(S == ss){
            print(b);
            return 0;
        }
    }
    if(N - S < 0){
        print(-1);
        return 0;
    }
    vector<ll> dd = divisor(N-S);
    ll dn = dd.size();
    rep(i,0,dn){
        ll bb = dd[i] + 1;
        ll xx = (N-S) / dd[i];
        if(S - xx >= 0 && S - xx <= bb-1){
            if(N - xx*bb >= 0 && N - xx * bb <= bb-1){
                if(xx <= bb && bb > sqrt(N)){
                    print(bb);
                    return 0;
                }
            }
        }
    }
    print(-1);
}
