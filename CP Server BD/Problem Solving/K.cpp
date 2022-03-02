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
int C(int n, int k) {
	double res = 1;
	for (int i = 1; i <= k; ++i)
		res = res * (n - k + i) / i;
	return (int)(res + 0.01);
}
void fop_cl()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
bool collinear(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return ((y3 - y2) * (x2 - x1) == (y2 - y1) * (x3 - x2));
}
int main()
{
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n; cin >> n;
	vector<pair<ll, ll>>v(n);
	for (auto &i : v) {
		cin >> i.first >> i.second;
	}
	ll res = C(n, 3);
	for (ll i = 0; i < n - 2; i++) {
		for (ll j = i + 1; j < n; j++) {
			for (ll k = j + 1; k < n; k++) {
				res -= collinear(v[i].first, v[i].second, v[j].first, v[j].second, v[k].first, v[k].second);
			}
		}
	}
	cout << res << nline;
	return 0;
}