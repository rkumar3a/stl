/*
 * Sin-Yaw Wang <swang24@scu.edu>
 */
#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

// trivial less-than and equality functions for integer
bool lessComp(const int a, const int b) { return a < b; }
bool eqComp(const int a, const int b) { return a == b; }

// trivial less-than functor for integers
struct CmpLessThan {
	const bool operator()(int x, int y) {return x < y; }
};

int main(int argc, char *argv[]) {
	vector<int> vlist = {868, 909, 992, 619, 449, 564, 232, 447, 837, 847, 736, 636, 281, 938, 407,
	435, 771, 390, 488, 113, 726, 493, 185, 602, 339, 442, 200, 650, 179, 477, 712, 100,
	507, 382, 464, 461, 797, 141, 905, 191, 483, 454, 990, 337, 962, 514, 208, 172, 663,
	641, 453, 634, 416, 685, 721, 706, 930, 986, 987, 692, 113, 938, 114, 911, 141, 509,
	174, 678, 451, 308, 694, 822, 735, 668, 747, 464, 397, 400, 809, 930, 791, 537, 361,
	649, 828, 854, 135, 489, 275, 453, 421, 779, 627, 821, 238, 812, 174, 685, 149, 109};

	constexpr int target(464);	// what we are searching
	
	// std::map demo
	cout << "Histogram with std::map<>:" << endl;
	std::map<int, int> histgram;
	for (auto x : vlist)
		histgram[x / 100]++;
	if (histgram.contains(target / 100))
		cout << "Number within [" << setw(2) << setfill('0') << target / 100 *  100
			<< ", " << (target / 100 + 1 ) * 100  - 1 << "): " << histgram.find(target / 100)->second << endl;
	
	// standard way to find all occurrences in a vector, using operator==
	cout << "Find demo:" << endl;
	int i = 0;
	auto it = find(vlist.begin(), vlist.end(), target);
	while (it != vlist.end()) {
		cout << "Found " << ++i << ": " << *it++ << endl;
		it = find(it, vlist.end(), target);
	}

	// sort with a function as the 3rd argument
	cout << "Sort with function pointer:" << endl;
	sort(vlist.begin(), vlist.end(), lessComp);
	cout << "Sorted: " << endl;
	for (auto x : vlist)
		cout << i++ << ": " <<  x << endl;

	// binary search, return true/false with a function
	cout << "Binary search:" << endl;
	if (binary_search(vlist.begin(), vlist.end(), target, eqComp))
		cout << target << " exists" << endl;

	// use a functor to search
	cout << "Lower-Bound with functor:" << endl;
	CmpLessThan lessFunctor;
	if ((it = lower_bound(vlist.begin(), vlist.end(), target, lessFunctor)) != vlist.end())
		cout << "Found " << *it << " (" << it - vlist.begin() << ") >= " << target << endl;

	cout << "Upper-Bound with lambda:" << endl;
	if ((it = upper_bound(vlist.begin(), vlist.end(), target, [=](int x, int y) { return x < y; })) != vlist.end())
		cout << "Found " << *it << " (" << it - vlist.begin() << ") > " << target << endl;
	
	return EXIT_SUCCESS;
}
	
