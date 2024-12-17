#include "Book.h"
#include <fstream>
#include <iostream>
#include <string>

//default constructor 
Book::Book(){
  title = "";
  genre = "";
  author = "";
  size = 0;
  IDnum = 0;
  availability = "";
}
//overloaded constructor
Book::Book(string btitle, string bauthor, string bgenre, int bsize, int bIDnum, int bavailability){
  title = btitle;
  author = bauthor;
  genre = bgenre;
  size = bsize; 
  IDnum = bIDnum;
  availability = bavailability;
}
//return title of book
string Book::getTitle(){
   return title; 
}
//return book genre
string Book::getGenre(){
  return genre;
}
//return book author
string Book::getAuthor(){
  return author;
} 
//return book availability
string Book::getAvailability(){
  return availability;
}
//return book size
int Book::getSize(){
  return size;
}
//return book id
int Book::getIDnum(){
  return IDnum;
}
//sets title of book
void Book::setTitle(string title){
  this->title = title;
}
//sets genre of book
void Book::setGenre(string genre){
  this->genre = genre;
}
//sets author of book
void Book::setAuthor(string author){
  this->author = author;
} 
//sets availability of book
void Book::setAvailability(string avail){
  this->availability = avail;
}
//sets size of book
void Book::setSize(int size){
  this->size = size;
}
//sets id of book
void Book::setIDnum(int id){
  this->IDnum = id;
}
