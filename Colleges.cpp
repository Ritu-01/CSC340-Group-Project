#include "Colleges.h"
#include <algorithm>
#include <iomanip>
#include <ios>
//read from the 2 data files csv.
void Colleges::readDataFromSchoolByType(string fileDir){
    vector<string> row;
    College college;
    string fileName1, word;
    
    //file pointer
    ifstream fin;

    //open an existing record
    fin.open(fileDir, ios::in);
    if (!fin.is_open()){
        cout << "Could not open file salaries-by-college-type.csv ###" << endl;
        return;
    }
    
    //fin >> fileName1;
    //getline(fin, fileName1);
    int counter = 0;
    while (getline(fin, fileName1)){
        if (counter > 0){
        row.clear();
        stringstream str(fileName1);
        
        while (getline(str, word, ',')){
            row.push_back(word);
        }
        college.setSchoolName(row[0]);
        college.setSchoolType(row[1]);
        college.setStartingMedianSalary(stod(row[2]));
        college.setMidCareerMedianSalary(stod(row[3]));
        college.setMidCareer10th(stod(row[4]));
        college.setMidCareer25th(stod(row[5]));
        college.setMidCareer75th(stod(row[6]));
        college.setMidCareer90th(stod(row[7]));
        collegesBySchoolType.push_back(college);
        }
        counter++;
    }
    cout << "salaries-by-college-type.csv successfully read" << endl;
    //close file
    fin.close();
}

//read data from school by region
void Colleges::readDataFromSchoolByRegion(string fileDir){
    vector<string> row;
    College college;
    string fileName1, word;
    
    //file pointer
    ifstream fin;

    //open an existing record
    fin.open(fileDir, ios::in);
    if (!fin.is_open()){
        cout << "Could not open file salaries-by-college-type.csv ###" << endl;
        return;
    }
    
    //getline(fin, fileName1);
    int counter = 0;
    while (getline(fin, fileName1)){
        if (counter > 0){
        row.clear();
        stringstream str(fileName1);
        
        while (getline(str, word, ',')){
            row.push_back(word);
        }
        college.setSchoolName(row[0]);
        college.setSchoolRegion(row[1]);
        college.setStartingMedianSalary(stod(row[2]));
        college.setMidCareerMedianSalary(stod(row[3]));
        college.setMidCareer10th(stod(row[4]));
        college.setMidCareer25th(stod(row[5]));
        college.setMidCareer75th(stod(row[6]));
        college.setMidCareer90th(stod(row[7]));
        collegesByRegion.push_back(college);
        }
        counter++;
    }
    cout << "salaries-by-region.csv successfully read" << endl;
    //close file
    fin.close();
}

void Colleges::printCollegesBySchoolType(){
  printColleges(collegesBySchoolType , "School Type");
}

void Colleges::printCollegesByRegion(){
  printColleges(collegesByRegion , "School Region");
}

void Colleges::printColleges(vector<College> colleges, string typeOrRegion){
  cout << endl;
  cout << left << setw(40) << "School Name" << " | ";
  cout << left << setw(13) << typeOrRegion << " | ";
  cout << left << setw(16) << "Starting Median" << " | ";
  cout << left << setw(18) << "Mid-Career Median" << " | ";
  cout << left << setw(15) << "Mid-Career 90th";
  cout << endl;
  cout << "-----------------------------------------|---------------|------------------|--------------------|----------------" << endl;
  string tempName;
  string tempStr;
  for(auto college: colleges){
    tempName = college.getSchoolName();

    if(typeOrRegion == "School Type"){
      tempStr = college.getSchoolTypeStr();
    }else{
      tempStr = college.getSchoolRegionStr();
    }
    
    tempName.resize(40,' ');
    tempStr.resize(13,' ');

    cout << left << setw(40) << tempName << " | ";
    cout << left << setw(13) << tempStr << " | ";
    cout << fixed;
    cout << "$" << left << setw(15) << setprecision(2) << college.getStartingMedianSalary() << " | ";
    cout << "$" << left << setw(17) << setprecision(2) << college.getMidCareerMedianSalary() << " | ";
    cout << "$" << left << setw(15) << setprecision(2) << college.getMidCareer90th();
    cout << endl;
  }
  cout << endl;
}

