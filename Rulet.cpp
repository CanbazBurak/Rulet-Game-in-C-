#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void fcn1(int bet_type,int specific_number,char *status,int *slot_number)
{	
	srand (time(NULL));
	*slot_number= rand()%36;

if(bet_type==1)
	{
			if(*slot_number==0)
		{
			*status='L';
		}
	else  {
		if(*slot_number%2==0)
		{
			*status='L';		
		}
		else if(*slot_number%2
		==1)
		{
			*status='W';
		}
	     }
   }
else if(bet_type==2)
	{
			if(*slot_number==0)
		{
			*status='L';
		}
		else {
		 if(*slot_number%2==0)
		{
			*status='W';		
		}
		else if(*slot_number%2==1)
		{
			*status='L';
		}
    	}
	}
else if(bet_type==3)
{
		if(*slot_number==0)
		{
			*status='L';
		}
   else {
   
	 if(*slot_number==specific_number)
	{
		*status='W';
	}
	else if(*slot_number!=specific_number)
	{
		*status='L';
	}
        }	
}
     }
int main(void)
{
	int spin=0,start_account,initial_account,bet_amount,final_account,choise,special_number,incoming_number;
	char stat,ch;

	do
	{
		spin++;
		printf("Spin %d:\n",spin);
		if(spin==1)
		{
		printf("Enter a start account for the game $:");
		scanf("%d",&start_account);
		if(start_account==0)
		{
			printf("Sorry start account must be greater then zero.See you again.");
			return(0);
		}
		initial_account=start_account;
		}
		
		
		
		printf("Enter the bet amount $:");
		scanf(" %d",&bet_amount);
		printf("Enter '1' to bet on an odd number, '2' to bet on an even number, or '3' to bet on a specific number:");
		scanf("%d",&choise);
		if(choise==3)
		{
		printf("Enter a number between 1-35:");
		scanf("%d",&special_number);
		while(special_number<1 || special_number>35)
		{
			printf("Enter a number between 1-35:");
			scanf("%d",&special_number);
		}
		}
		fcn1(choise,special_number,&stat,&incoming_number);
		printf("The ball fell in slot numbered %d\n",incoming_number);
		if(choise==1 || choise==2)
		{
					
			if(stat=='W')
			{
				printf("You Win the bet.\n");
				printf("Initial account $:%d\n",initial_account);
				printf("Final account $:%d\n",initial_account=bet_amount+initial_account);
			}
			else if(stat=='L')
			{
				printf("You lost the bet.\n");
				printf("Initial account $:%d\n",initial_account);
				printf("Final account $:%d\n",initial_account=initial_account-bet_amount);
			}
				if(initial_account==0)
		{
			printf("End of the game.Thanks for playing the game.");
			return(0);
		}
		}
		else if(choise==3)
		{
			if(stat=='W')
			{
				
				printf("You win the bet.\n");
				printf("Initial account $:%d\n",final_account=initial_account+(bet_amount*35));
				printf("Final account $:%d\n",final_account);
			}
			else if(stat=='L')
			{
				final_account=final_account-bet_amount;
				printf("You lost the bet.\n");
				printf("Initial account $:%d\n",initial_account);
				printf("Final account $:%d\n",initial_account=initial_account-bet_amount);
			}
			if(initial_account==0)
		{
			printf("End of the game.Thanks for playing the game.");
			return(0);
		}
		}
	printf("Do you want to continue? Enter Y or N:");
	scanf(" %c",&ch);	
	}
	while(ch=='Y' || ch=='y');
	printf("Thank you for playing the game.\n");
	
	
	
	system("pause");
	return(0);
	
}


