/*
 * Sin-Yaw Wang <swang24@scu.edu>
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include "person.h"

using namespace std;
using namespace csen79;

inline double BMI(const double weight, const double height) {
	return (weight / (height * height)) * 703.0;
}

struct CmpLessBMI {
	const bool operator()(Person x, double y) {return BMI(x.getWeight(), x.getHeight()) < y; }
};

struct genderedBMI {
	double BMI;
	Person::Gender gender;
};

int main(int argc, char *argv[]) {
    std::vector<Person> plist;
    Person p;
	constexpr double targetHeight = 70.0;
	constexpr double targetWeight = 150.0;
	const double targetBMI = BMI(targetWeight, targetHeight);
	constexpr Person::Gender targetGender = Person::Female;
	const std::pair<double, string> BMICategory[] = {{18.85, "Underweight"},
	                                         {24.99, "Normal weight"},
											 {29.99, "Overweight"},
											 {1000.0, "Obesity"}};

    while (std::cin >> p)
        plist.push_back(p);

	auto it = lower_bound(plist.begin(), plist.end(), p);
	cout << setprecision(2);

	/*
	 * Students to do:
	 * 1. Compute percentage of people within each BMI range.
	 * 2. Sort the records by gender then by last name.
	 * 3. Find the first person at or more than the target height
	 * 4. Find the person at or just more than the target weight and of the target gender
	 * 5. Find the first person at or more than the target BMI.
	 *
	 * For 1, use "std::map" to collect the count.
	 * For 2 to 5, make use of the C++ "iterator" feature.
	 *
	 * For the above, must use each of the below at least once.
	 * Function pointer, lambda function, and functor
	 */
	cout << "Person at or more than the target BMI and of the target gender:" << endl;
	if ((it = lower_bound(plist.begin(), plist.end(), nullptr, [targetBMI, targetGender](Person x, void * ignore) { return (BMI(x.getWeight(), x.getHeight()) < targetBMI) || (x.getGender() != targetGender); })) != plist.end())
		cout << "Found " << *it << ": " << BMI(it->getWeight(), it->getHeight()) << " >= " << targetBMI << " gender is: " << it->getGender() << endl;
	else
		cout << "No person found." << endl;

	cout << "First person at or more than the target BMI:" << endl;
	CmpLessBMI lessFunctor;
	if ((it = lower_bound(plist.begin(), plist.end(), targetBMI, lessFunctor)) != plist.end())
		cout << "Found " << *it << ": " << BMI(it->getWeight(), it->getHeight()) << " >= " << targetBMI << endl;
	else
		cout << "No person found." << endl;
	return EXIT_SUCCESS;
}
