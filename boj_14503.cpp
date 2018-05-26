/*
https://www.acmicpc.net/problem/14503
*/

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

bool map[50][50];
bool visit[50][50];
int dr[4] = { -1, 0, 1, 0 }; // 북 남
int dc[4] = { 0, 1, 0, -1 }; // 동 서
int n, m;
int r, c, d;

int main()
{
	int count = 0;

	ifstream fin("input.txt");

	fin >> n >> m;
	fin >> r >> c >> d;

	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fin >> map[i][j];
		}
	}

	while (1) {
	no_1:
		visit[r][c] = 1; // 현재 위치 청소
		count = 0;

	no_2:
		// 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로
		// 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춤
		if (count == 4) {
			if (d == 0 || d == 2) {
				r = r - dr[d];
				if (map[r][c] == 1)
					break;
				count = 0;
				goto no_2;
			}
			if (d == 1 || d == 3) {
				c = c - dc[d];
				if (map[r][c] == 1)
					break;
				count = 0;
				goto no_2;
			}
		}

		// 북 남
		if (d == 0 || d == 2) {
			// 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행
			int left = c + dr[d];
			if (map[r][left] == 0 && visit[r][left] == 0) {
				d = d - 1;
				if (d < 0)
					d = d + 4;
				c = left;
				goto no_1;
			}
			// 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로
			else if (map[r][left] == 1 || visit[r][left] == 1) {
				d = d - 1;
				if (d < 0)
					d = d + 4;
				count += 1;
				goto no_2;
			}
		}
		// 동 서
		if (d == 1 || d == 3) {
			// 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행
			int left = r - dc[d];
			if (map[left][c] == 0 && visit[left][c] == 0) {
				d = d - 1;
				if (d < 0)
					d = d + 4;
				r = left;
				goto no_1;
			}
			// 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로
			else if (map[left][c] == 1 || visit[left][c] == 1) {
				d = d - 1;
				if (d < 0)
					d = d + 4;
				count += 1;
				goto no_2;
			}
		}
	}

	// 청소한 구역 합산
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += visit[i][j];
		}
	}
	cout << ans;

	return 0;
}