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
bool is_symbol(char s){
    if(s == '+' || s == '-' || s == '*' || s == '/'){
        return true;
    }
    return false;
}
bool is_num(char s){
    if(s >= '0' && s <= '9'){
        return true;
    }
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.size();
    stack<string> ss;
    string now_num = "";
    rep(i,0,N){
        // print(i);
        if(is_symbol(S[i])){
            ss.push(S.substr(i,1));
        }else if(S[i] == '('){
            continue;
        }else if(is_num(S[i])){
            now_num += S[i];
        }else if(S[i] == ','){
            if(now_num != ""){
                ss.push(now_num);
                now_num = "";
            }
        }else if(S[i] == ')'){
            if(now_num != ""){
                ss.push(now_num);
                now_num = "";
            }
            vector<string> tt;
            while(!ss.empty()){
                string st = ss.top();
                tt.push_back(st);
                ss.pop();
                char c = st[0];
                if(is_symbol(c) && st.size() == 1){
                    string res = "";
                    res += "(";
                    ll n = tt.size();
                    rep(i,0,n-1){
                        res += tt[n-2-i];
                        if(i != n-2) res += tt[n-1];
                    }
                    res += ")";
                    ss.push(res);
                    break;
                }
            }          
        }
        // string k = ss.top();
        // print(k);
    }
    if(now_num != "") ss.push(now_num);
    print(ss.top());
}
