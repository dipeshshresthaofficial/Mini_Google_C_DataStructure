#include <stdio.h>

#include <stdlib.h>
#include <string.h>


FILE *f1;
char buffer[30],input[29],line[38],name[38],ch,pass[20];
int check=0;
void carsBrands_fun();
void fruitsNames_fun();
void commonFun();
void gamesNames_fun();
void insertFun(char []);
void printFun();
struct linkedlist{
	char data[30];
	struct linkedlist *next;
};
typedef struct linkedlist node;
node* head=NULL;
int main()
{
	int option;
	char che;
	do{
	printf("\n1. car brand \n 2. fruits\n 3. games \n");
	printf("\nenter your choice:\n");
	scanf("%d",&option);
        fflush(stdin);
	switch(option)
	{
		case 1: carsBrands_fun();
			break;
		case 2: fruitsNames_fun();
			break;
		case 3: gamesNames_fun();
			break;
		default:
			printf("\ninvalid\n");
	}
	printf("\ndo you want to go back to main menu?");
	scanf("%s",&che);
	}while(che=='Y'||che=='y');
	
	return 0;
}
void carsBrands_fun()
{	
   
    
	do
        {

		printf("\nenter the any two letters of the word which you want to search:");
		scanf("%s",&input);
                printf("\n Your search result are:\n");

		f1=fopen("D:\\cars_brands.txt","r");
                

		while(!feof(f1))
		{
			commonFun();
			

		}
                if(check<=1)
                {
                    printf("SOORY! we are not able to search your input");
                }
	
		printf("\n do you want to continue under Car Brand search(Y/N):");
                scanf("%s",&ch);
        } while(ch=='y'||ch=='Y');
       
		fclose(f1);

}
void fruitsNames_fun()
{
   
	do{

		printf("\nenter the any two letters of the word which you want to search:");
		scanf("%s",&input);
                printf("\n Your search result are:\n");

		f1=fopen("D:\\fruits_names.txt","r");

		while(!feof(f1))
		{
			commonFun();
			

		}
                if(check<=1)
                {
                    printf("SOORY! we are not able to search your input");
                }
		printf("\n do you want to continue inside Fruits search?(Y/N):");
		scanf("%s",&ch);
    } while(ch=='y'||ch=='Y');
    
		fclose(f1);

}

void gamesNames_fun()
{
    
	do{

		printf("\nenter the any two letters of the word which you want to search:");
                
                
		scanf("%s",&input);
               
                printf("\n Your search result are:\n");
		f1=fopen("D:\\games_names.txt","r");

		while(!feof(f1))
		{
                    
			commonFun();

		}
            
                if(check<=1)
                {
                    printf("SOORY! we are not able to search your input");
                }
		
		printf("\n do you want to continue inside Games search?(Y/N):");
		scanf("%s",&ch);
    } while(ch=='y'||ch=='Y');
    
    
		fclose(f1);

}

void commonFun()
{
	int i,j,hit=0;
	char *pass;
	pass=malloc(sizeof(char));
	fgets(buffer,30,f1);
			while(input[i]!='\0')
			{
				while(buffer[j]!='\n')
				{
					if(input[i]==buffer[j])
					{
					
						i++;
						j=0;

						hit++;
						break;
					}
					else
					{
						j++;
					}


				}
				if(buffer[j]=='\n')
					{
						break;
					}
			}


			if (hit==2)
			{
				//linked list logic
                            
				//printf("the suitable word is %s",buffer);
				check=check+1;
				insertFun(buffer);
                                
				printFun();
                                
			}
                        
			hit=0;
			i=0;
			j=0;
                        
}

void insertFun(char buffer[30] )
{
	node* temp=malloc(sizeof(node));
	strcpy(temp->data,buffer);
	temp->next=head;
	head=temp;
}
void printFun()
{
	node* temp=head;
	
	while(temp!=head)
	{
		printf("%s",temp->data);
		temp=temp->next;
	}
        printf("%s",temp->data);
        temp=temp->next;
}
