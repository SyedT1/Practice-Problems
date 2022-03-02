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
void fop_cl()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
void solve() {
	ll mn = -1, mx = -1, n; cin >> n;
	for (ll i = 0; i < n; i++) {
		ll y; cin >> y;
		if (!i) {
			mx = mn = y;
		} else {
			mx = max(mx, y);
			mn = min(mn, y);
		}
	}
	cout << mx - mn << nline;
}
int main()
{
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t; cin >> t;
	while (t--)
		solve();
	return 0;
}