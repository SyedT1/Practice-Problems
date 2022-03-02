#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <unordered_map>
#include <fstream>
#include <sstream>
#define nline '\n'
#define len(s) ll((s).size())
#define pb push_back
#define pp pop_back
#define loop(x, n) for(int x = 0; x < n; ++ x)
using namespace std;
using ll = long long int;
using par = pair<ll, ll>;

template <typename T>
ostream &operator<<(ostream &out, pair<T, T>p) {
	out << p.first << ' ' << p.second;
	return out;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> v)
{
	for (T i : v)
	{
		out << i << ' ';
	}
	return out;
}
istream &operator>>(istream &in, vector<ll> &v)
{
	for (ll &i : v)
	{
		cin >> i;
	}
	return in;
}
struct combo {
	ll lft, right;
	string va;
};
void fop_cl()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
void solve() {
	ll found = 0;
	string s; cin >> s;
	vector<combo>v;
	for (ll i = 0, sl = s.length(); i < sl; i++) {
		ll ff = 0, strt = i, en = i;
		while (i < sl && s[i] == '?') {
			en = i;
			ff++;
			i++;
			if (i == sl && strt == 0) {
				while (ff > 1) {
					cout << "ab";
					ff -= 2;
				}
				if (ff == 1)cout << 'a';
				cout << nline;
				return;
			}
		}
		if (ff) {
			string recons;
			if (strt == 0) {
				if (en + 1 > s.length()) {
					while (ff > 1) {
						recons += "ab";
						ff -= 2;
					}
					if (ff == 1) {
						recons += 'a';
					}
				} else {
					string addum = "";
					switch (s[en + 1]) {
					case 'a':
						addum = "bc";
						break;
					case 'b':
						addum = "ac";
						break;
					case 'c':
						addum = "ab";
						break;
					}
					while (ff > 1) {
						recons += addum;
						ff -= 2;
					}
					if (ff == 1) {
						recons += addum[0];
					}
				}
			} else {
				set<char>p;
				char la = s[strt - 1], ra = s[en + 1 == sl ? en : en + 1];
				string alga;
				p.insert(s[strt - 1]);
				p.insert(s[en + 1 == sl ? en : en + 1]);
				char lop = '\0';
				for (char c : {'a', 'b', 'c'}) {
					if (!p.count(c)) {
						lop = c;
						break;
					}
				}
				if (la == ra) {
					goto build;
				}
				else {
					alga += lop;
					alga += s[strt - 1];
				}
				while (ff > 1) {
					recons += alga;
					ff -= 2;
				}
				if (ff == 1) {
					recons += alga[0];
				}
			}
			v.pb({strt, en, recons});
		}
	}
	for (auto i : v) {
		ll p = 0;
		for (ll j = i.lft; j <= i.right; j++) {
			s[j] = i.va[p++];
		}
	}
	for (ll i = 0, sl = s.length(); i < sl; i++) {
		if (i < sl - 1 && s[i] == s[i + 1]) {
			cout << -1 << nline;
			return;
		}
	}
	cout << s << nline;
}
int main()
{
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}