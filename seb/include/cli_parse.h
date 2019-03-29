#ifndef _CLI_PARSE
#define _CLI_PARSE

/**
 * Define CLI the options of the tools
 */
struct options {
    char** strings;
    int nbr_options;
};

/**
 * Parse CLI and return the result in the options struct
 */
void cli_parse(struct options* options, int argc, char** argv);

#endif