#ifndef SUPPORTING_H
#define SUPPORTING_H

#include<iostream>
#include<fstream>
#include "course.h"
#include "student.h"
#include "date.h"

using namespace std;
// function to show main menue and prompt the user to select input option
int main_menu();
//!

// cleans leftovers in the input buffer after any input operation
void buffer_cleaner();
//!

// function to open file using file stream and extract course information in the file. the extraction is based on the file format provided in the supporting materials document
int load_coursefile(string filename, vector<Course> & clist);
//!

// function to open file using file stream and extract student information in the file.
int load_studentfile(string filename, vector<Student> & slist);
//!

// search function that finds a student object in the vector of students using the student id and return a pointer to the student object
Student* find_student(string id,vector<Student>& student_list);
//!

// search function that finds a course object in the vector of students using the course id and returns a pointer to the course object
Course* find_course(string cid,vector<Course>& course_list);
//!

// function to open enrollement file using a file stream and extracts student enrollment into courses information. must update the course objects to include the student in the student list, and update the student object to have the course in enrolled courses list
int enrollment_file(string filename, vector<Course> & clist, vector<Student>& slist);
//!

// function that take course id and displays the string return of the course object
void show_course_details(string c,vector<Course>& clist);
//!

// function that takes the student id and displays the string return of the student object info
void show_student_details(string s,vector<Student>& slist);
//!

// creates a new course by prompting the user to input required course information (not including enrolled students)
Course create_course();
//!

// creates a new student object by prompting user to input required student information for the constructor
Student create_student();
//!

// enrolls the student with sid into course with cid.
void enroll_to_course(string sid, string cid,vector<Student>& slist,vector<Course>& clist);
//!


// functions to add for options 9 through 11
//9. function that takes a student id and course id, looks up the student in the course student list and if  found removes the student from the course. parameters needed might be more than just student id adn course id
string withdraw_from_course(string sid, string cid,vector<Student>& slist,vector<Course>& clist);

//10. update student grade that takes a student id, course id, and grade to update the student grade in a given course. note that parameters needed might be more than the three specified
string update_grade(string sid, string cid, double grade, vector<Student>& slist,vector<Course>& clist);


//11. save changes will modify courses.txt, students.txt, and enroll.txt to reflect any changes that were made during the program run (i.e. new students added, course added, and new enrolments .... etc)
//bool save(vector<Student>& slist,vector<Course>& clist);




// note: you can define supporting functions similar to find_student and find_course which do not correspond to an option in the main menu directly







//Utils---------------------------------------------------------------------------
void enter_wait();
// PROMISES: sets 'Press enter to continue' on screen

void enter_clear();
// PROMISES: sets 'Press enter to continue' on screen and clear

void clear();
// PROMISES does a system("clear");

string get_input();
// PROMISES: Prompts user for an input and returns that input

int get_int();
// PROMISES: Prompts user for an input and returns that input as int
double get_double();
// PROMISES: Prompts user for an input and returns that input as double

void nl();
// PROMISES: does cout << endl;

string prompt_get(string prompt);
// PROMISES: Prompts user for an input but specifies to input 'prompt'
//REQUIRES: a string to prompt

double prompt_get_double(string prompt);
// PROMISES: Prompts user for an input but specifies to input 'prompt'
//	REQUIRES: a string to prompt


//--------------------------------------------------------------------------------











#endif