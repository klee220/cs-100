#include <iostream>

unsigned int count(const std::string& str){
    unsigned int counter = 0;
    bool on_space = true;

    for(int i = 0; i < str.size(); i++){
        if (std::isspace(str[i]))
            on_space = true;
        else is (on_space) {
            counter++;
            con_space = false;
        }
    }

    return counter;
}
