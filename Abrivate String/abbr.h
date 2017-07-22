#include <stdlib.h>

typedef struct
{
    const char * full;
    const char * abbr;
} dictionary_t;

/**
 * Abbreviate a given string using a dictionary of acceptable abbreviations.
 *
 * Notes:
 *
 * - Only "whole words" should be abbreviated. That is, if the word "record" can
 *   be abbreviated to "rec", "records" SHOULD NOT be abbreviated to "recs".
 * - A "whole word" is a sequence of alphanumeric characters.
 * - If the abbreviated string will not fit in the destination buffer clamp the
 *   string.
 * - Bonus points for allowing the substitution to be case insensitive, but also
 *   case aware. It should handle three cases, the original word all lower case,
 *   all upper case, or the first letter only being capitalized. Mixed cases can
 *   be handled in any reasonable way.
 *   For example, if the dictionary contains: "record"->"rec":
 *     - "record" should be replaced with "rec"
 *     - "Record" should be replaced with "Rec"
 *     - "RECORD" should be replaced with "REC"
 *     - "ReCord" can be replaced with "rec", "Rec" or "REC"
 *
 * @param str            source string to abbreviate (NULL terminated)
 * @param str_abbr       destination buffer to store abbreviated version of 'str'
 * @param str_abbr_len   length of 'str_abbr' buffer, including NULL terminator
 * @param dictionary     array of acceptable abbreviations
 * @param dictionary_len number of items in dictionary
 */
void abbreviate_string(const char * str, char * str_abbr, size_t str_abbr_len, dictionary_t * dictionary, size_t dictionary_len);
