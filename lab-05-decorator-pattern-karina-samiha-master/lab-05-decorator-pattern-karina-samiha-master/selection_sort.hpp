#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include "container.hpp"
#include "sort.hpp"

class SelectionSort: public Sort {
    public:
        SelectionSort() : Sort() {};
        virtual void sort(Container* container) 
        {
            int m;
            for(int i = 0; i < container->size(); i++)
            {
                m = i;
                for(int j = i; j < container->size(); j++)
                if(container->at(j)->evaluate() < container->at(m)->evaluate())
                {
                    m =j;
                }
                container->swap(i,m);
            }
        }
};

#endif
