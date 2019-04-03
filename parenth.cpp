#include <iostream>
#include "tester"

using namespace std; 
 

int main() 
{ 
    string expr ;
    
    cout << "entrez l'expression"
    
    getline(cin,expr);
  
    if (test(expr)) 
        cout << "\tvalid"; 
    else
        cout << "\tnon valid"; 
    return 0; 
} 

