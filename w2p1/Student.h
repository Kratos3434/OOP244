/*
Name: Keith Carlos
Section: NNN
Email: kwcarlos@myseneca.ca
Student ID: 127638211
*/
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_


namespace sdds {
    struct Student {
	  char* m_name;
	  int m_studentNumber;
	  char m_grade;
    };
    void sort();
    bool load(Student& student);
    bool load(const char* file);
    void display(const Student& student);
    void display();
    void deallocateMemory();
}

#endif