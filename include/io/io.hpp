#ifndef IO_H
#define IO_H

#include <string>

/**************************** check dir/file existence and dir/file names ****************************/
/*
Return true if the given directory exists. Otherwise, return false.
*/
inline bool is_directory_exist(const char* dirname);

/*
Check the existence of the directory and create it if it does not exists. If it does, then do nothing.
*/
void check_and_create_directory(const char* dirname);

/*
Return true if the given file exists. Otherwise, return false.
*/
inline bool is_file_exist(const char* fname);

/*
Check if the given file exists. If it does not, then throw an error. Otherwise, do nothing.
*/
void check_file_exist(const char* fname);


char * normalise_directory_name (char * directory_name);
/*
 Checks for presence of backslash on output directory and adds one if not present.
 Input:
 * directory_name as specified by user

 Output:
 * directory_name with added '/' symbol if it is not already present
*/

#endif
