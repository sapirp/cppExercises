#include "Editor.h"
#include "Document.h"
#include <typeinfo>

using namespace std;

Editor::Editor(){
    // cout << "Editor c'tor"<<endl;
}

Editor::~Editor(){
    search_s.clear();
    // cout << "Editor d'tor"<<endl; 
}

void Editor::loop(){

    string com;
    while(com != "Q"){
        
        int num;
        getline(cin,com);
        cout << com << endl;
        if(com == "p") this->d.command_p();
        if(com == "n") this->d.command_n();
        if(com == "%p") this->d.command_pAll();
        if(isdigit(com.at(0))) this->d.command_num(com);
        if(com == "a") this->d.command_a();
        if(com == "i") this->d.command_i();
        if(com == "c") this->d.command_c();
        if(com == "d") this->d.command_d();
        if(com == "/") this->d.command_RepeatSearch(this->search_s); 
        if(com.at(0) == '/') {
            this->search_s="/"+com;
            this->d.command_SearchF(com);
        }
        if(com.at(0) == '?') this->d.command_SearchB(com);
        if(com.substr(0, 2) == "s/") this->d.command_sOldNew(com);
    }
}
