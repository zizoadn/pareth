#include <stack>

// fonction pour tester si les parenthése sont ballancé
bool test(string expr) 
{ 
    // on cree une pile 
	stack<char> pile; 
    
	// ce x va represente le dernier element dans la pile, 
	// qu'on vas comparez avec l'element qu'on vient de scanner
	char x; 
  
    // une loop pour scanner 
    for (int i=0; i<expr.length(); i++) 
    { 
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{') 
        { 
            // on c++ on a pas besoin de céer une fonctin push
            pile.push(expr[i]); 
             
        } 
  
        // ci l'element n'est pas une ( , [,{  
        // alors on le compare avec le dernier element dans la pile
        
     
         else {
		 
         
        switch (expr[i]) 
        { 
        case ')': 
  
            
            x = pile.top(); 
            pile.pop(); 
            if (x=='{' || x=='['){
		
                return false; 
            	} 
		    else 
			    return true   
            break; 
  
        case '}': 
  
            
            x = pile.top(); 
            pile.pop(); 
            if (x=='(' || x=='['){
			 
                return false; 
                }
            else 
                return true;
                
            break; 
  
        case ']': 
  
            x = pile.top(); 
            pile.pop(); 
            if (x =='(' || x == '{') {
			
                return false; 
                }
            else 
                return true;
            break; } 
            
        } 
     
	     

	} 
		 
   if (!pile.empty()) 
           return false;
    
  
} 
 
