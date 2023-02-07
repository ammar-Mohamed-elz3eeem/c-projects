#include "bank.h"

account_t *update_record(char *acc_number, int arr_size)
{
	int i = 0;
	int update_more = 1;
	char answer[2];

	while (accounts[i] != NULL)
	{
		if (strcasecmp(acc_number, accounts[i]->account_number) == 0)
		{
			while (update_more)
			{
				run_update(accounts[i]);
				printf("Do you want to update anything else (y/n): ");
				readstring(answer, 2);
				if (*answer != 'y' && *answer != 'Y')
					update_more = 0;
			}
		}
		i++;
	}
}

int update_fname(account_t *acc)
{
	char buff[255];
	readstring(buff, 255);
	strcpy(acc->first_name, buff);
	return 1;
}

int update_lname(account_t *acc)
{
	char buff[255];
	readstring(buff, 255);
	strcpy(acc->last_name, buff);
	return 1;
}

int update_balance(account_t *acc)
{
	char buff[20];
	double updated_balance;

	readstring(buff, 20);
	updated_balance = atof(buff);
	acc->balance = updated_balance;
	return 1;
}

void run_update(account_t *acc)
{
	int i = 0;
	char s[2];
	int number;
	updater_t updaters[4] = {
	    {1, update_fname},
	    {2, update_lname},
	    {3, update_balance},
	    {0, NULL}};

	printf("(1) Update first name\n");
	printf("(2) Update last name\n");
	printf("(3) Update balance\n");
	printf("Please Enter a number for what you want to update: ");

	readstring(s, 20);
	number = atoi(s);

	while (updaters[i].update_function != NULL)
	{
		if (updaters[i].update_option == number)
		{
			updaters[i].update_function(acc);
			return;
		}
		i++;
	}

	printf("Invalid operation code\n");
}
