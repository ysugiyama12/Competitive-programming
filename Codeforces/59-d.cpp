#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
// ll c[5300][5300] = {};
string t[5300];
// ll v[5300] = {};
// ll mp[5300][5300] = {};
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
ll cv(char s){
    if(s >= 'A' && s <= 'F'){
        return s - 'A' + 10;
    }
    return s -'0';
}
string cv2(ll v){
    stringstream ss;
    ss << hex << v;
    string s = ss.str();
    // print2(v,s);
    return s;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    rep(i,0,N) cin >> t[i];
    // print("---");
    string s[5300];
    rep(i,0,N){
        // print2("i=",i);
        s[i] = "";
        ll val = 0;
        rep(j,0,N){
            val += ((cv(t[j][i/4])>>(3 - i%4)) & 1) * pow(2, 3-j%4);
            // print(val);
            if(j % 4 == 3){
                s[i] += cv2(val);
                // print(s[i]);
                val = 0;
            }
        }
    }
    // printa(s, N);
    rep(i,0,N){
        transform(s[i].begin(), s[i].end(), s[i].begin(), ::toupper);
    }
    vector<ll> dd = divisor(N);
    sort(dd.begin(), dd.end(), greater<ll>());
    for(auto &e: dd){
        bool ok = true;
        rep(i,1,N){
            if(i%e > (i-1)%e && t[i] != t[i-1]) ok = false;
            if(i%e > (i-1)%e && s[i] != s[i-1]) ok = false;
        }
        if(ok){
            print(e);
            return 0;
        }
    }
    
    // printa(s, N);
    // rep(i,0,N){
    //     rep(j,0,N/4){
    //         ll tt = N/4 - 1 - j;
    //         // print(t[i][tt]);
    //         if(t[i][tt] >= 'A' && t[i][tt] <= 'F'){
    //             v[i] += pow(16,j) * (t[i][tt] - 'A' + 10);
    //         }else{
    //             v[i] += pow(16,j) * (t[i][tt] - '0');
    //         }
    //     }
    //     // print(v[i]);
    //     // v[i] = strtol(t[i], NULL, 16);
    // }
    // rep(i,0,N){
    //     ll idx = 0;
    //     while(v[i] > 0){
    //         c[i][idx] = v[i] % 2;
    //         v[i] /= 2;
    //         idx++;
    //     }
    // }
    // rep(i,0,N){
    //     rep(j,0,N){
    //         cout << c[i][j] << " \n"[j == N-1];
    //     }
    // }
    // vector<ll> dd = divisor(N);
    // sort(dd.begin(), dd.end(), greater<ll>());
    // ll ans = 0;
    // rep(m,0,dd.size()){
    //     ll val = dd[m];
    //     // map<lpair, ll> mp;
    //     ll divs = N / val;
    //     rep(i,0,divs){
    //         rep(j,0,divs){
    //             mp[i][j] = -1;
    //         }
    //     }
    //     bool ok = true;
    //     rep(i,0,N){
    //         rep(j,0,N){
    //             if(mp[i/val][j/val] == -1){
    //                 mp[i/val][j/val] = ((cv(t[i][j/4])>>(3 - j%4)) & 1);
    //             }else if(mp[i/val][j/val] != ((cv(t[i][j/4])>>(3 - j%4)) & 1)){
    //                 ok = false;
    //                 break;
    //             }
    //         }
    //         if(!ok) break;
    //     }
    //     if(ok){
    //         print(val);
    //         return 0;
    //     }
    // }
    // printa(dd, dd.size());


}