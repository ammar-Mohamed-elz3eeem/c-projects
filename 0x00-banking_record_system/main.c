#include "bank.h"

int main(void)
{
	char *filename = "data.csv";
	int size = read_entires(DB_FILE);
	if (size == 0)
		create_admin_account(size);
	bank_system(size);
	update_database(accounts);
}