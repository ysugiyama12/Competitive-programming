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
struct HashData {
	ll h1, h2;
	bool operator==(const HashData& rhs) const {
		return h1 == rhs.h1 && h2 == rhs.h2;
	}
	bool operator!=(const HashData& rhs) const { return !(*this == rhs); }
};

class RollingHash {
	template<const ll B, const ll M>
	class RollingHashPart {
	private:
		size_t len;
		vector<ll> pow_b, hash;
	public:
		RollingHashPart() {}
		template<typename T>
		RollingHashPart(const T& s) : len(s.size()), pow_b(s.size() + 1), hash(s.size() + 1) {
			pow_b[0] = 1;
			hash[0] = 0;
			for (ll i = 0; i < len; i++) {
				pow_b[i + 1] = pow_b[i] * B % M;
				hash[i + 1] = (hash[i] * B + s[i]) % M;
			}
		}
		// [l, r)
		ll get(ll l, ll r) const {
			ll res = (hash[r] - hash[l] * pow_b[r - l]) % M;
			if (res < 0) res += M;
			return res;
		}
	};
public:
	RollingHashPart<1033, 1000000007> rh1;
	RollingHashPart<6037, 999999937> rh2;
 
	RollingHash() {}
	template<typename T> RollingHash(const T & s) : rh1(s), rh2(s) {}
	// [l, r)
	HashData get(ll l, ll r) const {
		return (HashData){ rh1.get(l, r), rh2.get(l, r) };
	}

	lpair getPair(ll l, ll r) const {
		return make_pair(rh1.get(l,r) , rh2.get(l, r));
	}
	// [l1, r1), [l2, r2)
	ll lcp(const RollingHash & rhs, ll l1, ll r1, ll l2, ll r2) const {
		ll lb = 0, ub = min(r1 - l1, r2 - l2) + 1;
		while (ub - lb > 1) {
			ll md = (lb + ub) >> 1;
			(get(l1, l1 + md) == rhs.get(l2, l2 + md) ? lb : ub) = md;
		}
		return lb;
	}
};

bool is_pali(string S){
    ll sz = S.size();
    bool ok = true;
    rep(i,0,sz/2){
        if(S[i] != S[sz-1-i]) ok = false;
    }
    return ok;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--){
        string S;
        cin >> S;
        ll N = S.size();
        string T = S;
        reverse(T.begin(), T.end());
        RollingHash rh(S), rh2(T);
        string ans = "";
        ll len = 0;
        rrep(i,N/2,1){
            lpair lv = rh.getPair(0, i);
            lpair rv = rh2.getPair(0, i);
            if(lv == rv){
                len = i;
                break;
            }
        }
        // print(len);
        ll lv = len, rv = N-len-1;// [lv,rv]
        ll max_len = 0, max_idx = -1;
        rep(i,1,rv-lv+2){
            if(is_pali(S.substr(lv, i))){
                max_len = i;
                max_idx = i;
            }
        }
        ll max_len2 = 0, max_idx2 = -1;
        rep(i,1,rv-lv+2){
            if(is_pali(S.substr(rv-i+1, i))){
                max_len2 = i;
                max_idx2 = i;
            }
        }
        // print(max_len2, max_idx2);
        if(max_len >= max_len2){
            string ans = S.substr(0, len + max_len) + S.substr(N-len, len);
            print(ans);
        }else{
            string ans = S.substr(0, len) + S.substr(N-len-max_len2, len + max_len2);
            print(ans);
        }


    }
    

}