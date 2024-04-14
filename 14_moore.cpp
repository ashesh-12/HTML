///Moore machine that prints a wheneevr 01 encountered else b

#include<stdio.h>

enum states { q0, q1, q2};
void delta(enum states, char *);

int main()
{
	char input[20];
	enum states curr_state = q0;
	int i =0;
	
	printf("\n Enter a binary string\t");
	scanf("%s",input);
	char ch = input[i];
	printf("\n Output string\t");
	delta(curr_state,input);
	
   return 0;			
}


void delta(enum states curr_state, char * input)
{
	int i=0;
	printf("b");
      while(input[i] !='\0')
      {
      	   switch(curr_state)
		{
			case q0:
				if(input[i]=='0')
				{
				   printf("b");
				   curr_state = q1;
				}
				else
				{
				   printf("b");
				   curr_state = q0;
				}
				break;
			case q1:
				if(input[i]=='0')
				{
				   printf("b");
				   curr_state = q1;
				}
				else
				{
				   printf("a");
				   curr_state = q2;
				}
				  
				break;
			case q2:
				if(input[i]=='0')
				{
				   printf("b");
				   curr_state = q1;
				}
				else
				{
				   printf("b");
				   curr_state = q0;
				}
				break;

		}	
		i++;
	}
	printf("\n");
}
