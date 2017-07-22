#include <string.h>
#include <stdio.h>

#include "abbr.h"

/* Sample Test Driver */
int main(void)
{
    /* Sample Dictionary */
    dictionary_t dictionary[] =
    {
        {"record", "rec"},
        {"maximum", "max"},
        {"minimum", "min"},
        {"number", "no"}
    };

    char str[100];
    char str_abbr[100];
	str_abbr[0] = '\0';
    strcpy(str, "maximum record rate is:");
	//printf("\n first  %s \n",str_abbr);
    abbreviate_string(str, str_abbr, sizeof(str_abbr), dictionary, sizeof(dictionary) / sizeof(dictionary[0]));

    printf("%s -> %s\n", str, str_abbr);

    return 0;
}
