#ifndef College_h
#define College_h


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

//enum class school type
enum class SchoolType{
    Engineering, Party, Liberal_Arts, Ivy_League, States};

//enum class school region
enum class Region{California, Western, Midwestern, Southern, Northeastern};

//college class
class College{
  private:
    string schoolName;
    string schoolType;
    SchoolType type;
    Region region;
    string schoolRegion;
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
    void setSchoType(SchoolType schoolType);
    void setSchoolRegion(string theRegion);
    void setStartingMedianSalary(double startingMed);
    void setMidCareerMedianSalary(double midCareer);
    void setMidCareer10th(double mid10th);
    void setMidCareer25th(double mid25th);
    void setMidCareer75th(double mid75th);
    void setMidCareer90th(double mid90th);

    //Getter
    string getSchoolName() const;
    string getSchoolType() const;
    SchoolType getSchoType() const;
    string getSchoolRegion() const;
    double getStartingMedianSalary() const;
    double getMidCareerMedianSalary() const;
    double getMidCareer10th() const;
    double getMidCareer25th() const;
    double getMidCareer75th() const;
    double getMidCareer90th() const;

    
};

#endif //end of College_h