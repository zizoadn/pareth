#include <stdio.h>
#include <string.h>

#include "checker.h"
#include "pile.h"

/**
 * Configure the supported element here
 */
static char OPENER[3] = "([{";
static char CLOSER[3] = ")]}";

/**
 * Main algorithm: for the input string, check the state of the accolade/
 * parenthesis, etc.
 */
int checker(char* string) {
    struct stack* stack = create_stack("checker");
    int lstring = strlen(string);
    char* ocu;   /* Occurence */
    int res = 1; /* Final result */

    for (int i = 0; i < lstring; ++i) {
        /* Is the current char a supported opening element? */
        ocu = strchr(OPENER, string[i]);

        if (ocu != NULL) {
            /* If yes, store the corresponding expected closing element
               on the stack */
            push(stack, ocu-OPENER+CLOSER);

        } else {
            /* If no, check if this a supported closing element */
            ocu = strchr(CLOSER, string[i]);

            if (ocu != NULL) { /* It is a closing element */
                if (not_empty(stack)) { /* Stack is not empty is it the same? */
                    char* expected = (char*) pop(stack);
                    if (expected[0] != ocu[0]) {
                        /* Not the same error and break, no need to go further */
                        fprintf(
                            stderr,
                            "%s: erreur in char %d: found %c expected %c.\n",
                            string,
                            i,
                            ocu[0],
                            expected[0]
                        );
                        break;
                    }

                } else {
                    /* Stack empty, not normal, we have a closer element, error */
                    fprintf(
                        stderr,
                        "%s: erreur in char %d: found %c nothing expected.\n",
                        string,
                        i,
                        ocu[0]
                    );
                    break;
                }
            } /* It's neither an opening or a closing element, ignore the char */
        }
    }

    if (res == 1 && not_empty(stack)) {
        /* At the end still an element on the stack? Not normal, error */
        fprintf(stderr, "%s: missing chars to close all open symbols.\n", string);
        res = 0;
    }

    /* Let's clean the memory */
    destroy_stack(stack);

    return res;
}
