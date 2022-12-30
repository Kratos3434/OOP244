/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_NAME_H
#define SDDS_NAME_H
#include <iostream>

namespace sdds {
    class Name {
        char* m_value;
    public:
        Name();
        Name(const char* name);
        // Rule of three goes here:
        Name(const Name& name);
        Name& operator=(const Name& name);
        ~Name();

        operator const char* ()const;
        virtual operator bool()const;
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;
        virtual std::istream& read(std::istream& istr = std::cin);
    };
    std::ostream& operator<<(std::ostream& ostr, const Name& name);
    std::istream& operator>>(std::istream& istr, Name& name);
}
#endif // !SDDS_NAME_H
