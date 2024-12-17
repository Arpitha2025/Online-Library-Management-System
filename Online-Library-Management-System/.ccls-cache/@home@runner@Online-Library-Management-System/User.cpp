#include "User.h"
#include <fstream>
#include <iostream>
#include <string>

User::User(){
  name = "";
  status = "";
  transactions = "";;
  balance = 0;
  IDnum = 0;
  loyalty = 0;
}

//getters
string User::getName(){ //returns name of user
  return name;
}
string User::getStatus(){ //returns status of user account (fines & overdue)
  return status;
}
string User::getTransactions(){ //returns transaction history of user
  return transactions;
}
int User::getBalance(){ //returns balance of user
  return balance;
}
int User::getIDnum(){ //returns id of user
  return IDnum;
}
int User::getLoyalty(){ //returns loyalty tier of user (years of being member)
  return loyalty;
}
//setters                
void User::setName(string name){ //sets name of user to string input
  this->name = name;
}
void User::setStatus(string status){ //sets status of user to string input
  this->status = status;
}
void User::setTransactions(string transactions){ //sets transactions of user to string input
  this->transactions = transactions;
}
void User::setBalance(int balance){ //sets balance of user to int input
  this->balance = balance;
}
void User::setIDnum(int IDnum){ //sets id of user to int input
  this->IDnum = IDnum;
}
void User::setLoyalty(int loyalty){//sets loyalty tier of user to string input
  this->loyalty = loyalty;
}
void User::printRewards(){ //notifies reward to user based on years of membership
  if (loyalty >= 1)
    cout << "CONGRATULATIONS!" << endl;
  if (loyalty == 1){ 
    cout << "You are a level 1 member! You can now check out more than 2 books." << endl;
  }
  else if (loyalty == 2){
    cout << "You are a level 2 member! You can now check out more than 3 books and get a custom bookmark." << endl;
  }
  else if (loyalty == 3){
    cout << "You are a level 3 member! You can now extend your due date for upto a week and choose one of our Red Planet Merch." << endl;
  }
  else if (loyalty == 4){
    cout << "You are a level 4 member! You get a free autograph from your favorite author." << endl;
  }
  else if (loyalty == 5){
    cout << "You are a level 5 member! You can now write a personal letter to any author of choice and we will deliver!" << endl;
  }
}
void User::printTransactionReport(){
  cout << "Your transactions:" << endl;
  cout << transactions << endl;
}