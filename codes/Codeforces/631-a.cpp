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

#define Case(i) cout << "Case #" << (i) << ": "

int main(){
    ll T;
    ll B;
    cin >> T >> B;
    rep(t,1,T+1){
        if(B == 10){
            vector<char> ans;
            rep(i,0,B){
                cout << i+1 << endl;
                char res;
                cin >> res;
                ans.push_back(res);
            }
            string res = "";
            rep(i,0,B){
                res += ans[i];
            }
            cout << res << endl;
            string result;
            cin >> result;
            if(result == "N") return 0;
        }else if(B == 20){
            ll types[21] = {};
            rep(i,0,10){
                cout << i+1 << endl;
                char res1, res2;
                cin >> res1;
                cout << 20-i << endl;
                cin >> res2;
                if(res1 == res2){
                    types[i] = 1;
                }else{
                    types[i] = 2;
                }
            }
            string ans = string(20, '.');
            rep(i,0,10){
                cout << i+1 << endl;
                char res;
                cin >> res;
                if(res == '0'){
                    if(types[i] == 1){
                        ans[i] = '0';
                        ans[19-i] = '0';
                    }else{
                        ans[i] = '0';
                        ans[19-i] = '1';
                    }
                }else{
                    if(types[i] == 1){
                        ans[i] = '1';
                        ans[19-i] = '1';
                    }else{
                        ans[i] = '1';
                        ans[19-i] = '0';
                    }                  
                }
            }
            cout << ans << endl;
            string result;
            cin >> result;
            if(result == "N") return 0;

        }else{
            ll types[110] = {};
            rep(i,0,50){
                cout << i+1 << endl;
                char res1, res2;
                cin >> res1;
                cout << 100-i << endl;
                cin >> res2;
                if(res1 == res2){
                    if(res1 == '0'){
                        types[i] = 1;
                    }else{
                        types[i] = 2;
                    }
                }else{
                    if(res1 == '0'){
                        types[i] = 3;
                    }else{
                        types[i] = 4;
                    }
                }
            }
            
        }

    }

}