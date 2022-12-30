/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
    class Numbers {
        double* m_numbers;
        char* m_filename;
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty()const;
        void setEmpty();
        void setFilename(const char* filename);
        void sort();
    public:
        Numbers();
        Numbers(const char* filename);
        Numbers(const Numbers& num);
        Numbers& operator=(const Numbers& num);
        Numbers& operator+=(double val);
        std::ostream& display(std::ostream& ostr) const;
        double average()const;
        double max()const;
        double min()const;
        ~Numbers();
        bool load();
        int numberCount() const;
        void save();
    };
    std::ostream& operator<<(std::ostream& ostr, Numbers& num);
    std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_