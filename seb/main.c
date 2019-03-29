#include <stdio.h>
#include <stdlib.h>

#include "checker.h"
#include "cli_parse.h"

/**
 * Run the checker on all the element configured on the CLI
 */
int main(int argc, char** argv) {
    struct options options;
    int i;

    cli_parse(&options, argc-1, argv+1);

    for (i = 0; i < options.nbr_options; ++i) {
        char* string = options.strings[i];
        printf("%s: %s\n", string, checker(string) ? "OK" : "KO");
    }

    return EXIT_SUCCESS;
}
