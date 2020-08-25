#ifndef VECTORCONTAINER_HPP
#define VECTORCONTAINER_HPP

#include "container.hpp"
#include <vector>
#include <iostream>
#include <exception>

using namespace std;

class VectorContainer: public Container {
	public: 
		VectorContainer() : sort_function(nullptr) { };
   		VectorContainer(Sort* function) : sort_function(function) { };
		void set_sort_function(Sort* sort_function) {
			this->sort_function = sort_function;
		}
		virtual void add_element(Base* element) {
			vect.push_back(element);
		}
		virtual void print() {
			for(unsigned i = 0; i < vect.size(); ++i) {
				cout << vect.at(i)->stringify() << endl;
			}	
		}
		virtual void sort() {	
      			try{
        			if(sort_function == nullptr){
          				throw runtime_error("No sort function found.");
        			}
      			}
      			catch(runtime_error e){
        			cout << "Error caught." << endl;
      			}
      			sort_function->sort(this);
    		}	 
		virtual void swap(int i, int j) { 
			Base* temp = vect.at(i);	
			vect.at(i) = vect.at(j);
			vect.at(j) = temp;
		} 
		virtual Base* at(int i) {
     			return vect.at(i);  
    		}
		virtual int size() { 
      			return vect.size(); 
    		}
	private:
		vector<Base*> vect;
		Sort* sort_function;
};

#endif
