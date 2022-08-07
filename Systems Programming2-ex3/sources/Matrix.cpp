#include "Matrix.hpp"
size_t const nine =9;

using namespace std;

namespace zich {


    ostream &operator<<(ostream &os, const Matrix &m) {
        string ans = "[";
        for (size_t i = 0; i < m.getMat().size(); i++) {
            //if we arrived to the end of the row:
            if (i % m.getCol() == 0 && i != 0) {
                ans += "]\n[";
            }
            //checking if the number is integer number
            if (floor(m.getMat()[i]) == m.getMat()[i]) {
                ans += to_string(int(m.getMat()[i]));
            } else {
                ans += to_string(m.getMat()[i]);
            }
            //adding spaces between the numbers
            if ((i + 1) % m.getCol() != 0) {
                ans += " ";
            }
        }
        ans += "]";
        std::operator<<(os, ans);
        return os;
    }

    vector<double> insertToVec(string& s){
        vector<double> v;
        string num;
        for (size_t i = 0; i < s.size(); i++) {
            if ((s.at(i)-'0'>=0 && s.at(i)-'0'<=nine) || s.at(i)=='.'){
                num.append(1,s.at(i));
            }
            else{
                if(!num.empty()) {
                    v.push_back(stof(num));
                }
                num="";
            }
        }
        return v;
    }

    size_t numberOfRows(string& s){
        size_t sum=0;
        for (size_t i = 0; i < s.size(); i++) {
            if (s.at(i)=='[') {sum++;}
        }
        return sum;
    }

    bool isNotValid(string& s){
        return s.find(", ")==std::string::npos || s.at(0)==','|| s.find(",[")!=std::string::npos || s.find("] [")!=std::string::npos || s.find("[ ")!=std::string::npos;
    }

    std::istream& operator>> (std::istream& input , Matrix& m){
        //converting the data from input to string
        std::string s;
        vector<double> v;
        size_t rows=1;

        std::streampos p = input.tellg();

        input.seekg(0, std::ios_base::end);
        std::streamoff sz = input.tellg() - p;
        input.seekg(p);

        s.resize(size_t (sz));
        input.read(&s[0], sz);

        if (isNotValid(s)){ throw "the string is not valid";};
        v=insertToVec(s);
        rows= numberOfRows(s);
        if(rows!=0){
        m=Matrix(v,rows,int(v.size()/rows));}

        return input;
    }

    Matrix operator-(const Matrix &c1, const Matrix &c2) {
        if (c1.getCol()!=c2.getCol() || c1.getRow()!=c2.getRow()) {throw "the size of matrices are not the same";}

        vector<double> v;
        for (size_t i = 0; i < c1.getMat().size(); i++) {
            v.push_back(c1.getMat()[i]-c2.getMat()[i]);
        }
        return Matrix(v,c1.getRow(),c1.getCol());
    }

    Matrix operator+(const Matrix &c1, const Matrix &c2) {
        if (c1.getCol()!=c2.getCol() || c1.getRow()!=c2.getRow()) {throw "the size of matrices are not the same";}

        vector<double> v;
        for (size_t i = 0; i < c1.getMat().size(); i++) {
            v.push_back(c1.getMat()[i]+c2.getMat()[i]);
        }
        return Matrix(v,c1.getRow(),c1.getCol());
    }

    Matrix operator*(const Matrix &c1, const Matrix &c2) {
        if (c1.getCol()!=c2.getRow()) {throw "the size of matrices are not valid";}
        vector<double> v;
        double n=0;
        for (size_t i = 0; i < c1.getRow(); i++) {
            for (size_t j = 0; j < c2.getCol(); j++) {
                for (size_t k = 0; k < c2.getRow(); k++) {
                    n+=c1.mat[i*c1.getCol()+k]*c2.mat[k*c2.getCol()+j];
                }
                v.push_back(n);
                n=0;
            }
        }

        return Matrix(v,c1.getRow(),c2.getCol());
    }

