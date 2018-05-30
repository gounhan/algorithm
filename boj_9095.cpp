/*
https://www.acmicpc.net/problem/9095
*/

#include <iostream>
#include <stdio.h>
using namespace std;
int t, n;
int ans = 0;

/*
int main()
{
	cin >> t;
	while (t--) {
		cin >> n;
		for (int l1 = 1; l1 <= 3; l1++) {
			if (n == l1)
				ans++;
			for (int l2 = 1; l2 <= 3; l2++) {
				if (l1 + l2 == n)
					ans++;
				for (int l3 = 1; l3 <= 3; l3++) {
					if (l1 + l2 + l3 == n)
						ans++;
					for (int l4 = 1; l4 <= 3; l4++) {
						if (l1 + l2 + l3 + l4 == n)
							ans++;
						for (int l5 = 1; l5 <= 3; l5++) {
							if (l1 + l2 + l3 + l4 + l5 == n)
								ans++;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
*/

int go(int count, int sum, int goal)
{
	if (count > 10 || sum > goal)
		return 0;
	if (sum == goal)
		return 1;
	int now = 0;
	for (int i = 1; i <= 3; i++)
		now += go(count + 1, sum + i, goal);
	return now;
}

int main()
{
	cin >> n;
	cout << go(0, 0, n) << endl;
	return 0;
}
