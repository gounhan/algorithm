#include <stdio.h>
#include <conio.h>

char * read_string_from_console()
{
	char word[50];
	char sentence[1000];

	printf("Type stirng: ");
	gets(word);
	strcpy(sentence, word);
	do {
		printf("Type stirng: ");
		gets(word);
		strcat(sentence, word);
	} while (word[0] != '\0');

	printf("%s", sentence);
	return sentence;
}

char * read_string_from_file(char filename[])
{
	char word[50];
	char sentence[1000];
	FILE *fp = NULL;

	fp = fopen(filename, "r");
	if (fp != NULL)
	{
		fgets(word, 50, fp);
		word[strlen(word) - 1] = '\0';
		strcpy(sentence, word);

		while (!feof(fp))
		{
			fgets(word, 50, fp);
			word[strlen(word) - 1] = '\0';
			strcat(sentence, word);
		}
		fclose(fp);
	}
	printf("%s", sentence);
	return sentence;
}

int main()
{
	//read_string_from_console();
	read_string_from_file("text.txt");

	return 0;
}