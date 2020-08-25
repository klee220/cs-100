#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include "container.hpp"
#include "sort.hpp"

class BubbleSort : public Sort{
	public:
		BubbleSort() : Sort(){};
		virtual void sort(Container* container){
			bool swapped = true;
      			for(int i = 1; i <= container->size() && swapped; i++){
        			swapped = false;
        			for (int j = 0; j < container->size() - i; j++){
          				if(container->at(j)->evaluate() > container->at(j+1)->evaluate()){
            					container->swap(j, j+1);
            					swapped = true;
          				}
        			}
      			}
    		}
    
};


#endif
