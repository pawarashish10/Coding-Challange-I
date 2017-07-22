#include "abbr.h"
#include "string.h"

char **strsplit(const char* str, const char* delim, size_t* numtokens) 
{
	char *string = strdup(str);
	unsigned int tokens_alloc = 1;
	unsigned int tokens_used = 0;
	char **token_arr = calloc(tokens_alloc, sizeof(char*));
	char *token, *strtok_ctx;
	for (token = strtok(string, delim, &strtok_ctx);
	token != NULL;
	token = strtok(NULL, delim, &strtok_ctx)) 
	{

		if (tokens_used == tokens_alloc) 
		{
			tokens_alloc *= 2;
			token_arr = realloc(token_arr, tokens_alloc * sizeof(char*));
		}
		token_arr[tokens_used++] = strdup(token);
	}

	if (tokens_used == 0) 
	{
		free(token_arr);
		token_arr = NULL;
	}
	else 
	{
		token_arr = realloc(token_arr, tokens_used * sizeof(char*));
	}
	*numtokens = tokens_used;
	free(string);

	return token_arr;
}

void abbreviate_string(const char * str, char * str_abbr, size_t str_abbr_len, dictionary_t * dictionary, size_t dictionary_len)
{
    /* implement this */
	unsigned int i,j, flag = 0;

	char **tokens;
	size_t numtokens;
	//str_abbr = NULL;
	tokens = strsplit(str, ", \t\n", &numtokens);
	for (size_t i = 0; i < numtokens; i++) 
	{
			//printf("    token: \"%s\"\n", tokens[i]);
			for (j = 0; j < dictionary_len; j++)
			{
				if (strcmp(tokens[i], dictionary[j].full) == 0)
				{
					strcat(str_abbr, dictionary[j].abbr);
					strcat(str_abbr, " ");
					flag = 1;
				}
			}
			if (flag == 0)
			{
				strcat(str_abbr, tokens[i]);
				strcat(str_abbr, " ");
			}
			free(tokens[i]);
			flag = 0;
	}
	
}
