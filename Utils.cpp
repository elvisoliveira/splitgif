#include <cstdio>

#include "Utils.h"

/*
 * Fires the usage instructions print.
 */
void Utils::usage(const char * argv0)
{
    fprintf(stderr, "Usage: %s [-v] input.gif output_base\n", argv0);
}