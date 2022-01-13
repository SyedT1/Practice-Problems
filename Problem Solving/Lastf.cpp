#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <cmath>
#define nline '\n'
#define len(s) ll((s).size())
#define pb push_back
#define pp pop_back
#define loop(x, n) for(int x = 0; x < n; ++ x)
using namespace std;
using ll = long long int;
using par = pair<ll, ll>;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
	ll N; cin >> N;
	ll numdiv = 0;
	for (ll i = 1; i * i <= N; i++) {
		ll l = i, r = N, t = -1;
		while (l <= r) {
			ll mid = l + (r - l) / 2;
			if (N - i * mid > 0) {
				t = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		numdiv += ((t > 0) * (t - i + 1) * 2);
	}
	ll j = 1;
	while (N - j * j > 0) {
		numdiv--;
		j++;
	}
	cout << numdiv << nline;
}
int main()
{
	fop_cl();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}