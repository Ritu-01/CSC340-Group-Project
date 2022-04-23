#include "College.h"

//set school name
void College::setSchoolName(string theSchoolName){
  schoolName = theSchoolName;
}

//set school type string
void College::setSchoolType(string theType){
  type = toEnumSchoolType(theType);
}

//set school region
void College::setSchoolRegion(string theRegion){
  region = toEnumRegion(theRegion);
}

//set starting median salary
void College::setStartingMedianSalary(double startingMed){
  StartingMedianSalary = startingMed;
}

//set mid career median salary
void College::setMidCareerMedianSalary(double midCareer){
  MidCareerMedianSalary = midCareer;
}

//set mid 10th
void College::setMidCareer10th(double mid10th){
  MidCareer10th = mid10th;
}

//set mid 25th
void College::setMidCareer25th(double mid25th){
  MidCareer25th = mid25th;
}

//set mid 75th
void College::setMidCareer75th(double mid75th){
  MidCareer75th = mid75th;
}

//set mid 90th
void College::setMidCareer90th(double mid90th){
  MidCareer90th = mid90th;
}

//get school name
string College::getSchoolName() const{
  return schoolName;
}

//get school type 
SchoolType College::getSchoolType() const{
  return type;
}

//get school type string
string College::getSchoolTypeStr() const{
  return toStrSchoolType(type);
}

//get school region
Region College::getSchoolRegion() const{
  return region;
}

//get school region string
string College::getSchoolRegionStr() const{
  return toStrSchoolRegion(region);
}

//get starting salary
double College::getStartingMedianSalary() const{
  return StartingMedianSalary;
}

//get mid career salary
double College::getMidCareerMedianSalary() const{
  return MidCareerMedianSalary;
}

//get mid 10th
double College::getMidCareer10th() const{
  return MidCareer10th;
}

//get mid 25th
double College::getMidCareer25th() const{
  return MidCareer25th;
}

//get mid 75th
double College::getMidCareer75th() const{
  return MidCareer75th;
}

//get mid 90th
double College::getMidCareer90th() const{
  return MidCareer90th;
}

