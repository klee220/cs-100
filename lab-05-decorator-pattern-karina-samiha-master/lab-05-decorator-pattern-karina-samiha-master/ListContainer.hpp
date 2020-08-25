#ifndef LISTCONTAINER_HPP
#define LISTCONTAINER_HPP

#include "container.hpp"
#include <list>
#include <iostream>
#include <exception>

class ListContainer: public Container {
    public:
        ListContainer() : sort_function(nullptr) {};
        ListContainer(Sort* function) {sort_function = function;}
        void set_sort_function(Sort* sf)
        { sort_function = sf;}
        virtual void add_element(Base* element)
        {
            l.push_back(element);
        }
        virtual void print() 
        {
            for(std::list<Base*>::iterator i = l.begin(); i != l.end(); i++)
            {
                std::cout<< (*i)->stringify() << std::endl;
            }
        }
        virtual void sort()
        {
            try{
                if(sort_function == nullptr){
                    throw runtime_error("No sort function found.");
                }
            }
            catch(runtime_error e){
                std::cout << "Error caught." << std::endl;
            }
            sort_function->sort(this);
        }
        virtual void swap(int i, int j)
        {
            std::list<Base*>::iterator x = l.begin();
            std::list<Base*>::iterator y = l.begin();
            for(int n = 0; n < i; n++)
            {
                x++;
            }
            for(int m = 0; m < j; m++)
            {
                y++;
            }
            Base* temp = *x;
            *x = *y;
            *y = temp;
        }
        virtual Base* at(int i)
        {
            std::list<Base*>::iterator x = l.begin(); 
            for(int n = 0; n < i; n++)
            {
                x++;
            }
            return *x;
        }
        virtual int size() {return l.size();}
    private:
        list<Base*> l;
        Sort* sort_function; 
};

#endif
