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
	ll n; cin >> n;
	vector<ll>v(n);
	pair<ll, ll>mx = { -1, -1}, mn = { -1, -1};
	for (ll i = 0; i < n; i++)
	{
		cin >> v[i];
		if (!i) {
			mn = mx = {v[i], 0};
		} else {
			mn = min(mn, {v[i], i});
			mx = max(mx, {v[i], i});
		}
	}
	while (mx.first - mn.first > 1) {
		if (mx.first % 2 == mn.first % 2) {
			ll avg = (mx.first + mn.first) / 2;
			mx.first = mn.first = avg;
			v[mx.second] = v[mn.second] = avg;
		} else {
			ll avg = (mx.first + mn.first) / 2;
			if (mx.first % 2) {
				v[mx.second] = mx.first = avg + 1;
				v[mn.second] = mn.first = avg;
			} else {
				v[mx.second] = mx.first = avg;
				v[mn.second] = mn.first = avg + 1;
			}
		}
		for (ll i = 0; i < n; i++) {
			mx = max(mx, {v[i], i});
			mn = min(mn, {v[i], i});
		}
	}
	cout << abs(mx.first - mn.first) << nline;
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