#include "cli_parse.h"

/**
 * Simple naive way to parse the CLI. Putting this code here allow us to
 * use more complex cli options in the future (for example we could configure
 * the supported element we want to test).
 */
void cli_parse(struct options* options, int argc, char** argv) {
    options->strings = argv;
    options->nbr_options = argc;

}
