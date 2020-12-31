#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LINE 256
#define WORD 30

void print_lines(char *searchWord)
{
    char line[LINE];
    while (fgets(line, LINE, stdin))
    {
        // run for any line and check if the word is here.
        int i = 0;
        while (line[i] != '\0')
        {
            int j = 0;
            while (searchWord[j] != '\0')
            {
                if (searchWord[j] == line[i + j])
                {
                    j++;
                }
                else
                {
                    break;
                }
            }

            if (strlen(searchWord) == j)
            {
                printf("%s", line);
                break;
            }
            i++;
        }
    }
}
// check if this is a smae word less one letter 0=false, nun 0=true
bool isSame(char *searchWord, char *word)
{
    int j = 0;
    int FLAG = 0;
    if (strlen(searchWord) < strlen(word) - 1)
    {
        return false;
    }
    while (searchWord[j] != '\0')
    {
        if (word[j] == '\0')
            return false;
        if (searchWord[j] != word[j + FLAG])
        {
            if (FLAG != 0)
            {
                return false;
            }
            else
            {
                FLAG = 1;
            }
        }
        j++;
    }
    return true;
}

void print_similar_words(char *searchWord)
{
    char line[LINE];
    char word[WORD];
    while (fgets(line, LINE, stdin))
    {
        int j = 0;
        // creat a word
        while (line[j] != '\0')
        {
            int k = 0;
            while (line[j] != ' ' && line[j] != '\0' && line[j] != '\n')
            {
                word[k] = line[j];
                k++;
                j++;
            }
            word[k] = '\0';
            if (isSame(searchWord, word))
            {
                printf("%s\n", word);
            }
            if (line[j] == '\0')
            {
                break;
            }
            j++;
        }
    }
}

int main()
{
    char letter;
    char searchWord[WORD];
    char line[LINE];

    fgets(line, LINE, stdin);

    int i = 0;
    letter = line[i];
    // reed the word for searching
    while (letter != ' ')
    {
        searchWord[i] = letter;
        i++;
        letter = line[i];
    }

    searchWord[i] = '\0';
    i++;

    // reed the letter for case
    letter = line[i];

    //fits to case a or b
    switch (letter)
    {
    case 'a':
        print_lines(searchWord);
        printf("\n");
        break;

    case 'b':
        print_similar_words(searchWord);
        break;

    default:
        printf("error/n");
        break;
    }
}
