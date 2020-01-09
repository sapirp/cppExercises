#ifndef _Editor_h
#define _Editor_h
#include <iostream>
#include "Document.h"

using namespace std;

class Editor{
    private:
        Document d;
        string search_s;
    public:
        Editor();
        ~Editor();
        void loop();
        
};

#endif
