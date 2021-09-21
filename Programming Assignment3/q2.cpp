#include<iostream>

using namespace std;

#define ll long long int

ll mat[1001][1001];
int front = 0, rear = 0;


struct data
{
	ll x, y;
};

data queue1[1000000];

void enqueue(data val) {
	queue1[rear++] = val;
}
void dequeue() {
	front++;
}

bool qempty() {
	if (front == rear)
		return true;
	else
		return false;
}

bool inside(ll row, ll col, ll x, ll y) {
	if (x < 0 || y < 0 || x >= row || y >= col)
		return false;
	else
		return true;

}

ll completeWard(ll row, ll col) {
	for (ll i = 0; i < row; i++) {
		for (ll j = 0; j < col; j++) {
			if (mat[i][j] == 1) {
				return 1;
			}
		}
	}
	return 0;
}

ll covidPatients(ll row, ll col) {

	ll max_count = 0;
	ll count[row][col];
	for (ll i = 0; i < row; i++) {
		for (ll j = 0; j < col; j++) {
			count[i][j] = -1;
		}
	}
	data pos;

	for (ll i = 0; i < row; i++) {
		for (ll j = 0; j < col; j++) {
			if (mat[i][j] == 2) {
				pos.x = i; pos.y = j;
				count[i][j] = 0;
				enqueue(pos);
			}
		}
	}

	while (!qempty()) {

		data move;
		move = queue1[front];

		if (max_count < count[move.x][move.y])max_count = count[move.x][move.y];

		dequeue();

		if (inside(row, col, move.x - 1, move.y) && mat[move.x - 1][move.y] == 1) {
			mat[move.x - 1][move.y] = 2;
			count[move.x - 1][move.y] = count[move.x][move.y] + 1;
			move.x--;
			enqueue(move);
			move.x++;
		}
		if (inside(row, col, move.x + 1, move.y) && mat[move.x + 1][move.y] == 1) {
			count[move.x + 1][move.y] = count[move.x][move.y] + 1;
			mat[move.x + 1][move.y] = 2;
			move.x++;
			enqueue(move);
			move.x--;
		}
		if (inside(row, col, move.x, move.y - 1) && mat[move.x][move.y - 1] == 1) {
			count[move.x][move.y - 1] = count[move.x][move.y] + 1;
			mat[move.x][move.y - 1] = 2;
			move.y--;
			enqueue(move);
			move.y++;
		}
		if (inside(row, col, move.x, move.y + 1) && mat[move.x][move.y + 1] == 1) {
			count[move.x][move.y + 1] = count[move.x][move.y] + 1;
			mat[move.x][move.y + 1] = 2;
			move.y++;
			enqueue(move);
			move.y--;
		}
	}

	if (completeWard(row, col))
		return -1;
	else
		return max_count;

}

int main() {
	ll row, col;
	cin >> row >> col;

	for (ll i = 0; i < row; i++) {
		for (ll j = 0; j < col; j++)
			cin >> mat[i][j];
	}

	cout << covidPatients(row, col);

}