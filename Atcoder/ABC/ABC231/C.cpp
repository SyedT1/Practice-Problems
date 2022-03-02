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
	ll n, q; cin >> n >> q;
	vector<ll>v(n);
	for (ll &i : v) {
		cin >> i;
	}
	sort(v.begin(), v.end());
	for (ll i = 0; i < q; i++) {
		ll val; cin >> val;
		//cout << val << nline;
		ll yl = -1, left = 0, right = n - 1;
		while (left <= right) {
			ll middle = left + (right - left) / 2;
			if (v[middle] >= val) {

				yl = middle;
				right = middle - 1;
			} else {
				left = middle + 1;
			}
		}
		cout << (yl > -1)*( n - yl) << nline;
	}
}
int main()
{
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}