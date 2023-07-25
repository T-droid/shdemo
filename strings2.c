#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: string to concatenate to dest
 * Return: the dest pointer
 */
char *_strcat(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}
char* _strtok(char* s, char* delm){
    char W[100];
    int i = 0, k = 0, j = 0;
    char *ptr;
    static char *Iterator;
    char *tok = NULL;
    ptr = s;

    if (s == NULL){
        s = Iterator;
    }
    while (s[i] != '\0'){
        j = 0;
        while (delm[j] != '\0'){
            if (s[i] != delm[j])
                W[k] = s[i];
            else goto It;
            j++;
        }
        ptr++;
        i++;
        k++;
    }
It:
    W[i] = 0;
    Iterator = ++ptr;
    tok = W;
    return tok;
}
