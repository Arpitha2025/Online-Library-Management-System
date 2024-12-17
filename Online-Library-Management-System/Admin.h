#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include "Transaction.h"
using namespace std;

class Admin : public User{

private:
string name;
int adminID, yrsWork, salary, adminSize;

public:
Admin();
Admin(string , int , int , int );
void printReward(); //notifies reward to admin based on years of work
int search(int);
void addWorker(Admin*); //adds worker
void removeWorker (int ); //removes worker
void rewardWorker (string ); //reward a worker
string getName(); // returns name of admin
int getadminID(); //return id of admin
int getYrsWork (); //return years of work at library
int getSalary(); //returns salary of admin
int getAdminSize(); //returns size of admin array
void setName(string); //sets name of admin to string input
void setadminID(int); // sets id of admin to string input
void setYrsWork (int); //sets years of work at library
void setSalary(int); //sets salary to int input
void setAdminSize(int);
};
#endif