#include<stdio.h>
#include <stdlib.h>

int k=0;
 struct stack
{
    char s[100];
    struct stack *suiv;
}stock;

void push(struct stack **elem,char s[100]);
void pop(struct stack **elem);
void main()
{
    char exp[100];
    printf("\nEntrez une expression: ");
   scanf("%s",exp);
   struct stack*suiv= NULL;
    int i=0;
    while(exp[i]!=EOF)
    {
        if((exp[i]=='(')||(exp[i]=='[')||(exp[i]=='{'))
            push(&suiv,exp[i]);
        else if((exp[i]==')')||(exp[i]==')')||(exp[i]=='}'))
        {
            if(exp[i]==')')
            {
                if(suiv =='(')
                    pop(&suiv);
                else
                    {
                    printf("\nnon valid");
                    break;
                    }
           }
           if(exp[i]==']')
            {
                if(suiv =='[')
                    pop(&suiv);
                else
                    {
                    printf("\nnon valid");
                    break;
                    }
           }
           if(exp[i]=='}')
            {
                if(suiv=='{')
                    pop(&suiv);
                else
                    {
                    printf("\nnon valid");
                    break;
                    }
           }
        }
    i++;
    return 0;
    }

   if (stock.suiv == - 1)
        printf("\nvalid");
    else
        printf("\nnon valid");
}
void push( struct stack **elem,char s[100])
{ int i;
struct stack *nouv_ele;
 nouv_ele =(char*)calloc(i, sizeof *nouv_ele);
    if (nouv_ele =! NULL){

	nouv_ele->s ;
	nouv_ele->suiv = *elem;
	*elem = nouv_ele;
}

}

void pop(struct stack **elem)
{ int i=-1;
if (elem != NULL)
        {
        	struct stack *ch = (*elem)->suiv;
        	  i = (*elem)->s ;
        	free(*elem),*elem=NULL;
        	*elem = ch;

        }


}
