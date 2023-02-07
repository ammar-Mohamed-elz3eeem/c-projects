#include "bank.h"

account_t *delete_account(char *acc_number, int arr_size)
{
	remove_account_by_account_number(acc_number, arr_size);
}