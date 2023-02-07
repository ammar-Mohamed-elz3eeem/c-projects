#include "bank.h"

account_t *search_record(char *acc_number, int arr_size)
{
	account_t *account;
	int i = 0;

	account = malloc(sizeof(account_t));
	if (account == NULL)
		return NULL;

	while (*(accounts + i))
	{
		if (strcasecmp(acc_number, accounts[i]->account_number) == 0)
		{
			account = *(accounts + i);
			print_account(account);
			return account;
		}
		i++;
	}

	return NULL;
}
