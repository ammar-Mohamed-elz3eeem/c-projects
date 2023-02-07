#include "bank.h"

account_t *accounts[MAX_ACCOUNTS];
int size;

account_t *split_account(char *line)
{
	int i;
	account_t *account = NULL;
	int account_field = 0;
	int string_start = 0;

	account = malloc(sizeof(account_t));

	for (i = 0; *(line + i + 1) != '\0'; i++)
	{
		if (*(line + i + 1) == ',' || *(line + i + 1) == '\n')
		{
			if (account_field == 0)
			{
				strcpy(account->account_number, _substr(line, string_start, i + 1));
			}
			else if (account_field == 1)
			{
				strcpy(account->first_name, _substr(line, string_start, i + 1));
			}
			else if (account_field == 2)
			{
				strcpy(account->last_name, _substr(line, string_start, i + 1));
			}
			else if (account_field == 3)
			{
				account->balance = atof(_substr(line, string_start, i + 1));
			}
			account_field++;
			string_start = i + 2;
		}
	}

	return account;
}

char *_substr(char *s, int low, int high)
{
	char *ptr;
	int i = 0;

	ptr = malloc(sizeof(char) * (high + 1));

	while (i < (high - low))
	{
		*(ptr + i) = s[low + i];
		i++;
	}

	ptr[i] = '\0';
	return ptr;
}

void print_accounts(account_t **accounts)
{
	int i = 0;

	for (; accounts[i] != NULL; i++)
	{
		printf("account_number: %s,", accounts[i]->account_number);
		printf("first_name: %s,", accounts[i]->first_name);
		printf("last_name: %s,", accounts[i]->last_name);
		printf("balance: %.2f\n", accounts[i]->balance);
		printf("------------------------------------------------------------\n");
	}
}

int _getvalue(char *str, int len, int is_last_field)
{
	char *ptr = str;
	char c;
	int letters_count = 0;

	while (len > 0)
	{
		c = getchar();
		if (c == '\n' || c == '\t')
			c = '\0';
		*ptr = c;
		ptr++;
		if (c == '\0')
			len = -1;
		len--;
		letters_count++;
	}

	return letters_count;
}

void print_account(account_t *acc)
{
	printf("account number: %s\n", acc->account_number);
	printf("account first name: %s\n", acc->first_name);
	printf("account last name: %s\n", acc->last_name);
	printf("account balance: %.2f\n", acc->balance);
}

account_t **remove_account_by_account_number(char *acc_number, int arr_size)
{
	FILE *fd = fopen(DB_FILE, "r");
	size_t len = MAX_READ_SIZE;
	char *buff = NULL;
	int i = 0;
	int index = 0;

	while (getline(&buff, &len, fd) != -1)
	{
		if (strcasecmp((*(accounts + i))->account_number, acc_number) == 0)
		{
			index = i;
			break;
		}
		*(accounts + i) = split_account(buff);
		i++;
	}

	if (index > 0)
	{
		shift_array(accounts, index, arr_size);
		update_database(accounts);
	}
	if (accounts[index + 1] == NULL)
		accounts[index] = NULL;
	return accounts;
}

void shift_array(account_t **arr, int index, int arr_size)
{
	int i;
	for (i = index; i < arr_size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[i] = NULL;
}

void update_database(account_t **acounts)
{
	int i;
	FILE *filehandler;

	filehandler = fopen(DB_FILE, "w");
	for (i = 0; accounts[i] != NULL; i++)
	{
		char *buff = struct_to_string(accounts[i]);
		fwrite(buff, 1, strlen(buff), filehandler);
		free(buff);
	}
	fclose(filehandler);
}

char *struct_to_string(account_t *user)
{
	char *buff;
	buff = malloc(sizeof(char) * 1024);
	sprintf(buff, "%s,%s,%s,%.2f\n", user->account_number, user->first_name, user->last_name, user->balance);
	return buff;
}

char *int_to_string(float number)
{
	char *numstr;
	numstr = malloc(sizeof(char) * 1);
	sprintf(numstr, "%.2f", number);
	return numstr;
}

void readstring(char *s, int len)
{
	char c;
	char *ptr = s;

	while (len > 0)
	{
		c = getchar();
		if (c == '\n' || c == ' ')
			c = '\0';
		*ptr = c;
		ptr++;
		if (c == '\0')
			len = -1;
		len--;
	}
}
