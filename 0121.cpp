#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int COL_SIZE = 2;
const int ROW_SIZE = 4;

int puzzle[COL_SIZE][ROW_SIZE];
int final_puzzle[COL_SIZE][ROW_SIZE];

int main() {
	for (int i = 0; i < COL_SIZE; i++)
		for (int j = 0; j < ROW_SIZE; j++) final_puzzle[i][j] = i * ROW_SIZE + j;

	while (cin) {
		for (int i = 0; i < COL_SIZE; i++)
			for (int j = 0; j < ROW_SIZE; j++) cin >> puzzle[i][j];

		while (true) {
			bool f = true;
			for (int i = 0; i < COL_SIZE; i++)
				for (int j = 0; j < ROW_SIZE; j++) f = (puzzle[i][j] == final_puzzle[i][j]);
			if (f) {
				cout << "OK" << endl;
				break;
			}
		}

	}

	return 0;
}
