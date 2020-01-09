#include "Document.h"

Document::Document(){
    // cout << "Doc c'tor"<<endl;
    this->current=0;
}

Document::~Document(){
    // cout << "Doc d'tor"<<endl;
    doc.clear();
}

void Document::command_p(){
    int i = this->getCurrent(); //-1
    // cout << "current is:" << this->getCurrent() << endl;
    cout << this->doc[i] <<endl;
}

void Document::command_n(){ //shows the number of current line and prints the line
    int i = this->getCurrent(); //-1
    cout << i+1 << "\t" << this->doc[i] << endl;
}

void Document::command_pAll(){
    for(int i=0; i < this->doc.size(); i++){
        cout << this->doc[i] <<endl;
    }
}

void Document::command_num(string com){
    this->current=stoi(com)-1;
    int i = this->getCurrent();
    cout << this->doc[i] <<endl;
}

void Document::command_a(){
    if(this->current == this->doc.size()){
        string input;
        getline(cin,input);
        cout << input << endl;
        while(input!= "."){
            this->doc.push_back(input);
            this->current++;
            getline(cin,input);
           cout << input << endl;
        }
        this->current--;
    }
    else{
        string input2;
        getline(cin,input2);
        cout << input2 << endl;
        while(input2 != "."){
            int i=this->getCurrent();
            auto it=this->doc.insert(this->doc.begin()+i+1,input2); 
            this->current++;
            getline(cin,input2);
            cout << input2 << endl; 
        }  
    }
}

void Document::command_i(){ //insert before the current
    int i =this->getCurrent(); 
    string input;
    getline(cin, input);
    cout << input << endl;
    auto it = this->doc.insert(this->doc.begin()+i, input);
    this->current++;
}

void Document::command_c(){ //change the current line for text that follow 
    int i = this->getCurrent(); 
    auto it = this->doc.erase(this->doc.begin()+i);
    string input;
    getline(cin, input);
    cout << input << endl;
    auto it2 = this->doc.insert(this->doc.begin()+i, input);
}

void Document::command_d(){ //delete the current line
    int i = this->getCurrent(); 
    auto it = this->doc.erase(this->doc.begin()+i);
    this->current--;   
}

void Document::command_SearchF(string com){
    bool flag=false;
    string str = com.substr(1,com.size());

    for(int i=this->getCurrent() ; i<this->doc.size() && flag==false; i++){ //current to end
        size_t found = this->doc[i].find(str); 
        if (found != string::npos) {
            flag=true;
            this->current=i;
            cout<< this->doc[i]<<endl;
        }
    }
    
    for(int i=0 ; i<this->getCurrent() && flag==false; i++){ //start to current
        size_t found = this->doc[i].find(str); 
        if (found != string::npos){
            flag=true;
            this->current=i;
            cout<< this->doc[i]<<endl;
        }
    }
}

void Document::command_RepeatSearch(string search_s){
    this->current++;
    command_SearchF(search_s);
}

void Document::command_SearchB(string com){
bool flag=false;
    string str = com.substr(1,com.size());

    for(int i=0 ; i<this->getCurrent() && flag==false; i++){ //start to current
        size_t found = this->doc[i].find(str); 
        if (found != string::npos){
            flag=true;
            this->current=i;
            cout<< this->doc[i]<<endl;
        }
    }   
}

void Document::command_sOldNew(string com){
    vector<string> re;
    string str=com.substr(2,com.size());
    size_t found = str.find("/");
    string temp=str.substr(0,found); 
    re.push_back(temp);
    string temp2=str.substr(found+1,str.size()-found-2);
    re.push_back(temp2);
    int i = this->getCurrent();
    found = this->doc[i].find(temp);
    this->doc[i].replace(found, re[0].size(), re[1]);
}