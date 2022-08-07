#include "Notebook.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace ariel;
using ariel::Direction;

const size_t ADDITION = 10;
const size_t COL =100;
const size_t ROW =100;
const size_t LIMIT=99;
const size_t CHAR_LIMIT_UP=123;
const size_t CHAR_LIMIT_DOWN=32;

bool str_not_valid(string s){
    for (size_t i = 0; i < s.length(); i++) {
        if(int(s.at(i))>CHAR_LIMIT_UP || int(s.at(i))<CHAR_LIMIT_DOWN){return true;}
    }
    return false;
}

//////////////////////// PAGE ////////////////////////////

void ariel::Page::showPage() {
    for (size_t i = 0; i < this->v.size(); i++){
        for (size_t j = 0; j < this->v[0].size(); j++) {
            cout << v[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void ariel::Page::writeIn(size_t row, size_t column, ariel::Direction direction, const std::string &str) {
    if(direction==Direction::Horizontal) {
        for (size_t i = 0; i < str.size(); i++) {
            this->v[row][column + i] = str.at(i);
        }
    }
    else{
        for (size_t i = 0; i < str.size(); i++) {
            this->v[row + i][column] = str.at(i);
        }
    }
}

string ariel::Page::readIn(size_t row, size_t column, ariel::Direction direction, size_t len){
    string ans;

    if(direction==Direction::Horizontal) {
        for (size_t i = 0; i < len; i++) {
            ans.append(1,this->v[row][column + i]);
        }
    }
    else{
        for (size_t i = 0; i < len; i++) {
            ans.append(1,this->v[row + i][column]);
        }
    }
    return ans;
}

void ariel::Page::increase_Rows(size_t n) {
    this->v.resize(n+ADDITION, vector<char>(COL,'_'));
}

/////////////// NOTEBOOK /////////////////////

void ariel::Notebook::increase_Pages(size_t num){
    for (int i = this->pages.size(); i < num+ADDITION; i++) {
        this->pages.push_back(Page(i));
    }
}

void ariel::Notebook::write(int page, int row, int column, ariel::Direction direction, const std::string &str){
    //checking the parameters
    if(page<0 || row<0 || column<0 || str.find('~')!=string::npos|| column>LIMIT || str_not_valid(str)) {throw "the parameters are not valid";}
    if(column+int(str.size())-1>LIMIT && direction==Direction::Horizontal) {throw "there is not enough space in the line for this word";}

    // if we need to resize the number of pages
    if (page >= this->pages.size()){
        increase_Pages(size_t(page));
    }
    // if there is no space to write the string vertically
    if(size_t(row)+str.length()>this->pages[size_t(page)].v.size() && direction==Direction::Vertical){
        this->pages[size_t(page)].increase_Rows(size_t(row)+str.length()+ADDITION);
    }
    //if we need to resize the number of rows
    if (row>=this->pages[size_t(page)].v.size()){
        this->pages[size_t(page)].increase_Rows(size_t(row)+ADDITION);
    }


    string str1 = this->pages[size_t(page)].readIn(size_t(row),size_t(column),direction,str.length());
    for (size_t i = 0; i < str1.size(); i++) {
        if (str1.at(i) != '_') { throw "cant write on written space"; }
    }

    this->pages[size_t(page)].writeIn(size_t(row),size_t(column),direction,str);
}

const string& ariel::Notebook::read(int page, int row, int column, ariel::Direction direction, int length){
    if(page<0 || row<0 || column<0 || length<0 || column>LIMIT) {throw "the parameters are not valid";}
    if(column+length-1>LIMIT && direction==Direction::Horizontal) {throw "there is not enough space in the line for this word";}

    // if we need to resize the number of pages
    if (page >= this->pages.size()){
        increase_Pages(size_t(page));
    }
    // if there is no space to write the string vertically
    if(size_t(row)+size_t(length) > this->pages[size_t(page)].v.size() && direction==Direction::Vertical){
        this->pages[size_t(page)].increase_Rows(size_t(row)+size_t(length) + ADDITION);
    }
    //if we need to resize the number of rows
    if (row>=this->pages[size_t(page)].v.size()){
        this->pages[size_t(page)].increase_Rows(size_t(row)+ADDITION);
    }

    static string * ans;
    ans = new string;
    *ans = this->pages[size_t(page)].readIn(size_t(row),size_t(column),direction,size_t(length));
    return *ans;
}

void ariel::Notebook::erase(int page, int row, int column, Direction direction, int length){
    if(page<0 || row<0 || column<0 || length<0|| column>LIMIT) {throw "the parameters are not valid";}
    if(column+length-1>LIMIT && direction==Direction::Horizontal) {throw "there is not enough space in the line for this word";}

    // if we need to resize the number of pages
    if (page >= this->pages.size()){
        increase_Pages(size_t(page));
    }
    // if there is no space to write the string vertically
    if(size_t(row)+size_t(length) > this->pages[size_t(page)].v.size() && direction==Direction::Vertical){
        this->pages[size_t(page)].increase_Rows(size_t(row)+size_t(length) + ADDITION);
    }
    //if we need to resize the number of rows
    if (row>=this->pages[size_t(page)].v.size()){
        this->pages[size_t(page)].increase_Rows(size_t(row)+ADDITION);
    }

    std::string ans;
    ans.append(size_t(length),'~');

   this->pages[size_t(page)].writeIn(size_t(row),size_t(column),direction,ans);
}

void ariel::Notebook::show(int page) {
    if(page<0 || page>= this->pages.size()) {throw "the parameters are not valid";}

    // if we need to resize the number of pages
    if (page >= this->pages.size()){
        increase_Pages(size_t(page));
    }

    this->pages[size_t(page)].showPage();
}

