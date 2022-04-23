#ifndef College_h
#define College_h


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include "EnumTypeRegion.h"

using namespace std;



//college class
class College{
  private:
    string schoolName;
    SchoolType type;
    Region region;
    double StartingMedianSalary;
    double MidCareerMedianSalary;
    double MidCareer10th;
    double  MidCareer25th;
    double MidCareer75th;
    double MidCareer90th;
    //Double Difference;
  public:
    //Setter
    void setSchoolName(string theSchoolName);
    void setSchoolType(string theType);
    void setSchoolRegion(string theRegion);
    void setStartingMedianSalary(double startingMed);
    void setMidCareerMedianSalary(double midCareer);
    void setMidCareer10th(double mid10th);
    void setMidCareer25th(double mid25th);
    void setMidCareer75th(double mid75th);
    void setMidCareer90th(double mid90th);

    //Getter
    string getSchoolName() const;
    string getSchoolTypeStr() const;
    SchoolType getSchoolType() const;
    string getSchoolRegionStr() const;
    Region getSchoolRegion() const;
    double getStartingMedianSalary() const;
    double getMidCareerMedianSalary() const;
    double getMidCareer10th() const;
    double getMidCareer25th() const;
    double getMidCareer75th() const;
    double getMidCareer90th() const;

    
};

#endif //end of College_h