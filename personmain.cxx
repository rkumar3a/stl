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

	return EXIT_SUCCESS;
}
