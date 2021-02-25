#ifndef IO_CC
#define IO_CC

/* Standard library headers */
#include <sys/stat.h>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
/* Internal headers */
#include "io/io.hpp"

/**************************** check directory existence ****************************/
// code from https://stackoverflow.com/questions/6252060/check-folder-path
inline bool is_directory_exist(const char* dirname) {
    #ifdef UNIX

        if( access(dirname, 0) == 0 ) {
            struct stat status;
            stat( dirname, &status );
            if( status.st_mode & S_IFDIR )
                return true;
        }
        // if any condition fails
        return false;

    #elif defined(WINDOWS)

        if( _access(dirname, 0) == 0 ) {
            struct stat status;
            stat( dirname, &status );
            if( status.st_mode & S_IFDIR )
                return true;
        }
        // if any condition fails
        return false;

    #endif
}

void check_and_create_directory(const char* dirname) {
    if ( !is_directory_exist(dirname) ) {
        #ifdef UNIX
            mkdir(dirname, 0777);
        #elif defined(WINDOWS)
            CreateDirectory(dirname, NULL);
        #endif
    }
}

/**************************** check file existence ****************************/
inline bool is_file_exist(const char* fname) {
    struct stat buffer;
    return (stat(fname, &buffer) == 0);
}

void check_file_exist(const char* fname) {
    if (!is_file_exist(fname)) {
        printf("FileError: file '%s' is not found\n", fname);
        exit(1);
    }
}


/**************************** Add '/' to path name ****************************/
char * normalise_directory_name (char * directory_name) {
    char end_char = directory_name[strlen(directory_name)-1];
    if (!(end_char == '/'||end_char == '\\')){
        strncat (directory_name, "/", 1);
    }
    return directory_name;
}

#endif
