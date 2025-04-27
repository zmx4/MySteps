import std;
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string n;
	cin >> n;
	int x;
	cin >> x;
	// reverse(n.begin(), n.end());
	for(auto c:n)
		cout << c << endl;
	cout << x++ << endl;
	x--;
	cout << ++x << endl;
	// mdspan<char, std::array<std::size_t, 2>> m(n.data(), n.size(), 1);
	return 0;
}