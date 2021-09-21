#include<iostream>

using namespace std;

#define ll long long int

struct data
{
	ll x, y;
};

ll mat[301][301];
ll visit[301][301];

bool inside(ll row, ll col, ll x, ll y) {
	if (x < 0 || y < 0 || x >= row || y >= col)
		return false;
	else
		return true;

}

void DFS(ll x, ll y, ll row, ll col) {

	visit[x][y] = 1;

	ll xMoves[] = { -1, 1, 0, 0};
	ll yMoves[] = {0, 0, -1, 1};

	data move[4];

	for (ll i = 0; i < 4; i++) {
		move[i].x = xMoves[i];
		move[i].y = yMoves[i];
	}

	for (ll i = 0; i < 4; i++) {
		if (inside(row, col, x + move[i].x , y + move[i].y) && mat[x + move[i].x][y + move[i].y] == 1 && visit[x + move[i].x][y + move[i].y] == 0)
			DFS(x + move[i].x, y + move[i].y, row, col);
	}

}

ll solve(ll row, ll col) {

	ll count = 0;

	for (ll i = 0; i < row; i++) {
		for (ll j = 0; j < col; j++)
			visit[i][j] = 0;
	}

	for (ll i = 0; i < row; i++) {
		for (ll j = 0; j < col; j++)
			if (mat[i][j] == 1 && visit[i][j] == 0) {
				DFS(i, j, row, col);
				count++;
			}
	}
	return count;

}

int main() {
	ll row, col, count = 0;
	cin >> row >> col;

	for (ll i = 0; i < row; i++) {
		for (ll j = 0; j < col; j++)
			cin >> mat[i][j];
	}

	cout << solve(row, col);

}