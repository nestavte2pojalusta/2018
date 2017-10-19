#include "stdafx.h"

#include <iostream>

using namespace std;

int main()
{
	cout << "Enter matrix 4x4 : use numbers 2, 4, 8, 16...(Enter each new number after a 'SPACE', go to a new line with 'ENTER'" << endl;
	int m[4][4], d = 0, s = 0, w = 0;
	char op;
	for (d = 0; d<4; ++d) {
		for (s = 0; s<4; ++s) {
			cin >> m[d][s];
		}
	}
	cout << endl << "Use the keys 's'(move down), 'w'(move up), 'a'(move left), 'd'(move right) to move the tiles" << endl;
	for (d = 0; d<4; ++d) {
		for (s = 0; s<4; ++s) {
			if (m[d][s] == 0) {
				cout << "* ";
			}
			else {
				cout << m[d][s] << " ";
			}
		}
		cout << endl;
	}
	while (cin >> op) {
		if (op == 'q') {
			break;
		}
		if (op == 's') {
			for (s = 0; s<4; ++s) {
				for (d = 3; d >= 0; --d) {
					if (m[d][s] != 0) {
						for (w = d - 1; w >= 0; --w) {
							if (m[w][s] != 0) {
								if (m[w][s] == m[d][s]) {
									m[d][s] = m[d][s] + m[w][s];
									m[w][s] = 0;
								}
								break;
							}
						}
						while (m[d + 1][s] == 0) {
							if (d<3) {
								m[d + 1][s] = m[d][s];
								m[d][s] = 0;
								d = d + 1;
							}
							else { break; }
						}
						d = w;
					}
				}
			}
		}
		if (op == 'w') {
			for (s = 0; s<4; ++s) {
				for (d = 0; d<4; ++d) {
					if (m[d][s] != 0) {
						for (w = d + 1; w<4; ++w) {
							if (m[w][s] != 0) {
								if (m[w][s] == m[d][s]) {
									m[d][s] = m[d][s] + m[w][s];
									m[w][s] = 0;
								}
								break;
							}
						}
						while (m[d - 1][s] == 0) {
							if (d>0) {
								m[d - 1][s] = m[d][s];
								m[d][s] = 0;
								d = d - 1;
							}
							else { break; }
						}
						d = w;
					}
				}
			}
		}
		if (op == 'a') {
			for (d = 0; d<4; ++d) {
				for (s = 0; s<4; ++s) {
					if (m[d][s] != 0) {
						for (w = s + 1; w<4; ++w) {
							if (m[d][w] != 0) {
								if (m[d][w] == m[d][s]) {
									m[d][s] = m[d][s] + m[d][w];
									m[d][w] = 0;
								}
								break;
							}
						}
						while (m[d][s - 1] == 0) {
							if (s>0) {
								m[d][s - 1] = m[d][s];
								m[d][s] = 0;
								s = s - 1;
							}
							else { break; }
						}
						s = w;
					}
				}
			}
		}
		if (op == 'd') {
			for (d = 0; d<4; ++d) {
				for (s = 3; s >= 0; --s) {
					if (m[d][s] != 0) {
						for (w = s - 1; w >= 0; --w) {
							if (m[d][w] != 0) {
								if (m[d][w] == m[d][s]) {
									m[d][s] = m[d][s] + m[d][w];
									m[d][w] = 0;
								}
								break;
							}
						}
						while (m[d][s + 1] == 0) {
							if (s<3) {
								m[d][s + 1] = m[d][s];
								m[d][s] = 0;
								s = s + 1;
							}
							else { break; }
						}
						s = w;
					}
				}
			}
		}
		for (d = 0; d<4; ++d) {
			for (s = 0; s<4; ++s) {
				if (m[d][s] == 0) {
					cout << "* ";
				}
				else {
					cout << m[d][s] << " ";
				}
			}
			cout << endl;
		}
	}
}
