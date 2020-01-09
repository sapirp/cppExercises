#ifndef _Document_h
#define _Document_h
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
//#include <boost/tokenizer.hpp>
// #include <boost/algorithm/string.hpp>


using namespace std;


class Document
{
private:
    vector<string> doc;
    int current;

public:
    Document();
    ~Document();
   
    void command_p(); //prints the current line (ed maintains a current line)
    void command_n(); //prints line number of current line followed by TAB followed by current line
    void command_pAll(); //prints all lines
    void command_num(string com); //makes line #number the current line
    void command_a(); //appends new text after the current line
    void command_i(); //inserts new text before the current line
    void command_c(); //changes the current line for text that follows 
    void command_d(); //deletes the current line
    void command_SearchF(string com); //searches forward after current line for the specified text
    void command_RepeatSearch(string search_s); //Repeat search.
    void command_SearchB(string com); //searches backward 
    void command_sOldNew(string com); //replaces old string with new in current line (google: C++ split or token)
   
    int getCurrent(){ return this->current; }
    void setCurrent(int num){ this->current=num; }
    
};
#endif