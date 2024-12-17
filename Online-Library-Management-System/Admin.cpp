#include "Admin.h"
#include <fstream>
#include <iostream>
#include <string>

//default constructor 
Admin::Admin(){
  name = "";
  adminID = 0, yrsWork = 0, salary = 0;
  adminSize = 0;
}
//overloaded constructor
Admin::Admin(string n, int id, int yrs, int sal){
  name = n;
  adminID = id, yrsWork = yrs, salary = sal;
}

//getters
string Admin::getName(){// returns name of admin
  return name;
} 
int Admin::getadminID(){//return id of admin
  return adminID;
} 
int Admin::getYrsWork (){ //return years of work at library
  return yrsWork;
}
int Admin::getSalary(){ //returns salary of admin
  return salary;
}
int Admin::getAdminSize(){ //returns salary of admin
  return adminSize;
}
//setters
void Admin::setName(string name){ //sets name of admin to string input
  this->name = name;
}
void Admin::setadminID(int adminID){ // sets id of admin to string input
  this->adminID = adminID;
}
void Admin::setYrsWork (int yrsWork){ //sets years of work at library
  this->yrsWork = yrsWork;
}

void Admin::setSalary(int salary){ //sets salary to int input
  this->salary = salary; 
}
void Admin::setAdminSize(int size){ //sets name of admin to string input
  this->adminSize = size;
}
//REWARDS
void Admin::printReward(){
  if (yrsWork >= 1)
    cout << "WE APPRECIATE YOU!" << endl;
  if (yrsWork < 2){ 
    cout << "You are a level 1 employee! You get a $25 Gift Card!" << endl;
  }
  else if (yrsWork < 4){
    cout << "You are a level 2 employee! You can now get an autograph from your favorite author." << endl;
  }
  else if (yrsWork < 7){
    cout << "You are a level 3 employee! You get a $100 gift card and a free two-day vacation to Earth." << endl;
  }
  else if (yrsWork < 10){
    cout << "You are a level 4 employee! You get a choice of a free tour of Mars or two days of vacation to Earth." << endl;
  }
  else {
    cout << "You are our heighest level 5 employee! You get to join the Martians on our Moon mission!" << endl;
  }
} 
//search is in library
void Admin::addWorker(Admin* addedWorker){ //worker class?
  //lib->addAdmin(addedWorker);
} //adds worker
void Admin::removeWorker (int i){} //removes worker

void Admin::rewardWorker (string n){

} //reward a worker