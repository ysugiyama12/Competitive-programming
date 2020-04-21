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
#define Case(t) cout << "Case #" << t << ": "

int main(){
    ll T,A,B;
    cin >> T >> A >> B;
    // if(A != B) return 0;
    rep(t,1,T+1){
        if(A == 1000000000 - 5){
            rep(x,-5, 6){
                bool ok = false;
                rep(y,-5,6){
                    cout << x << " " << y << endl;
                    string res;
                    cin >> res;
                    if(res == "CENTER"){
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }
        }else{
            bool ok = false;
            rep(x,-50, 51){
                cout << x << " " << 0 << endl;
                string res;
                cin >> res;
                if(res == "CENTER"){
                    ok = true;
                    break;
                }
            }
            if(ok) continue;
            rep(y,-50, 51){
                cout << 0 << " " << y << endl;
                string res;
                cin >> res;
                if(res == "CENTER"){
                    ok = true;
                    break;
                }
            }
            if(ok) continue;

            ll lv = -1, rv = 101;
            ll e9 = 1000000000;
            while(rv - lv > 1){
                ll mid = (rv + lv) / 2;
                ll x = -e9 + mid, y = 0;
                cout << x << " " << y << endl;
                string res;
                cin >> res;
                if(res == "MISS"){
                    lv = mid;
                }else{
                    rv = mid;
                }
            }
            ll left_pos = -e9 + rv-1;
            lv = -1; rv = 101;
            while(rv - lv > 1){
                ll mid = (rv + lv) / 2;
                ll x = e9-100+mid;
                ll y = 0;
                cout << x << " " << y << endl;
                string res;
                cin >> res;
                if(res == "MISS"){
                    rv = mid;
                }else{
                    lv = mid;
                }
            }
            ll right_pos = e9 - 100 + lv+1;

            lv = -1; rv = 101;
            while(rv - lv > 1){
                ll mid = (rv + lv) / 2;
                ll x = 0;
                ll y = e9 - 100 + mid;
                cout << x << " " << y << endl;
                string res;
                cin >> res;
                if(res == "MISS"){
                    rv = mid;
                }else{
                    lv = mid;
                }
            }
            ll top_pos = e9 - 100 + lv+1;


            lv = -1; rv = 101;
            while(rv - lv > 1){
                ll mid = (rv + lv) / 2;
                ll x = 0;
                ll y = -e9 + mid;
                cout << x << " " << y << endl;
                string res;
                cin >> res;
                if(res == "MISS"){
                    lv = mid;
                }else{
                    rv = mid;
                }
            }
            ll bottom_pos = -e9 + rv-1;

            ll ans_x = (left_pos + right_pos) / 2;
            ll ans_y = (top_pos + bottom_pos) / 2;
            cout << ans_x << " " << ans_y << endl;
            string res;
            cin >> res;
            if(res != "CENTER") exit(1);

        }
    }
    

}