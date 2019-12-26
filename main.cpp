#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using std::vector;

bool contains(const vector<int>& v, int i)
{
	return std::find(v.begin(), v.end(), i) != v.end();
}

void shuffle(int card[], int n)
{
	// Initialize seed randomly 
	std::srand(std::time(0));

	std::random_shuffle(card, card + n, [](int i) -> std::rand()%i);
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
