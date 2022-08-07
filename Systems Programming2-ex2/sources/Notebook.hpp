#include <system_error>
#include "Direction.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

namespace ariel{

    class Page{
    public:
        vector<vector<char>> v;
        int num;

        Page(){}

        Page(int n) {
            this->num = n;
            this->v.resize(100, vector<char>(100,'_'));
        }

        void showPage();

        void writeIn(size_t row, size_t column, ariel::Direction direction, const std::string &str);

        string readIn(size_t row, size_t column, ariel::Direction direction, size_t len);

        void increase_Rows(size_t n);
    };

    class Notebook {
    public:

        vector<Page> pages;

        Notebook() {
            increase_Pages(10);
        }

        void increase_Pages(size_t num);

        void write(int page, int row, int column, ariel::Direction direction, const std::string &str);

        const string &read(int page, int row, int column, ariel::Direction direction, int length);

        void erase(int page, int row, int column, Direction direction, int length);

        void show(int page);

    };
}







