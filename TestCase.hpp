#include <iostream>

using namespace std;

class TestCase{
 
 
public:
  
string name;
ostream& current_err;
int Failed_tests;
int Passed_tests;
int All;
  
	
TestCase(string s, ostream& other):name(s),current_err(other),Passed_tests(0),Failed_tests(0),All(0) {}
		
    
template<typename T> TestCase& check_equal(T x,T y) {
 if(x == y) {
   All++;
   Passed_tests++;
  }
  else {
       All++;
       Failed_tests++;
       cout<<name<<": Failure in test #"<< All <<" "<< x <<" "<<"should equal"<<" "<< y <<" !"<<endl;
      }		
 return *this;
}
template<typename T> TestCase& check_different(T x,T y) {
   if(x!=y) {
     All++;
     Passed_tests++;
    }
    else {
         All++;
	 Failed_tests++;
	cout<<name<<": Failure in test #"<< All<<" "<<x<<" "<<"is equal"<<" "<<y<<" !"<<endl;
        }		
 return *this;	
}
template<typename T> TestCase& check_output(T x, string other) {
   stringstream in;
   in<<x;
   if(in.str().compare(other)==0) {
      All++;
      Passed_tests++;
    }
    else {
         All++;
	 Failed_tests++;
	 cout<<name<<": Failure in test #"<< All << " " <<"string value should be"<<" "<<other<<" "
         <<"but is"<<" "<<in.str()<<endl;
	}		
return *this;
}	
template<typename X,typename Y,typename Z> TestCase& check_function(Z function, X arg, Y res) {
    if((*function)(arg)==res) {
       All++;
       Passed_tests++;
       }
       else {
            All++;
	    Failed_tests++;
	    cout<<name<<": Failure in test #"<< All <<" "<<"Function should return"<<" "<<res<<" "<<"but returned"<<" "
            <<(*function)(arg)<<"!"<<endl;
           }		
  return *this;	
}  
TestCase& print() {
	current_err<<name<<": "<<Failed_tests<<" "<<"failed"<<", "<<Passed_tests<<" "<<"passed"<<", "<<All<<" "<<"total."<<endl;
	cout <<"---"<<endl;
	return *this;
  }
};
