/*
Name: Keith Carlos
Section: NHH
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include "Numbers.h"  // intentional
#include <iomanip>
using namespace std;
namespace sdds {


    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;
    }

    Numbers::Numbers(const char* filename) {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
        if (m_numCount == 0 || !load()) {
            delete[] m_numbers;
            delete[] m_filename;
            setEmpty();
            m_isOriginal = false;
        }
        else {
            sort();
        }
    }
    Numbers::Numbers(const Numbers& num) {
        setEmpty();
        m_isOriginal = false;
        (*this) = num;
    }
    Numbers& Numbers::operator=(const Numbers& num) {
        delete[] m_numbers;
        m_numbers = new double[num.m_numCount];
        m_numCount = num.m_numCount;
        for (int i = 0; i < m_numCount; i++)
            m_numbers[i] = num.m_numbers[i];

        return *this;
    }
    Numbers& Numbers::operator+=(double val) {
        if (!isEmpty()) {
            double* temp = new double[m_numCount + 1];
            for (int i = 0; i < m_numCount; i++)
                temp[i] = m_numbers[i];
            delete[] m_numbers;
            m_numbers = temp;
            m_numbers[m_numCount] = val;
            m_numCount++;
            sort();
        }
        return *this;
    }
    std::ostream& Numbers::display(std::ostream& ostr) const {
        if (isEmpty()) ostr << "Empty list";
        else {
            ostr << "=========================\n";
            if (m_isOriginal) ostr << m_filename<<"\n";
            else ostr << "*** COPY ***\n";
            for (int i = 0; i < m_numCount; i++) {
                ostr << m_numbers[i];
                if (i != m_numCount - 1) ostr << ", ";
            }
            ostr << "\n-------------------------\n";
            ostr << "Total of " << m_numCount << " number(s)\n";
            ostr << "Largest number:  " << max() << "\n";
            ostr << "Smallest number: " << min() << "\n";
            ostr << "Average :        " << average() << "\n";
            ostr << "=========================";
        }
        return ostr;
    }
    int Numbers::numberCount() const {
        char c;
        int numLine = 0;
        std::ifstream open(m_filename);
        while (open) {
            while (open.get(c)) {
                if (c == '\n')
                    numLine++;
            }
        }
        return numLine;
    }
    bool Numbers::load() {
        int i = -1;
        if (m_numCount > 0) {
            m_numbers = new double[m_numCount];
            ifstream nums(m_filename);
            i = 0;
            while (nums) {
                for (i = 0; i < m_numCount; i++)
                    nums >> m_numbers[i];
                if (nums)i++;
            }
        }
        return i == m_numCount;
    }
    void Numbers::save() {
        if (m_isOriginal && !isEmpty()) {
            std::ofstream ofs(m_filename);
            for (int i = 0; i < m_numCount; i++) {
                ofs << m_numbers[i]<<"\n";

            }
        }
    }
    Numbers::~Numbers() {
        save();
        delete[] m_numbers;
        delete[] m_filename;
    }

    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }

    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }
    void Numbers::setFilename(const char* filename) {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }
    void Numbers::sort() {
        int i, j;
        double temp;
        for (i = m_numCount - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (m_numbers[j] > m_numbers[j + 1]) {
                    temp = m_numbers[j];
                    m_numbers[j] = m_numbers[j + 1];
                    m_numbers[j + 1] = temp;
                }
            }
        }
    }

    double Numbers::average() const {
        double aver = 0.0;
        if (!isEmpty()) {
            for (int i = 0; i < m_numCount; i++)
                aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
    }
    double Numbers::min() const {
        double minVal = 0.0;
        if (!isEmpty()) {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (minVal > m_numbers[i]) minVal = m_numbers[i];
        }
        return minVal;
    }
    double Numbers::max() const {
        double maxVal = 0.0;
        if (!isEmpty()) {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
        }
        return maxVal;
    }

    std::ostream& operator<<(std::ostream& ostr, Numbers& num) {
        return num.display(ostr);
    }
    std::istream& operator>>(std::istream& istr, Numbers& N) {
        double val;
        istr >> val;
        N += val;
        return istr;
    }

}