#include "monty.h"

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int getwlen(char *str, char *delims);
int getwcount(char *str, char *delims);
char *getnword(char *str, char *delims);

/**
 * strtow - Separates strings into words.
 *
 * @str: String to separate into word.
 * @delims: Delimitors.
 *
 * Return: 2D array of pointers to each word.
 */
char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wlen, num, index = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = getwcount(str, delims);

	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	while (index < wc)
	{
		wlen = getwlen(str, delims);

		if (is_delim(*str, delims))
			str = getnword(str, delims);
		words[index] = malloc((wlen + 1) * sizeof(char));

		if (words[index] == NULL)
		{
			while (index >= 0)
			{
				index--;
				free(words[index]);
			}
			free(words);

			return (NULL);
		}
		num = 0;

		while (num < wlen)
		{
			words[index][num] = *(str + num);
			num++;
		}
		words[index][num] = '\0'; /* set end of str */
		str = getnword(str, delims);
		index++;
	}
	words[index] = NULL; /* last element is null for iteration */

	return (words);
}

/**
 * is_delim - Checks if stream has delimitor char.
 *
 * @ch: Character in stream.
 * @delims: Pointer to null terminated array of delimitors.
 *
 * Return: 1 (Sucess) 0 (Failure)
 */
int is_delim(char ch, char *delims)
{
	int index = 0;

	while (delims[index])
	{
		if (delims[index] == ch)
			return (1);
		index++;
	}

	return (0);
}

/**
 * getwlen - Gets the word length of the currrent word in str.
 *
 * @str: String source.
 * @delims: Delimitors.
 *
 * Return: Word length of current word.
 */
int getwlen(char *str, char *delims)
{
	int wlen = 0, tmp = 1, index = 0;

	while (*(str + index))
	{
		if (is_delim(str[index], delims))
			tmp = 1;
		else if (tmp)
			wlen++;

		if (wlen > 0 && is_delim(str[index], delims))
			break;
		index++;
	}

	return (wlen);
}

/**
 * getwcount - Gets the number of word counts in a string.
 *
 * @str: String source.
 * @delims: Delimitors.
 *
 * Return: The word count of the string.
 */
int getwcount(char *str, char *delims)
{
	int wc = 0, tmp = 1, index = 0;

	while (*(str + index))
	{
		if (is_delim(str[index], delims))
			tmp = 1;
		else if (tmp)
		{
			tmp = 0;
			wc++;
		}
		index++;
	}

	return (wc);
}

/**
 * getnword - Gets the next word in a string afte the first word.
 *
 * @str: String source.
 * @delims: Delimitors.
 *
 * Return: Pointer to first char of next word.
 */
char *getnword(char *str, char *delims)
{
	int pending = 0, index = 0;

	while (*(str + index))
	{
		if (is_delim(str[index], delims))
			pending = 1;
		else if (pending)
			break;
		index++;
	}

	return (str + index);
}
