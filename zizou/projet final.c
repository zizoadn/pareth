/**
 * Plusieurs commentaires importants :
 * 1. Ta fonction main est trop grosse, elle fait trop de chose, il faut
 *    séparer les concepts pour que chacun et un rôle et 1 seul
 * 2. L'indentation DOIT être respecté, sinon le code est illisible
 * 3. Le code DOIT être commenté, sinon il est inutilisable.
 * 4. Les blocs if doivent avoir les accolades, même quand ils font une seule
 *    ligne, pour la clarté et la lisibilité
 * 5. Le code doit être moins compact, il faut aérer en parsemant d'explication
 * 6. Il manque ta ligne de compilation
 */

#include <stdio.h>
#include <stdlib.h>

struct pile{
	char tete;
	struct pile *suivant;
};
int tester(char par1,char par2);
int traiter(char exp[]);
void push(struct pile** top,int nouveau);
int pop(struct pile** top);

void main(){
	char exp[100];
	printf("entrez une expression:\t");
	scanf("%s",exp);
	if (traiter(exp)==1)
	printf("valid");
	else
	printf("non valid");
}
int tester(char par1,char par2){
	if(par1=='('&& par2==')')
	return 1;
	else if (par1 =='{'&&par2=='}')
	return 1;
	else if (par1 == '['&& par2 == ']')
	return 1;
	else
	return 0;
}
int traiter(char exp[]){

	struct pile *stock;
	int i=0;
while(exp[i]!=EOF){
	/**
	 * C'est dommage si je veux rajouter un symbole, genre par exemple / et \
	 * en ouverture fermeture, il faut aller profondément dans le code
	 */
  	if (exp[i]=='('||exp[i]=='['||exp[i]=='{')
  	   push(&stock,exp[i]);
  	if (exp[i]==')'||exp[i]==']'||exp[i]=='}')
  	  if(stock ==NULL)
  	  return 0;
  	  else if(!tester(pop(&stock), exp[i]))
  	return 0;


  ++i;
}
  	 if(stock== NULL)
   return 1;
   else
   return 0;

}
void push(struct pile** top,int nouveau)
/**
 * Indentation incorrecte, de plus on évite les variables en majuscule, elles
 * sont réservées pour les constantes en général, ce sont des bonnes pratiques
 */
{ struct pile *LIFO= (struct pile*)malloc(sizeof(struct pile));
  if (LIFO==0)
   printf("non valid");
  else
   LIFO->tete=nouveau;
   LIFO->suivant=(*top);
   (*top)=LIFO;
}
int pop(struct pile **top){
	char s;
	struct pile* pop;
	if(*top==0){

	printf("non valid");

	  exit(0);

     	}
	else
	/** Si pop contient la valeur NULL tu as une erreur ici */
	pop = *top;
	s =pop->tete;
	*top =pop->suivant;
	free(top);

	return s;
}

