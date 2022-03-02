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
	string res;
	vector<string>s(n - 2);
	for (string &i : s) {
		cin >> i;
		res += i;
	}
	ll m = s.size() * 2, sle = n - 2;
	if (m < n) {
		cout << res + string(abs(m - n), 'b') << nline;
		return;
	}
	while (true) {
		bool f = false;
		for (ll i = 0; i < sle - 1; i++) {
			string s1 = s[i], s2 = s[i + 1];
			if (s1.length() > 1 && s2.length() > 1) {
				if (s1[1] == s2[0]) {
					m--;
					f = true;
					s[i].pop_back();
					break;
				}
			}
		}
		if (f == false || n == m) {break;}
	}
	for (string i : s) {
		cout << i ;
	}
	cout << nline;
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