#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * wordsCount - Count the nulber of words in a string
 *
 * @str: String to check
 * @separators: Separators
 *
 * Return: The number of words in the string
 */

int wordsCount(char *str, const char *separators)
{
	int count = 0, i, j;

	if (str == NULL)
		return (0);

	for (i = 0; str[i] != '\0'; i++)
		for (j = 0; separators[j] != '\0'; j++)
			if (str[i] == separators[j])
				count++;

	return (count);
}


/**
 * strsplit - Split a string into an array of words
 *
 * @str: String to split
 *
 * Return: The array of words
 */

char **strsplit(char *str)
{
	const char *separators = ",.- \t\n";
	char **words = malloc(wordsCount(str, separators) * sizeof(char **));
	char *word = strtok(str, separators);
	int i = 0;

	while (word != NULL)
	{
		words[i] = malloc(strlen(word));
		strcpy(words[i], word);
		i++;
		word = strtok(NULL, separators);
	}

	words[i] = NULL;
	return (words);
}


/**
 * main - Check the code
 *
 * Return: Always 0
 */

int main(void)
{
	int i;
	char string[] = "Oui\tvas-y. oui, oui";
	char **words = strsplit(string);
	char *sep = "";

	printf("[");
	for (i = 0; words[i] != NULL; i++)
	{
		printf("%s\"%s\"", sep, words[i]);
		sep = ", ";
		free(words[i]);
	}
	printf("]\n");

	free(words);
	return (0);
}
