#ifndef TRANSACTION_H
#define TRANSACTION_H  
#include <iostream>
#include <string>
#include "User.h"
using namespace std;

class Transaction{

private:
  string transactID, dateTime, transactBooks, typeTransact;
  int userID;

public:
  //virtual void printRewards() const;
  void printRewards();
//getters
  string getTransactID(); //returns transaction ID of book
  string getDateTime(); //returns date & time of book transaction
  string getTransactBooks(); //returns transacted book
  int getUserID(); //returns id of user
//setters                
  void setTransactID(string); //set transaction ID of book to str input
  void setDateTime(string); //set date & time of book to str input
  void setTransactBooks(string); //returns transacted book
  void setUserID(int); //sets id of user to User input

};
#endif