//Based on the average of starting and mid-career median salary
vector<College> Colleges::RankCollegesBySchoolType(SchoolType theType, bool output){
  
  vector<College> tempColleges;

  for(auto college: collegesBySchoolType){
    if(college.getSchoolType() == theType){
      tempColleges.push_back(college);
    }
  }

  sort(tempColleges.begin(), tempColleges.end(), [](const College& a, const College&b) -> bool{
    double aScore = (a.getStartingMedianSalary() + a.getMidCareerMedianSalary())/2;
    double bScore = (b.getStartingMedianSalary() + b.getMidCareerMedianSalary())/2;
    return aScore > bScore;
  });
  
  if(output){
    cout << endl;
    cout << "School Type: " << toStrSchoolType(theType) << endl;
    cout << "Rank" << "   ";
    cout << left << setw(40) << "School Name" << "   ";
    cout << "Average Start & Mid Career Salary" << "   " << endl;
    for(int i = 0; i < tempColleges.size(); i++ ){
      string tempName = tempColleges[i].getSchoolName();
      tempName.resize(40,' ');
      cout  << right << setw(2) << i+1;
      cout  << left << setw(5) << ".";
      cout << left << setw(40) << tempName;
      cout << "               ";
      cout << "$" << fixed << setprecision(2);
      cout << (tempColleges[i].getStartingMedianSalary() + tempColleges[i].getMidCareerMedianSalary())/2.0 << endl;
    }
    cout << endl;
  }
  return tempColleges;
}

vector<College> Colleges::RankCollegesByRegion(Region theRegion, bool output){
  
  vector<College> tempColleges;

  for(auto college: collegesByRegion){
    if(college.getSchoolRegion() == theRegion){
      tempColleges.push_back(college);
    }
  }

  sort(tempColleges.begin(), tempColleges.end(), [](const College& a, const College&b) -> bool{
    double aScore = (a.getStartingMedianSalary() + a.getMidCareerMedianSalary())/2;
    double bScore = (b.getStartingMedianSalary() + b.getMidCareerMedianSalary())/2;
    return aScore > bScore;
  });
  if(output){
    cout << endl;
    cout << "School Region: " << toStrSchoolRegion(theRegion) << endl;
    cout << "Rank" << "   ";
    cout << left << setw(40) << "School Name" << "   ";
    cout << "Average Start & Mid Career Salary" << "   " << endl;
    for(int i = 0; i < tempColleges.size(); i++ ){
      string tempName = tempColleges[i].getSchoolName();
      tempName.resize(40,' ');
      cout  << right << setw(2) << i+1;
      cout  << left << setw(5) << ".";
      cout << left << setw(40) << tempName;
      cout << "               ";
      cout << "$" << fixed << setprecision(2);
      cout << (tempColleges[i].getStartingMedianSalary() + tempColleges[i].getMidCareerMedianSalary())/2.0 << endl;
    }
    cout << endl;
  }
  return tempColleges;
}

//Ranl all colleges by Region e.g. 1. California, 2. Northeastern,
vector<Region> Colleges::RankRegion(){
  vector<College> californiaColleges = RankCollegesByRegion(Region::California);
  vector<College> westernColleges = RankCollegesByRegion(Region::Western);
  vector<College> midwesternColleges = RankCollegesByRegion(Region::Midwestern);
  vector<College> southernColleges = RankCollegesByRegion(Region::Southern);
  vector<College> northeasternColleges = RankCollegesByRegion(Region::Northeastern);

}
 
//Rank all colleges by school type e.g 1. Ivy League, 2. Engineering
vector<SchoolType> RankSchoolType();

double Colleges::regionScorer(vector<College> colleges){

}
    
double schoolTypeScorer(vector<College> colleges);
