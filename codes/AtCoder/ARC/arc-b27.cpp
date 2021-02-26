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
bool is_num(char c){
    if(c - '0' >= 0 && c - '0' <= 9) return true;
    return false;
}
ll parent[200010];

ll root(ll x){
    if(x == parent[x]) return x;
    else return parent[x] = root(parent[x]);
}

void unite(ll a, ll b){
    a = root(a); b = root(b);
    if(a == b) return;
    parent[a] = b;
}

bool same(ll a, ll b){
    return root(a) == root(b);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    string s1, s2;
    cin >> N;
    cin >> s1 >> s2;
    ll d[30] = {};
    rep(i,0,N){
        if(is_num(s1[i]) && !is_num(s2[i])){
            d[s2[i]-'A'] = 1;
        }else if(!is_num(s1[i]) && is_num(s2[i])){
            d[s1[i]-'A'] = 1;
        }
    }
    rep(i,0,26){
        parent[i] = i;
    }
    ll is_9 = -1;
    map<ll,ll> is_same;
    rep(i,0,N){
        if(!is_num(s1[i]) && !is_num(s2[i])){
            if(s1[i] == s2[i]) is_same[s1[i]-'A']++;
            unite(s1[i]-'A', s2[i]-'A');
            if(i == 0){
                is_9 = s1[i] - 'A';
            }
        }
    }
    map<ll,ll> mp;
    rep(i,0,26){
        mp[root(i)]++;
    }
    ll ans = 1;
    rep(i,0,26){
        if(mp[root(i)] == 1 && d[i] == 0 && !is_same[i]) continue;
        ll val = 0;
        rep(j,0,26){
            if(root(i) == root(j)){
                val = max(val, d[j]);
            }
        }
        if(val == 1){
            ans *= 1;
        }else{
            if(is_9 != -1){
                if(root(is_9) == root(i)){
                    ans *= 9;
                }else{
                    ans *= 10;
                }
            }else{
                ans *= 10;
            }
            d[i] = 1;
        }

    }
    print(ans);
    // rep(i,0,N){
    //     if(is_num(s1[i]) && !is_num(s2[i])){
    //         mp[s2[i]] = 1;
    //     }else if(!is_num(s1[i]) && is_num(s2[i])){
    //         mp[s1[i]] = 1;
    //     }
    // }
    // rep(i,0,N){
    //     if(!is_num(s1[i]) && !is_num(s2[i])){
    //         if(i == 0){
    //             if(mp[s1[i]] == 0 && mp[s2[i]] == 0){
    //                 mp[s1[i]] = 1;
    //                 mp[s2[i]] = 9;
    //             }else{
    //                 if(mp[s2[i]] == 0 && mp[s1[i]] != 0){
    //                     mp[s2[i]] = 1;
    //                 }else if(mp[s1[i]] == 0 && mp[s2[i]] != 0){
    //                     mp[s1[i]] = 1;
    //                 }else if(mp[s1[i]] != 1 && mp[s2[i]] != 1){
    //                     mp[s1[i]] = 1;
    //                 }
    //             }
    //         }else{
    //             if(mp[s1[i]] == 0 && mp[s2[i]] == 0){
    //                 mp[s1[i]] = 1;
    //                 mp[s2[i]] = 10;
    //             }else{
    //                 if(mp[s2[i]] == 0 && mp[s1[i]] != 0){
    //                     mp[s2[i]] = 1;
    //                 }else if(mp[s1[i]] == 0 && mp[s2[i]] != 0){
    //                     mp[s1[i]] = 1;
    //                 }else if(mp[s1[i]] != 1 && mp[s2[i]] != 1){
    //                     mp[s1[i]] = 1;
    //                 }
    //             }

    //         }
    //     }
    // }
    // ll ans = 1;
    // for(auto &e: mp){
    //     if(e.second != 0){
    //         ans *= e.second;
    //     }
    // }
    // print(ans);
}
