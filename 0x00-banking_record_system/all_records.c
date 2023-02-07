#include "bank.h"

int read_entires(char *filename)
{
	FILE *fd = fopen(filename, "r");
	size_t len = MAX_READ_SIZE;
	char *buff = NULL;
	int i = 0;

	while (getline(&buff, &len, fd) != -1)
	{
		*(accounts + i) = split_account(buff);
		i++;
	}

	*(accounts + i) == NULL;

	fclose(fd);

	return i;
}

void create_reading_process()
{
	pid_t proccess_pid;

	proccess_pid = fork();
	if (proccess_pid == 0)
		read_entires(DB_FILE);
	if (proccess_pid != 0)
		print_accounts(accounts);
}
