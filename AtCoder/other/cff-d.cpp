#include <bits/stdc++.h>
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
char get_char(ll v){
    if(v < 26){
        return (char)('a' + v);
    }else{
        return (char)('A' + (v-26));
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    string S[30010];
    cin >> N;
    rep(i,0,N) cin >> S[i];
    vector< pair<string, ll> > ss;
    map<char, ll> mp[30010];
    rep(i,0,N){
        rep(j,0,S[i].size()){
            mp[i][S[i][j]]++;
        }
    }

    rep(cc,0,52){
        char c = get_char(cc);
        ll val[30010] = {};
        ll val_max[30010] = {};
        rep(i,0,N){
            val[i] = mp[i][c];
            val_max[i] = mp[i][c];
        }
        map<char, ll> mp_left, mp_right;
        rep(i,0,N){
            if(val_max[i] == 0) continue;
            map<char, ll> mp_left_part, mp_right_part;
            rep(j,0,S[i].size()){
                if(S[i][j] == c){
                    if(val_max[i] == 1){
                    }else{
                        if(val[i] == val_max[i]){
                            mp_left_part[c]++;
                        }else if(val[i] == 1){
                            mp_right_part[c]++;
                        }else{
                            mp_left_part[c]++;
                            mp_right_part[c]++;
                        }
                    }
                    val[i]--;
                }else{
                    if(val[i] == val_max[i]){
                        mp_left_part[S[i][j]]++;
                    }else if(val[i] == 0){
                        mp_right_part[S[i][j]]++;
                    }else{
                        mp_left_part[S[i][j]]++;
                        mp_right_part[S[i][j]]++;
                    }
                }
            }
            rep(m,0,52){
                char k = get_char(m);
                if(mp_left_part[k] != 0){
                    mp_left[k]++;
                }
                if(mp_right_part[k] != 0){
                    mp_right[k]++;
                }
            }
        }
        ll mv = 0;
        rep(i,0,52){
            rep(j,0,52){
                char ca = get_char(i);
                char cb = get_char(j);
                mv = max(mv, min(mp_left[ca], mp_right[cb]));
            }
        }
        // print(mv);
        if(mv == 0) continue;
        rep(i,0,52){
            rep(j,0,52){
                char ca = get_char(i);
                char cb = get_char(j);
                if(mv == min(mp_left[ca], mp_right[cb])){
                    string st = "   ";
                    st[0] = ca;
                    st[1] = c;
                    st[2] = cb;
                    // print(st);
                    ss.push_back(make_pair(st, mv));
                }
            }
        }

    }
    rep(i,0,ss.size()){
        print2(ss[i].first, ss[i].second);
    }

}
