#include "Colleges.h"
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
  cout << endl;
  cout << left << setw(40) << "School Name" << " | ";
  cout << left << setw(12) << "School Type" << " | ";
  cout << left << setw(16) << "Starting Median" << " | ";
  cout << left << setw(18) << "Mid-Career Median" << " | ";
  cout << left << setw(15) << "Mid-Career 90th";
  cout << endl;
  cout << "-----------------------------------------|--------------|------------------|--------------------|---------------" << endl;
  for(auto college: collegesBySchoolType){
    string tempName = college.getSchoolName();
    string tempType = college.getSchoolTypeStr();
    
    tempName.resize(40,' ');
    tempType.resize(12,' ');

    cout << left << setw(40) << tempName << " | ";
    cout << left << setw(12) << tempType << " | ";
    cout << fixed;
    cout << "$" << left << setw(15) << setprecision(2) << college.getStartingMedianSalary() << " | ";
    cout << "$" << left << setw(17) << setprecision(2) << college.getMidCareerMedianSalary() << " | ";
    cout << "$" << left << setw(15) << setprecision(2) << college.getMidCareer90th();
    cout << endl;
  }
  cout << endl;
}

void Colleges::printCollegesByRegion(){
  cout << endl;
  cout << left << setw(40) << "School Name" << " | ";
  cout << left << setw(12) << "School Region" << " | ";
  cout << left << setw(16) << "Starting Median" << " | ";
  cout << left << setw(18) << "Mid-Career Median" << " | ";
  cout << left << setw(15) << "Mid-Career 90th";
  cout << endl;
  cout << "-----------------------------------------|---------------|------------------|--------------------|---------------" << endl;
  for(auto college: collegesByRegion){
    string tempName = college.getSchoolName();
    string tempRegion = college.getSchoolRegionStr();
    
    tempName.resize(40,' ');
    tempRegion.resize(13,' ');

    cout << left << setw(40) << tempName << " | ";
    cout << left << setw(13) << tempRegion << " | ";
    cout << fixed;
    cout << "$" << left << setw(15) << setprecision(2) << college.getStartingMedianSalary() << " | ";
    cout << "$" << left << setw(17) << setprecision(2) << college.getMidCareerMedianSalary() << " | ";
    cout << "$" << left << setw(15) << setprecision(2) << college.getMidCareer90th();
    cout << endl;
  }
  cout << endl;
}

