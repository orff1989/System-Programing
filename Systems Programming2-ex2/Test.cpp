#include "doctest.h"
#include "sources/Notebook.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <string>
#include <algorithm>
using namespace std;

string ans="";
ariel::Notebook notebook;

TEST_CASE("Good input") {

    notebook.write(/*page=*/0, /*row=*/0, /*column=*/0, Direction::Horizontal, "hello there!");
    ans = notebook.read(/*page=*/0, /*row=*/0, /*column=*/0, Direction::Horizontal, /*length=*/12);
    CHECK(ans == "hello there!");

    notebook.write(/*page=*/0, /*row=*/1, /*column=*/1, Direction::Horizontal, "my name is Or");
    ans = notebook.read(/*page=*/0, /*row=*/1, /*column=*/1, Direction::Horizontal, /*length=*/13);
    CHECK(ans == "my name is Or");

    notebook.write(/*page=*/0, /*row=*/2, /*column=*/0, Direction::Horizontal, "i dont know");
    ans = notebook.read(/*page=*/0, /*row=*/2, /*column=*/2, Direction::Horizontal, /*length=*/4);
    CHECK(ans == "dont");

    ans = notebook.read(/*page=*/0, /*row=*/0, /*column=*/2, Direction::Vertical, /*length=*/3);
    CHECK(ans == "lyd");

    notebook.erase(0,0,0,Direction::Horizontal,12);
    ans = notebook.read(/*page=*/0, /*row=*/0, /*column=*/0, Direction::Horizontal, /*length=*/12);
    CHECK(ans == "~~~~~~~~~~~~");

    notebook.write(/*page=*/20, /*row=*/30, /*column=*/10, Direction::Horizontal, "this is page 20");
    ans = notebook.read(/*page=*/20, /*row=*/30, /*column=*/10, Direction::Horizontal, /*length=*/10);
    CHECK(ans == "this is pa");

    notebook.write(/*page=*/20, /*row=*/31, /*column=*/10, Direction::Horizontal, "what is your name?");
    ans = notebook.read(/*page=*/20, /*row=*/31, /*column=*/10, Direction::Horizontal, /*length=*/4);
    CHECK(ans == "what");

    notebook.erase(/*page=*/20, /*row=*/31, /*column=*/15,Direction::Horizontal,5);
    ans = notebook.read(/*page=*/20, /*row=*/31, /*column=*/10, Direction::Horizontal, /*length=*/18);
    CHECK(ans == "what ~~~~~ur name?");

    ans = notebook.read(/*page=*/20, /*row=*/28, /*column=*/17, Direction::Vertical, /*length=*/6);
    CHECK(ans == "__ ~__");

    notebook.write(/*page=*/22, /*row=*/64, /*column=*/2, Direction::Vertical, "this is c++");
    ans = notebook.read(/*page=*/22, /*row=*/64, /*column=*/2, Direction::Vertical, /*length=*/11);
    CHECK(ans == "this is c++");

    notebook.erase(/*page=*/22, /*row=*/65, /*column=*/2,Direction::Horizontal,2);
    ans = notebook.read(/*page=*/22, /*row=*/64, /*column=*/2, Direction::Vertical, /*length=*/11);
    CHECK(ans == "t~is is c++");

    notebook.write(/*page=*/56, /*row=*/114, /*column=*/5, Direction::Vertical, "this is c++");
    ans = notebook.read(/*page=*/56, /*row=*/114, /*column=*/5, Direction::Vertical, /*length=*/11);
    CHECK(ans == "this is c++");

}

TEST_CASE("Bad input"){

    CHECK_THROWS(notebook.write(/*page=*/-1, /*row=*/30, /*column=*/10, Direction::Horizontal, "this"));

    CHECK_THROWS(notebook.write(/*page=*/10, /*row=*/-5, /*column=*/10, Direction::Horizontal, "hi"));

    CHECK_THROWS(notebook.write(/*page=*/7, /*row=*/7, /*column=*/-77, Direction::Horizontal, "hello"));

    CHECK_THROWS(notebook.write(/*page=*/10, /*row=*/17, /*column=*/17, Direction::Vertical, "~~~"));

    CHECK_THROWS(notebook.erase(/*page=*/33, /*row=*/10, /*column=*/95,Direction::Horizontal,15));

    CHECK_THROWS(notebook.read(/*page=*/62, /*row=*/5, /*column=*/98, Direction::Horizontal, 10));

    CHECK_THROWS(notebook.write(/*page=*/55, /*row=*/55, /*column=*/96, Direction::Horizontal, "abcdefghijklmnopqrstuvwxyz"));

    CHECK_THROWS(notebook.read(/*page=*/0, /*row=*/0, /*column=*/0, Direction::Horizontal, 101));

    CHECK_THROWS(notebook.read(/*page=*/44, /*row=*/5, /*column=*/98, Direction::Vertical, -10));

    CHECK_THROWS(notebook.read(/*page=*/44, /*row=*/5, /*column=*/200, Direction::Vertical, 10));

}