    Matrix operator*(double c1, const Matrix &c2) {
        vector<double> v;
        for (size_t i = 0; i < c2.getMat().size(); i++) {
            v.push_back(c2.getMat()[i]*c1);
        }
        return Matrix(v,c2.getRow(),c2.getCol());
    }

    Matrix operator*(const Matrix &c1, double c2) {
        vector<double> v;
        for (size_t i = 0; i < c1.getMat().size(); i++) {
            v.push_back(c1.getMat()[i]*c2);
        }
        return Matrix(v,c1.getRow(),c1.getCol());
    }

    bool operator==(const Matrix& c1, const Matrix& c2){
        if (c1.getCol()!=c2.getCol() || c1.getRow()!=c2.getRow()) {throw "the size of matrices is not the same";}

        for (size_t i = 0; i < c1.getMat().size(); i++) {
            if(c1.getMat()[i]!=c2.mat[i]) {return false;}
        }
        return true;
    }

    bool operator<(const Matrix& c1, const Matrix& c2){
        double sum=0;
        double sumC1=0;
        if (c1.getCol()!=c2.getCol() || c1.getRow()!=c2.getRow()) {throw "the size of matrices is not the same";}

        for (size_t i = 0; i < c1.getMat().size(); i++) {
            sumC1+=c1.mat[i];
        }
        for (size_t i = 0; i < c2.mat.size(); i++) {
            sum+=c2.mat[i];
        }
        return sumC1<sum;
    }

    bool operator<=(const Matrix &c1, const Matrix &c2) {
        double sum=0;
        double sumC1=0;
        if (c1.getCol()!=c2.getCol() || c1.getRow()!=c2.getRow()) {throw "the size of matrices is not the same";}

        for (size_t i = 0; i < c1.getMat().size(); i++) {
            sumC1+=c1.mat[i];
        }
        for (size_t i = 0; i < c2.mat.size(); i++) {
            sum+=c2.mat[i];
        }
        return sumC1<=sum;
    }

    bool operator>(const Matrix &c1, const Matrix &c2) {
        double sum=0;
        double sumC1=0;
        if (c1.getCol()!=c2.getCol() || c1.getRow()!=c2.getRow()) {throw "the size of matrices is not the same";}

        for (size_t i = 0; i < c1.getMat().size(); i++) {
            sumC1+=c1.mat[i];
        }
        for (size_t i = 0; i < c2.mat.size(); i++) {
            sum+=c2.mat[i];
        }
        return sumC1>sum;
    }

    bool operator>=(const Matrix &c1, const Matrix &c2) {
        double sum=0;
        double sumC1=0;
        if (c1.getCol()!=c2.getCol() || c1.getRow()!=c2.getRow()) {throw "the size of matrices is not the same";}

        for (size_t i = 0; i < c1.getMat().size(); i++) {
            sumC1+=c1.mat[i];
        }
        for (size_t i = 0; i < c2.mat.size(); i++) {
            sum+=c2.mat[i];
        }
        return sumC1>=sum;
    }

    bool Matrix::operator==(const Matrix &c1){
        if (c1.getCol()!=getCol() || c1.getRow()!=getRow()) {throw "the size of matrices is not the same";}

        for (size_t i = 0; i < c1.getMat().size(); i++) {
            if(c1.getMat()[i]!=mat[i]) {return false;}
        }
        return true;
    }

    bool Matrix::operator<(const Matrix &c1) {
        double sum=0;
        double sumC1=0;
        if (c1.getCol()!=getCol() || c1.getRow()!=getRow()) {throw "the size of matrices is not the same";}

        for (size_t i = 0; i < c1.getMat().size(); i++) {
            sumC1+=c1.mat[i];
        }
        for (size_t i = 0; i < mat.size(); i++) {
            sum+=mat[i];
        }
        return sum<sumC1;
    }

