#include "Utils.h"

#include <cstdlib>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

/*
 * Set verbose as a global parameter, if it is passed as parameter the dbgprintf
 * function will be activated and the description of the actions will be made.
 */
int verbose = 0;

Utils util;

/*
 */
int main(int argc, char** argv) {
    
    int opt;
    
    /*
     * According to http://en.wikipedia.org/wiki/Getopt
     * getopt is a C library function used to parse command-line options.
     * 
     * A simple and efficient example of use can be found here:
     * http://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
     */
    while ((opt = getopt(argc, argv, "v")) != -1) {
        switch (opt) {
        case 'v':
            verbose = 1;
            break;
        default: /* 'h' */
            util.usage(argv[0]);
            return 1;
        }
    }

    if (optind != (argc - 2)) {
        fprintf(stderr, "Expected 2 arguments after options\n");
        return 1;
    }
    
    return 0;
}