/*
Name: Keith Carlos
Section: NNN
Email: kwcarlos@myseneca.ca
Student ID: 127638211
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h"
#include "File.h"

using namespace std;
namespace sdds {
    int noOfStudents;
    Student* students;
    void sort() {
	  int i, j;
	  Student temp;
	  for (i = noOfStudents - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
		    if (students[j].m_grade > students[j + 1].m_grade) {
			  temp = students[j];
			  students[j] = students[j + 1];
			  students[j + 1] = temp;
		    }
		}
	  }
	  
    }
    bool load(Student& student) {
	  char name[128];
	  bool success = false;
	  if (read(name)) {
		student.m_name = new char[strlen(name) + 1];
		strcpy(student.m_name, name);
		success = read(student.m_studentNumber) &&
		 read(student.m_grade);

	  }
	  return success;
    }
    bool load(const char *file) {
	  bool success = false;
	  int count = 0;
	  if (openFile(file)) {
		noOfStudents = noOfRecords();
		students = new Student[noOfStudents];
		//loop and read each line using the other load function
		for (int i = 0; i < noOfStudents; i++) {
		    load(students[i]);
		    count++;
		}
		if (count != noOfStudents) {
		    printf("Error: incorrect number of records read; the data is possibly corrupted.\n");
		    success = false;
		}
		else success = true;
		//make sure to update fileread correctly
		//otherwise print the required error message
	
	  }
	  closeFile();
	  return success;
    }
    void display(const Student& student) {
	  cout<<student.m_name<<", "<<student.m_studentNumber<<": "<<student.m_grade<<endl;
    }
    void display() {
	  int i;
	  sort();
	  for (i = 0; i < noOfStudents; i++) {
		printf("%d: ", i+1);
		display(students[i]);
	  }
    }
    void deallocateMemory() {
	  //loop for all students
	  //delete[] students[i].m_name
	  for (int i = 0; i < noOfStudents; i++) {
		delete[] students[i].m_name;
	  }
	  delete[] students;
    }
}