/*
https://www.acmicpc.net/problem/1697
*/

#include <iostream>
#include <queue>
using namespace std;
const int MAX = 200000; // * 2를 했을 때 범위를 생각해서 100000 * 2
bool check[MAX + 1];
int dist[MAX + 1];

int main()
{
	int n, m;
	cin >> n >> m;
	check[n] = true;
	dist[n] = 0;
	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now - 1 >= 0) {
			if (check[now - 1] == false) {
				check[now - 1] = true;
				q.push(now - 1);
				dist[now - 1] = dist[now] + 1;
			}
		}

		if (now + 1 < MAX) {
			if (check[now + 1] == false) {
				check[now + 1] = true;
				q.push(now + 1);
				dist[now + 1] = dist[now] + 1;
			}
		}

		if (now * 2 < MAX) {
			if (check[now * 2] == false) {
				check[now * 2] = true;
				q.push(now * 2);
				dist[now * 2] = dist[now] + 1;
			}
		}

	}

	cout << dist[m] << endl;
	return 0;
}
