/*
https://www.acmicpc.net/problem/14503
*/

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

bool map[50][50];
bool visit[50][50];
int dr[4] = { -1, 0, 1, 0 }; // �� ��
int dc[4] = { 0, 1, 0, -1 }; // �� ��
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
		visit[r][c] = 1; // ���� ��ġ û��
		count = 0;

	no_2:
		// �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������
		// ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� ����
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

		// �� ��
		if (d == 0 || d == 2) {
			// ���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ ����
			int left = c + dr[d];
			if (map[r][left] == 0 && visit[r][left] == 0) {
				d = d - 1;
				if (d < 0)
					d = d + 4;
				c = left;
				goto no_1;
			}
			// ���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������
			else if (map[r][left] == 1 || visit[r][left] == 1) {
				d = d - 1;
				if (d < 0)
					d = d + 4;
				count += 1;
				goto no_2;
			}
		}
		// �� ��
		if (d == 1 || d == 3) {
			// ���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ ����
			int left = r - dc[d];
			if (map[left][c] == 0 && visit[left][c] == 0) {
				d = d - 1;
				if (d < 0)
					d = d + 4;
				r = left;
				goto no_1;
			}
			// ���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������
			else if (map[left][c] == 1 || visit[left][c] == 1) {
				d = d - 1;
				if (d < 0)
					d = d + 4;
				count += 1;
				goto no_2;
			}
		}
	}

	// û���� ���� �ջ�
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += visit[i][j];
		}
	}
	cout << ans;

	return 0;
}