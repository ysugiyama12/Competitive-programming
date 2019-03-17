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
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    string S, A;
    cin >> N;
    cin >> S >> A;
    ll cnt[4] = {};
    rep(i,0,N){
        if(S[i] == '0' && A[i] == '0'){
            cnt[0]++;
        }else if(S[i] == '0' && A[i] == '1'){
            cnt[1]++;
        }else if(S[i] == '1' && A[i] == '0'){
            cnt[2]++;
        }else{
            cnt[3]++;
        }
    }
    ll aa = cnt[0], bb = cnt[1], cc = cnt[2], dd = cnt[3];
    rep(c1,0,cc+1){
        rep(d1,0,dd+1){
            ll d2 = dd - d1;
            ll b2 = c1+d1-d2;
            if(b2 < 0 || b2 > bb) continue;
            ll c2 = cc - c1;
            ll b1 = bb - b2;
            ll v = c2 - b1;
            if((aa+v) % 2 == 1 || aa+v < 0 || (aa-v) % 2 == 1 || aa-v < 0) continue;
            ll a1 = (aa+v)/2;
            if(a1 > aa) continue;
            // cout << a1 << " " << b1 << " " << c1 << " " << d1 << endl;
            ll cc[4] = {};
            vector<ll> ans;
            rep(i,0,N){
                if(S[i] == '0' && A[i] == '0'){
                    if(cc[0] < a1){
                        ans.push_back(i+1);
                        cc[0]++;
                    }
                }else if(S[i] == '0' && A[i] == '1'){
                    if(cc[1] < b1){
                        ans.push_back(i+1);
                        cc[1]++;
                    }
                }else if(S[i] == '1' && A[i] == '0'){
                    if(cc[2] < c1){
                        ans.push_back(i+1);
                        cc[2]++;
                    }
                }else{
                    if(cc[3] < d1){
                        ans.push_back(i+1);
                        cc[3]++;
                    }
                }
            }
            rep(i,0,ans.size()){
                cout << ans[i] << " \n"[i == ans.size()-1];
            }
            return 0;
            
        }
    }
    print(-1);
    
}