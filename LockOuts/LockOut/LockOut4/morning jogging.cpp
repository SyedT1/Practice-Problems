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
	for (ll &i : v)
	{
		cin >> i;
	}
	return in;
}
void fop_cl()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
void solve() {
	ll k, n; cin >> k >> n;
	vector<vector<ll>>p, reconstruct(k, vector<ll> {});
	for (ll i = 0; i < k; i++) {
		vector<ll>v(n);
		cin >> v;
		sort(v.rbegin(), v.rend());
		p.pb(v);
	}
	ll sum = 0;
	ll y = 0;
	vector<par>r;
	while (y < n) {
		par mn = {p[0].back(), 0};
		for (ll i = 0; i < k; i++) {
			mn = min(mn, {p[i].back(), i});
		}
		sum += mn.first;
		r.pb({mn});
		p[mn.second].pop_back();
		y++;
	}
	y = 0;
	unordered_map<ll, ll>MP;
	while (y < n) {
		reconstruct[r[y].second].pb(r[y].first);
		for (ll i = 0; i < k; i++) {
			if (i != r[y].second) {
				reconstruct[i].pb(p[i][MP[i]]);
				MP[i]++;
			}
		}
		y++;
	}
	for (ll i = 0; i < k; i++) {
		cout << reconstruct[i] << nline;
	}
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