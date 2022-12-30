/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Car.h"
using namespace std;

namespace sdds {
    void Car::resetInfo() {
	  m_type = nullptr;
	  m_brand = nullptr;
	  m_model = nullptr;
	  m_year = 0;
	  m_code = 0;
	  m_price = 0; 
    }
    Car::Car() {
	  resetInfo();
    }
    Car::Car(const char* type,const char* brand,const char* model,int year,int code,double price) {
	  if (type && brand  && model && year >= 1990
		&& code >= 100 && price > 0) {
		m_type = new char[strlen(type) + 1];
		strcpy(m_type, type);
		m_brand = new char[strlen(brand) + 1];
		strcpy(m_brand, brand);
		m_model = new char[strlen(model) + 1];
		strcpy(m_model, model);
		m_year = year;
		m_code = code;
		m_price = price;
	  }
	  else resetInfo();

    }
    void Car::deallocate() {
	  delete[] m_type;
	  delete[] m_brand;
	  delete[] m_model;
    }
    Car::~Car() {
	  deallocate();
    }
    Car& Car::setInfo(const char* type,
	  const char* brand,
	  const char* model,
	  int year,
	  int code,
	  double price) {
	  deallocate();
	  if (type && brand && model && year >= 1990
		&& code >= 100 && price > 0) {
		m_type = new char[strlen(type) + 1];
		strcpy(m_type, type);
		m_brand = new char[strlen(brand) + 1];
		strcpy(m_brand, brand);
		m_model = new char[strlen(model) + 1];
		strcpy(m_model, model);
		m_year = year;
		m_code = code;
		m_price = price;
	  }
	  else resetInfo();

	  return *this;

    }
    void Car::printInfo() const {
	  cout << "| " << setw(11) << left << m_type << "| ";
	  cout << setw(17) << left << m_brand << "| ";
	  cout << setw(17) << left << m_model << "|";
	  cout << setw(5) << right << m_year << " |";
	  cout << setw(5) << right << m_code << " |";
	  cout << setw(10) << right << fixed << setprecision(2) << m_price << " |" << endl;

    }
    bool Car::isValid() const {
	  bool valid = false;
	  if (m_type && m_brand && m_model && m_year >= 1990
		&& m_code >= 100 && m_price > 0)
		valid = true;
	  return valid;
    }
    bool Car::isSimilarTo(const Car& car) const {
	  return m_type && strcmp(m_type, car.m_type) == 0 
		&& m_brand && strcmp(m_brand, car.m_brand) == 0
		&& m_model && strcmp(m_model, car.m_model) == 0
		&& (m_year == car.m_year);
    }
    bool has_similar(const Car car[], const int num_cars) {
	  bool match = false;
	  for (int i = 0; i < num_cars; i++) {
		for (int j = i + 1; j < num_cars; j++) {
		    if (car[i].isSimilarTo(car[j])) {
			  // match is found
			  match = true;
		    }
		}
	  }
	  return match;
    }
    bool has_invalid(const Car car[], const int num_cars) {
	  int i;
	  bool hasInvalid = false;
	  for (i = 0; i < num_cars; i++) {
		if (car[i].isValid()) {
		    hasInvalid = true;
		}
	  }
	  return hasInvalid;
    }
    void print(const Car car[], const int num_cars) {
	  int i;
	  for (i = 0; i < num_cars; i++) {
		if (!car[i].isValid());//print nothing
		else car[i].printInfo();
	  }
	  return;
    }
}