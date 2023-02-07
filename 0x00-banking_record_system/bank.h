#ifndef __BANK_SYSTEM__
#define __BANK_SYSTEM__

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/file.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_READ_SIZE 1024
#define MAX_ACCOUNTS 1024
#define DB_FILE "data.csv"

/**
 * struct Account - this is a structure to hold account information
 * @account_number: string that represtents account number
 * @first_name: string represennts account owner first name
 * @last_name: string represennts account owner last name
 * @balance: double represennts account owner balance
 */

typedef struct Account
{
	char account_number[20];
	char first_name[255];
	char last_name[255];
	double balance;
} account_t;

/**
 * struct AccountOp - this is a structure to hold all accounts operationss
 * @op_code: code that determines the operation needed
 * @op: pointer to a function associated with every account
 * @callback: function to run after making operation on account
 */

typedef struct AccountOp
{
	int op_code;
	account_t *(*op)(char *, int);
} op_t;

typedef struct updater
{
	int update_option;
	int (*update_function)(account_t *);
} updater_t;

extern account_t *accounts[MAX_ACCOUNTS];
extern int size;

int read_entires(char *filename);
char *_substr(char *s, int low, int high);
account_t *split_account(char *line);
void print_accounts(account_t **accounts);
int _getvalue(char *str, int len, int is_last_field);
void print_account(account_t *acc);
void create_reading_process();
account_t **remove_account_by_account_number(char *acc_number, int arr_size);
void shift_array(account_t **arr, int index, int arr_size);
void update_database(account_t **acounts);
char *struct_to_string(account_t *user);
char *int_to_string(float number);
void readstring(char *s, int len);

void make_operation(int size);
int bank_system(int arr_size);

/**
 * Updaters
 */

int update_fname(account_t *acc);
int update_lname(account_t *acc);
int update_balance(account_t *acc);

/**
 * Runners
 */

void run_operation(int op_code, int size);
void run_update(account_t *acc);

account_t *add_record(char *acc_number, int arr_size);
account_t *delete_account(char *acc_number, int arr_size);
account_t *search_record(char *acc_number, int arr_size);
account_t *update_record(char *acc_number, int arr_size);
account_t *create_admin_account(int arr_size);

#endif