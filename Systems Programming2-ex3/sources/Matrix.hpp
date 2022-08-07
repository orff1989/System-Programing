#pragma once

#include <iostream>
#include <system_error>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

namespace zich {

    class Matrix {
    private:
        size_t row;
        size_t col;
        vector<double> mat;

    public:
        Matrix(vector<double> vec=vector<double>{0}, int rows=1, int cols=1){
            if (rows<=0 || cols<=0 || vec.size()!=size_t(rows*cols)) throw "the parameters are not valid";
            mat=vec;
            row=size_t(rows);
            col=size_t(cols);
        }

        size_t getRow() const {return row;}

        size_t getCol() const {return col;}

        vector<double> getMat() const {return std::vector<double> (mat);}

        friend vector<double> insertToVec(string& s);

        //operators declaration
        friend ostream& operator<< (ostream& os, const Matrix& m);

        friend std::istream& operator>> (std::istream& input , Matrix& m);

        friend Matrix operator- (const Matrix& c1, const Matrix& c2);

        friend Matrix operator+ (const Matrix& c1, const Matrix& c2);

        friend Matrix operator* (const Matrix& c1, const Matrix& c2);

        friend Matrix operator* (double c1, const Matrix& c2);

        friend Matrix operator* (const Matrix& c1, double c2);

        friend bool operator==(const Matrix& c1, const Matrix& c2);

        friend bool operator<(const Matrix& c1, const Matrix& c2);

        friend bool operator<=(const Matrix& c1, const Matrix& c2);

        friend bool operator>(const Matrix& c1, const Matrix& c2);

        friend bool operator>=(const Matrix& c1, const Matrix& c2);

        bool operator==(const Matrix& c1);

        bool operator<(const Matrix& c1);

        bool operator<=(const Matrix& c1);

        bool operator>(const Matrix& c1);

        bool operator>=(const Matrix& c1);

        bool operator!=(const Matrix& c1);

        void operator+=(const Matrix& other);

        void operator-=(const Matrix& other);

        void operator*=(const Matrix& other);

        void operator*=(const double num);

        Matrix&  operator=(const Matrix& m);

        Matrix operator-();

        Matrix operator+();

        Matrix& operator++();

        Matrix operator++(int d);

        Matrix& operator--();

        Matrix operator--(int d);


    };
}