# Backup script

Backup script to make backups for a certain directory


## Description:

This backup script is made to backup a specified directory to a certain backup directory each time it is modified (checked recursively after a certain time interval) 
The backups have a specifiable limit that when exceeded the oldest backup gets deleted


## Dependencies:

Need to install the makefile in ubuntu

### 1- Open terminal 

if using Windows press (CTRL+ALT+T)

If using Mac press (^ +⌥+T)

### 2- Type in terminal

```bash
$ sudo apt install make -y.
```    

-if Windows press (enter)

-if Mac press (return)

## Executing the program:

### 1- Go to the directory containing the makefile 

```bash
cd <make_path>
```
<make_path> the path of the project from file properties
### 2- Open terminal 

if using Windows press (CTRL+ALT+T)

If using Mac press (^ +⌥+T)

### 3- Type 
```bash
$ make
```
if Windows press (enter)

if Mac press (return)

## Support:

-e-mail: es-omar.mohamed24@alexu.edu.eg
-e-mail: omar.ashoor35@gmail.com
-phone: (+20) 106-335-5050

## Contributing: 

If you need to use different parameters go to the project directory and run the script without the make file 
```bash        
$ cd <project_directory>
$ mkdir -p <backup_directory>
$ chmod u+x script1.sh
$ ./script1.sh <directory> <backup_dir> <interval_in_seconds> <max_backups>
```    
<project_directory> the directory of the script (application)
 
<backup_directory> the directory of the backup files made

<directory> the directory of the directory to be backed up

<interval_in_seconds> the interval between checks  in seconds

<max_backups> the maximum number of backup files to be saved together


## Author and acknowledgement:

### Author:

- name: Omar Walied Mohamed Ashoor

- phone: (+20) 106-335-5050

- email: es-omar.mohamed24@alexu.edu.eg

### Acknowledgement
Thank you for using our product we hope it serves you well.


## License:

[QNAP Store](https://software.qnap.com/)

## Project status:

The project is completely developed

Looking for maintainers
