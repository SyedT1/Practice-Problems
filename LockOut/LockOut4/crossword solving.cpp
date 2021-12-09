#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <unordered_map>
#define nline '\n'
#define len(s) ll((s).size())
#define pb push_back
#define pp pop_back
#define FOR(i, n) for (i = 0; i < n; i++)
using namespace std;
using ll = long long int;
using par = pair<ll, ll>;
ostream &operator<<(ostream &out, vector<ll> v)
{
	for (ll i : v)
	{
		out << i << ' ';
	}
	return out;
}
istream &operator>>(istream &in, vector<ll> &v)
{
	ll l = len(v);
	FOR(i, l)
	{
		cin >> v[i];
	}
	return in;
}
void fop_cl()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
void solve() {
	ll n, k; cin >> n >> k;
	string s, t; cin >> s >> t;
	ll mx = 0;
	vector<ll>kv;
	ll r = 0;
	for (ll i = 0; i <= k - n; i++, r++) {
		ll sim = 0, y = i;
		vector<ll>v;
		for (ll j = 0; j < n; j++, y++) {
			if (t[y] == s[j]) {
				sim++;
			} else {
				v.pb(j + 1);
			}
		}
		if (r == 0) {
			mx = sim;
			kv = v;
			continue;
		}
		if (mx < sim) {
			kv = v;
			mx = sim;
		}
	}
	cout << n - mx << nline << kv << nline;
}
int main()
{
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}