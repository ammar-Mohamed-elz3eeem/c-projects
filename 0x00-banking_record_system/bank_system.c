#include "bank.h"

int bank_system(int arr_size)
{
	char str[20];
	account_t *acc = NULL;
	int another_op = 1;

	acc = malloc(sizeof(account_t));
	if (acc == NULL)
		return 0;

	printf("Welcome to our Bank System :)\n");
	printf("please enter your account number to continue: ");
	readstring(str, 20);
	acc = search_record(str, arr_size);
	if (acc == NULL)
	{
		dprintf(STDERR_FILENO, "Sorry, this account is not registered in our database\n");
		exit(404);
	}
	while (another_op)
	{
		make_operation(arr_size);
		printf("Do you want to make another operation ? (y,n): ");
		readstring(str, 2);
		if (*str != 'y' && *str != 'Y')
			another_op = 0;
	}
}

void make_operation(int arr_size)
{
	char str[2];
	int choice;

	printf("Please choose one of the following operations\n");
	printf("(1) Add Another account\n");
	printf("(2) Delete existing account\n");
	printf("(3) update account\n");
	printf("(4) search for an account\n");
	printf("Just enter number of operation: 1 or 2 or 3 or 4: ");

	readstring(str, 2);
	choice = atoi(str);

	run_operation(choice, arr_size);

	// switch (choice)
	// {
	// case 1:
	// 	printf("you choice is to add new account\n");
	// 	break;
	// case 2:
	// 	printf("your choice is to delete an account\n");
	// 	break;
	// case 3:
	// 	printf("your choice is to update an account\n");
	// 	break;
	// case 4:
	// 	printf("your choice is to search for an account\n");
	// 	break;
	// default:
	// 	printf("invalid option, please choose one of the following numbers: (1, 2, 3, 4) \n");
	// 	break;
	// }
}

void run_operation(int op_code, int arr_size)
{
	int i = 0;
	char acc_number[20];
	op_t acc_operations[5] = {
	    {1, add_record},
	    {2, delete_account},
	    {3, search_record},
	    {4, update_record},
	    {5, NULL}};

	while (acc_operations[i].op != NULL)
	{
		if (acc_operations[i].op_code == op_code)
		{
			printf("Please enter account number: ");
			readstring(acc_number, 20);

			acc_operations[i].op((void *)acc_number, arr_size);
			return;
		}
		i++;
	}

	printf("Invalid operation code\n");
}
