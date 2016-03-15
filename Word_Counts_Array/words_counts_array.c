#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define BUF_LEN 100
#define STR_LEN 1000
#define MAX_WORD 200
#define WORD_LEN 20
int main(void)
{
	char delimiters[] = ".\n,:;\"!? ";
	char buf[BUF_LEN];
	char str[STR_LEN];
	str[0] = '\0';
	printf("Enter a prose less than 200 words. Ending entering by an empty line.\n");
	while (true)
	{
		if (!fgets(buf, BUF_LEN, stdin))
		{
			printf("Error Reading!\n");
			return 1;
		}
		if (buf[0] == '\n') break;
		if (strcat_s(str, sizeof(str), buf))
		{
			printf("Error reading!\n");
			return 1;
		}
	}
	bool new_word = true;
	char word[MAX_WORD][WORD_LEN] = {""};
	int nwords[MAX_WORD] = { 0 };
	char *ptr = NULL;
	char *pword = strtok_s(str, delimiters, &ptr);
	int word_count = 0;
	if (!pword)
	{
		printf("No Word Found!\n");
		return 1;
	}
	while (pword)
	{
		for (int i = 0; i < word_count; i++)
		{
			if (strcmp(word[i], pword) == 0)
			{
				++nwords[i];
				new_word = false;
				break;
			}
		}
		if (new_word)
		{
			strcpy_s(word[word_count], WORD_LEN, pword);
			nwords[word_count++] = 1;

		}
		else
			new_word = true;
		pword = strtok_s(NULL, delimiters, &ptr);
	}
	for (int i = 0; i < word_count; i++)
	{
		printf("%5s  %d   ", word[i], nwords[i]);
		if ((i + 1)% 5 == 0)
			printf("\n");
	}
	
	






	return 0;
}