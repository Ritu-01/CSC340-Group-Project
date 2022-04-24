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
vector<pair<Region, double>> Colleges::RankRegion(bool output){
  vector<College> californiaColleges = RankCollegesByRegion(Region::California, false);
  vector<College> westernColleges = RankCollegesByRegion(Region::Western, false);
  vector<College> midwesternColleges = RankCollegesByRegion(Region::Midwestern, false);
  vector<College> southernColleges = RankCollegesByRegion(Region::Southern, false);
  vector<College> northeasternColleges = RankCollegesByRegion(Region::Northeastern, false);

  vector<pair<Region, double>> ranking;
  pair<Region, double> temp1 (Region::California, regionScorer(californiaColleges));
  pair<Region, double> temp2 (Region::Western, regionScorer(westernColleges));
  pair<Region, double> temp3 (Region::Midwestern, regionScorer(midwesternColleges));
  pair<Region, double> temp4 (Region::Southern, regionScorer(southernColleges));
  pair<Region, double> temp5 (Region::Northeastern, regionScorer(northeasternColleges));
  
  ranking.push_back(temp1);
  ranking.push_back(temp2);
  ranking.push_back(temp3);
  ranking.push_back(temp4);
  ranking.push_back(temp5);

  sort(ranking.begin(), ranking.end(), [](const pair<Region, double>& a, const pair<Region, double>& b) -> bool{
    return a.second > b.second;
  });
  
  if(output){
    cout << endl;
    cout << "Ranking Colleges by Region:" << endl;
    cout << "Rank" << "   ";
    cout << left << setw(18) << "School Region" << "   ";
    cout << "Total Score of Region" << "   " << endl;
    for(int i =0; i < ranking.size();i++){
      cout  << right << setw(2) << i+1;
      cout  << left << setw(5) << ".";
      cout << left << setw(18) << toStrSchoolRegion(ranking[i].first);
      cout << "          ";
      cout  << fixed << setprecision(2);
      cout << ranking[i].second << endl;
    }
  }
  return ranking;
}
 
//Rank all colleges by school type e.g 1. Ivy League, 2. Engineering
vector<pair<SchoolType,double>> Colleges::RankSchoolType(bool output){
  vector<College> engineeringColleges = RankCollegesBySchoolType(SchoolType::Engineering, false);
  vector<College> partyColleges = RankCollegesBySchoolType(SchoolType::Party, false);
  vector<College> liberalArtsColleges = RankCollegesBySchoolType(SchoolType::Liberal_Arts, false);
  vector<College> ivyLeagueColleges = RankCollegesBySchoolType(SchoolType::Ivy_League, false);
  vector<College> stateColleges = RankCollegesBySchoolType(SchoolType::State, false);

  vector<pair<SchoolType, double>> ranking;
  pair<SchoolType, double> temp1 (SchoolType::Engineering, schoolTypeScorer(engineeringColleges));
  pair<SchoolType, double> temp2 (SchoolType::Party, schoolTypeScorer(partyColleges));
  pair<SchoolType, double> temp3 (SchoolType::Liberal_Arts, schoolTypeScorer(liberalArtsColleges));
  pair<SchoolType, double> temp4 (SchoolType::Ivy_League, schoolTypeScorer(ivyLeagueColleges));
  pair<SchoolType, double> temp5 (SchoolType::State, schoolTypeScorer(stateColleges));
  
  ranking.push_back(temp1);
  ranking.push_back(temp2);
  ranking.push_back(temp3);
  ranking.push_back(temp4);
  ranking.push_back(temp5);

  sort(ranking.begin(), ranking.end(), [](const pair<SchoolType, double>& a, const pair<SchoolType, double>& b) -> bool{
    return a.second > b.second;
  });
  
  if(output){
    cout << endl;
    cout << "Ranking Colleges by School Type:" << endl;
    cout << "Rank" << "   ";
    cout << left << setw(18) << "School Type" << "   ";
    cout << "Total Score of School Type"  << endl;
    for(int i =0; i < ranking.size();i++){
      cout  << right << setw(2) << i+1;
      cout  << left << setw(5) << ".";
      cout << left << setw(18) << toStrSchoolType(ranking[i].first);
      cout << "             ";
      cout  << fixed << setprecision(2);
      cout << ranking[i].second << endl;
    }
  }
  return ranking;
}

double Colleges::regionScorer(vector<College> colleges){
  //Top 10 colleges in a region only
  double totalScore;

  double midCareerMedianScore = 0;
  double differenceStartMid = 0;
  double midCareer25thScore = 0;
  double midCareer75thScore = 0;

  for(int i = 0; i < 10; i++){
    midCareerMedianScore += colleges[i].getMidCareerMedianSalary();
    differenceStartMid += colleges[i].getMidCareerMedianSalary() - colleges[i].getStartingMedianSalary();
    midCareer25thScore += colleges[i].getMidCareer25th();
    midCareer75thScore += colleges[i]. getMidCareer75th();
  }

  totalScore = (midCareerMedianScore + 0.5*differenceStartMid + midCareer25thScore + midCareer75thScore)/1000;
  return totalScore;
}
    
double Colleges::schoolTypeScorer(vector<College> colleges){
  //Top 8 colleges in a region only
  double totalScore;

  double midCareerMedianScore = 0;
  double differenceStartMid = 0;
  double midCareer25thScore = 0;
  double midCareer75thScore = 0;

  for(int i = 0; i < 8; i++){
    midCareerMedianScore += colleges[i].getMidCareerMedianSalary();
    differenceStartMid += colleges[i].getMidCareerMedianSalary() - colleges[i].getStartingMedianSalary();
    midCareer25thScore += colleges[i].getMidCareer25th();
    midCareer75thScore += colleges[i]. getMidCareer75th();
  }

  totalScore = (midCareerMedianScore + 0.5*differenceStartMid + midCareer25thScore + midCareer75thScore)/800;
  return totalScore;
}
