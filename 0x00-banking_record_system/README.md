# Bank Record System

## table of content

- [Project Overview](#Project-Overview)
- [Installition](#Installition)
- [Operations](#Operations)
- [Technologies](#Technologies-Used)
- [Author](#Author)
- [License](#License)

### Project Overview

This project is a very simple bank record system working with file system to save records,
The project was built for learning objective only

### Installition

to be able to rub this project either in linux or windos you need gcc compliler to compile c files

- for Linux users
	to be able to run this project you need to run it using installers.sh for linux users
	```
	installers.sh
	```
	* Note: if you get permission denied errors then write sudo before bash script
	```
	sudo installers.sh
	```
	Now the script is installed and you can run it using bank_account command 
	```
	bank_account
	```

- for windows users
	first you need to create new file called data.csv in the project directory
	then run the following command
	```
	gcc *.c -o bank_account
	```
	Now the script is installed and you can run it using bank_account command 
	```
	bank_account.exe
	```

### Operations

you can perform number of operations after installing this script, these operations are:

- add bank record
- delete bank record
- update bank record
- search bank record

### Technologies Used

This script was built only using C programming language and bash installer for linux users

### Author

Ammar Massoud

### License

This project is licensed under MIT License
