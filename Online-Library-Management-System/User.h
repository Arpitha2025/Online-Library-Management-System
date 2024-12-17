#ifndef USER_H
#define USER_H  
#include "Transaction.h"
#include <iostream>
#include <string>
using namespace std;

class User{

private:
  string name, status, transactions;
  int balance, IDnum, loyalty;
// list of string transactions

public:
  User();
  User(int);
  //int search();// dont need this 
  void printRewards();
  void printTransactionReport();
//getters
  string getName(); //returns name of user
  string getStatus(); //returns status of user account (fines & overdue)
  string getTransactions(); //returns transaction history of user
  int getBalance(); //returns balance of user
  int getIDnum(); //returns id of user
  int getLoyalty(); //returns loyalty tier of user (years of being member)
//setters                
  void setName(string); //sets name of user to string input
  void setStatus(string); //sets status of user to string input
  void setTransactions(string); //sets transactions of user to string input
  void setBalance(int); //sets balance of user to int input
  void setIDnum(int); //sets id of user to int input
  void setLoyalty(int); //sets loyalty tier of user to string input

};
#endif