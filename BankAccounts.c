//Oscar Rodas

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* This program reads from a file and displays the accounts in the file according to the user's input */

void prompt(void);
void readAndWrite(int option);

unsigned int account = 0;
char name[30] = {0};
double balance = 0;
int choice = 0;
FILE *cfPtr, *wfPtr;

int main(void)
{
	prompt();
	return 0;
}

void prompt(void)
{
	while(choice!= 4)
	{
		puts("Enter an option:\n 1.display positive balance accounts\n 2.display negative balance accounts\n 3.display zero balance accounts\n 4.end program");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				readAndWrite(1);    //sends 1
				break;
			case 2:
				readAndWrite(2);    //sends 2
				break;
			case 3:
				readAndWrite(3);    //sends3
				break;
			case 4:
			    puts("Exited sucessfully");
				break;
			default:
				prompt();
				break;
		}
	}
}

void readAndWrite(int option)   // the option tells the method what to execute
{
	if((cfPtr = fopen("clients.dat","r")) == NULL)
	{
		puts("File could not be opened for reading");
	}
	//else if((wfPtr = fopen("clientsw.dat","w")) == NULL)
	//{
		//puts("File could not be opened for writing");
	//}
	else
	{
		while(!feof(cfPtr))
		{
			fscanf(cfPtr,"%d %s %lf", &account, name, &balance);
			if(option == 1 && balance > 0)          //option 1 for positive accounts
			{
				//fprintf(wfPtr,"%d %s %.2f\n", account,name,balance);
				printf("%d %s %f\n", account,name,balance);
			}
			else if(option == 2 && balance < 0)     //option 2 for negative accounts
			{
				//fprintf(wfPtr,"%d %s %.2f\n", account,name,balance);
				printf("%d %s %f\n", account,name,balance);
			}
			else if(option == 3 && balance == 0.00) //option 3 for empty accounts
			{
				//fprintf(wfPtr,"%d %s %.2f\n", account,name,balance);
				printf("%d %s %f\n", account,name,balance);
			}

		}
	}
	rewind(cfPtr);  //resets pointer to start of file
	//rewind(wfPtr);
	fclose(cfPtr);
	//fclose(wfPtr);
}

