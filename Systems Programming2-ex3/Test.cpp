#include "doctest.h"
#include "Matrix.hpp"
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;
using namespace zich;

std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
std::ostringstream out;

TEST_CASE("Good input") {
    std::vector<double> arr1 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    std::vector<double> arr2 = {3, 8, 0, 0, 2, 7, 9, 0, 1};
    std::vector<double> arr3 = {11, 44, 23, 4, 22, 78, 12, 23, 70};

    Matrix iden{identity, 3, 3};

    Matrix m1(arr1, 3, 3);
    Matrix m2{arr2,3,3};
    Matrix m3{arr3,3,3};
    std::vector<Matrix> marr{m1,m2,m3};


    out << m1;
    CHECK(out.str()=="[2 0 0]\n"
                     "[0 2 0]\n"
                     "[0 0 2]\n");
    out.str("");

    out<<m2;
    CHECK(out.str()=="[3 8 0]\n"
                     "[0 2 7]\n"
                     "[9 0 1]\n");
    out.str("");

    out<<m3;
    CHECK(out.str()=="[11 44 23]\n"
                     "[4 22 78]\n"
                     "[12 23 70]\n");
    out.str("");

    out<<m1+m2;
    CHECK(out.str()=="[5 8 0]\n"
                     "[0 4 7]\n"
                     "[9 0 3]\n");
    out.str("");

    out<<1*(m1+m2);
    CHECK(out.str()=="[5 8 0]\n"
                     "[0 4 7]\n"
                     "[9 0 3]\n");
    out.str("");

    out<<2*(m1+m2);
    CHECK(out.str()=="[10 16 0]\n"
                     "[0 8 14]\n"
                     "[18 0 6]\n");
    out.str("");

    out<<m1+m3;
    CHECK(out.str()=="[13 44 23]\n"
                     "[4 24 78]\n"
                     "[12 23 72]\n");
    out.str("");

    out<<m1*m2;
    CHECK(out.str()=="[6 16 0]\n"
                     "[0 4 14]\n"
                     "[18 0 2]\n");
    out.str("");

    out<<2*m2;
    CHECK(out.str()=="[6 16 0]\n"
                     "[0 4 14]\n"
                     "[18 0 2]\n");
    out.str("");

    out<<1*m3;
    CHECK(out.str()=="[11 44 23]\n"
                     "[4 22 78]\n"
                     "[12 23 70]\n");
    out.str("");


    for (size_t i = 0; i < marr.size(); i++){
      Matrix m=marr[i]*iden;
      CHECK(m==marr[i]);
    }

    out<<m3-m1;
    CHECK(out.str()=="[9 44 23]\n"
                     "[4 20 78]\n"
                     "[12 23 68]\n");
    out.str("");

    m2+=m1;
    out<<m2;
    CHECK(out.str()=="[5 8 0]\n"
                     "[0 4 7]\n"
                     "[9 0 3]\n");
    out.str("");

    m3*=3;
    out<<m3;
    CHECK(out.str()=="[33 132 69]\n"
                     "[12 66 234]\n"
                     "[36 69 210]\n");
    out.str("");

    out<<++m2;
    CHECK(out.str()=="[6 9 1]\n"
                     "[1 5 8]\n"
                     "[10 1 4]\n");
    out.str("");

    out<<-m2;
    CHECK(out.str()=="[-6 -9 -1]\n"
                     "[-1 -5 -8]\n"
                     "[-10 -1 -4]\n");
    out.str("");
}

TEST_CASE("Bad input"){
    std::vector<double> arr1 = {4, 2, 4, 5, 0, 5, 8, 7, 1};
    std::vector<double> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9,10};
    std::vector<double> arr3 = {2, 9, 1, 11, 4, 55};

    Matrix m1{arr1, 3, 3};
    Matrix m2{arr2,2,5};
    Matrix m3{arr3,3,2};


    CHECK_THROWS(m1+m2);

    CHECK_THROWS(m1*m2);

    CHECK_THROWS(m2-m3);

    CHECK_THROWS(m2*m3);

    CHECK_THROWS(m3*m1);

}