#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>

using namespace std;

bool contains(vector<int> v, int i) {
	for (int num : v) {
		if (num == i) {
			return true;
		}
	}
	return false;
}

void shuffle(int card[], int n)
{
	// Initialize seed randomly 
	srand(time(0));

	for (int i = 0; i < n; i++)
	{
		// Random for remaining positions. 
		int r = i + (rand() % (n - i));

		swap(card[i], card[r]);
	}
}

int main() {
	vector<int> dmg;
	int deck[60];
	int count = 0;
	for (int i = 0; i < 60; i++) {
		deck[i] = 0;
	}
	/*
	0 = land
	1 = treasure hunt
	2 = reliquary tower
	3 = zombie infestation
	*/
	for (int i = 2; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			deck[count] = j;
			count++;
		}
	}
	int infestations = 4;
	for (int i = 0; i < infestations; i++) {
		deck[count] = 3;
		count++;
	}

	shuffle(deck, 60);
	vector<int> hand;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			hand.push_back(deck[j]);
		if (contains(hand,1)) {
			break;
		}
		else {
			hand.clear();
			shuffle(deck,60);
		}
	}
	while (true) {
		int lands = 0;
		if (contains(hand, 0)) {

		}
	}
	return 0;
}
