#include "bank.h"

account_t *create_admin_account(int arr_size)
{
	char buff[100];
	int len = 255;
	int l = 0;
	account_t *account;

	account = malloc(sizeof(account_t));

	if (account == NULL)
		return NULL;

	printf("Enter Admin Account Number: ");
	l = _getvalue(buff, len, 0);
	strncpy(account->account_number, buff, l);

	printf("Enter Admin Account First Nane: ");
	l = _getvalue(buff, len, 0);
	strncpy(account->first_name, buff, l - 1);

	printf("Enter Admin Account Last Nane: ");
	l = _getvalue(buff, len, 0);
	strncpy(account->last_name, buff, l - 1);

	printf("Enter Admin Account Balance: ");
	l = _getvalue(buff, len, 1);
	account->balance = atof(buff);

	accounts[arr_size + size++] = account;

	print_account(account);
	printf("Record inserted successfully\n");
	return account;
}
