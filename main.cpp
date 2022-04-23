#include <iostream>
#include "Colleges.h"
#include "Colleges.cpp"
#include "College.h"
#include "College.cpp"

int main() {
    Colleges myColleges;
    myColleges.readDataFromSchoolByRegion("dataset/salaries-by-college-type.csv");
    myColleges.readDataFromSchoolByType("dataset/salaries-by-region.csv");
    return 0;
}
