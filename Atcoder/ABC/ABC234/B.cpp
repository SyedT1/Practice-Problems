#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <cmath>
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
void fop_cl()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
void solve() {
	ll n; cin >> n;
	vector<pair<ll, ll>>v;
	for (ll i = 0; i < n; i++) {
		ll l, r; cin >> l >> r;
		v.pb({l, r});
	}
	sort(v.begin(), v.end());
	double mN = -1;
	for (ll i = 0; i < n - 1; i++) {
		for (ll j = i + 1; j < n; j++) {
			ll V1 = abs(v[i].first - v[j].first);
			ll V2 = abs(v[i].second - v[j].second);
			if (mN < 0) {
				mN = sqrt(V1 * V1 + V2 * V2);
			} else {
				mN = min(mN, sqrt(V1 * V1 + V2 * V2));
			}
		}
	}
	cout << fixed << setprecision(6) << mN << nline;
}
int main()
{
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}