    bool Matrix::operator<=(const Matrix &c1) {
        double sum=0;
        double sumC1=0;
        if (c1.getCol()!=getCol() || c1.getRow()!=getRow()) {throw "the size of matrices is not the same";}

        for (size_t i = 0; i < c1.getMat().size(); i++) {
            sumC1+=c1.mat[i];
        }
        for (size_t i = 0; i < mat.size(); i++) {
            sum+=mat[i];
        }
        return sum<=sumC1;
    }

    bool Matrix::operator>(const Matrix& c1){
        double sum=0;
        double sumC1=0;
        if (c1.getCol()!=getCol() || c1.getRow()!=getRow()) {throw "the size of matrices is not the same";}

        for (size_t i = 0; i < c1.getMat().size(); i++) {
            sumC1+=c1.mat[i];
        }
        for (size_t i = 0; i < mat.size(); i++) {
            sum+=mat[i];
        }
        return sum>sumC1;
    }

    bool Matrix::operator>=(const Matrix& c1){
        double sum=0;
        double sumC1=0;
        if (c1.getCol()!=getCol() || c1.getRow()!=getRow()) {throw "the size of matrices is not the same";}

        for (size_t i = 0; i < c1.getMat().size(); i++) {
            sumC1+=c1.mat[i];
        }
        for (size_t i = 0; i < mat.size(); i++) {
            sum+=mat[i];
        }
        return sum>=sumC1;
    }

    bool Matrix::operator!=(const Matrix& c1){
        if (c1.getCol()!=getCol() || c1.getRow()!=getRow()) {throw "the size of matrices is not the same";}
        for (size_t i = 0; i < c1.getMat().size(); i++) {
            if(c1.getMat()[i]!=mat[i]) {return true;}
        }
        return false;
    }

    void Matrix::operator+=(const Matrix &other) {
        if (getCol()!=other.getCol() || getRow()!=other.getRow()) {throw "the size of matrices are not the same";}

        for (size_t i = 0; i < mat.size(); i++) {
            mat[i]+=other.getMat()[i];
        }
    }

    void Matrix::operator-=(const Matrix &other) {
        if (getCol()!=other.getCol() || getRow()!=other.getRow()){ throw "the size of matrices are not the same";}

        for (size_t i = 0; i < mat.size(); i++) {
            mat[i]-=other.getMat()[i];
        }
    }

    void Matrix::operator*=(const Matrix &other) {
        if (getCol()!=other.getRow()){throw "the size of matrices are not valid";}
        vector<double> v;
        double n=0;
        for (size_t i = 0; i < getRow(); i++) {
            for (size_t j = 0; j < other.getCol(); j++) {
                for (size_t k = 0; k < other.getRow(); k++) {
                    n+=mat[i*getCol()+k]*other.mat[k*other.getCol()+j];
                }
                v.push_back(n);
                n=0;
            }
        }

        mat=v;
        col=other.getCol();
    }

    void Matrix::operator*=(const double num) {
        for (size_t i = 0; i < mat.size(); i++) {
            mat[i]*=num;
        }
    }

    Matrix &Matrix::operator=(const Matrix &m) {
        mat=m.getMat();
        row=m.getRow();
        col=m.getCol();

        return *this;
    }

    Matrix Matrix::operator-() {
        vector<double> v;
        for (size_t i = 0; i < mat.size(); i++) {
            v.push_back(mat[i]*-1);
        }
        return Matrix(v,getRow(),getCol());
    }

    Matrix Matrix::operator+(){
        return *this;
    }

    Matrix &Matrix::operator++() {
        for (size_t i = 0; i < mat.size(); i++) {
            mat[i]++;
        }
        return *this;
    }

    Matrix Matrix::operator++(int d) {
        Matrix c = *this;
        for (size_t i = 0; i < mat.size(); i++) {
            mat[i]++;
        }
        return c;
    }

    Matrix &Matrix::operator--() {
        for (size_t i = 0; i < mat.size(); i++) {
            mat[i]--;
        }
        return *this;
    }

    Matrix Matrix::operator--(int d) {
        Matrix c = *this;
        for (size_t i = 0; i < mat.size(); i++) {
            mat[i]--;
        }
        return c;
    }




}

