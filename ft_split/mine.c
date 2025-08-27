#include <stdlib.h> // For malloc
#include <stdio.h>

// Helper function to check if a character is a delimiter (whitespace)
int	is_delimiter(char c)
{
    if (c == ' ')
    {
        return (1);
    }
    return (0);
}

// Count words (same logic as before, but using the helper function)
int	count_words(char *str)
{
    int count;
    int i;
    int in_word;

    in_word = 0;
    i = 0;
    count = 0;

    while (str[i])
    {
        while (!in_word && !is_delimiter(str[i]))
        {
            in_word = 1;
            count++;
        }
        while (in_word && is_delimiter(str[i]))
        {
            in_word = 0;
        }
        i++;
    }
    return (count);
// Flag: 0 if we are not in a word, 1 if we are in a word

		// If we are NOT in a word and the current char is NOT a delimiter...

		// If we ARE in a word and the current char IS a delimiter...
// Move to the next character
	
}
// int	count_words(char *str)
// {
// 	int	count;
// 	int	in_word;

// 	count = 0;
// 	in_word = 0; // Flag: 0 if we are not in a word, 1 if we are in a word
// 	while (*str)
// 	{
// 		// If we are NOT in a word and the current char is NOT a delimiter...
// 		while (!in_word && !is_delimiter(*str))
// 		{
// 			in_word = 1; // ...we just entered a word.
// 			count++;     // ...so we count it.
// 		}
// 		// If we ARE in a word and the current char IS a delimiter...
// 		while (in_word && is_delimiter(*str))
// 		{
// 			in_word = 0; // ...we just left a word.
// 		}
// 		str++; // Move to the next character
// 	}
// 	return (count);
// }

// The main split function
char	**ft_split(char *str)
{
    char **result;
    int word_count;
    int word_len;
    int i;

    i = 0;
    word_len = 0;
    result = NULL;
    word_count = count_words(str);

    printf("word_count = %d\n\n", word_count);

    // need for this : count amount of words and thus pointers to be allocated. 
    
	// 1. Allocate the main array of pointers (+1 for the final NULL)
    result = malloc(sizeof(char *) * word_count + 1);

	// 2. Walk through the input string

    while (*str)
{		// 2a. Skip any delimiters at the beginning
    while (is_delimiter(*str))
    {
        str++;
    }

		// 2b. If we're at the end of the string, break out of the loop
    if (*str == '\0')
        break;

		// 2c. Find the length of the current word
        // We just point 'j' to the start of the word and walk until we hit a delimiter or end of string.
        int j = 0;
        while (!is_delimiter(str[j]) && str[j])
        {
            j++;
        }
        // The length of the word we found
        word_len = j;

		// 2d. Allocate memory for this word (+1 for the null terminator '\0')
        // int i = 0;

        result[i] = malloc(sizeof(char *) * (word_len + 1));

		// 2e. Copy the word into the newly allocated space

        j = 0;
        while (j < word_len)
        {
            result[i][j] = str[j];
            j++;
        }

        // Null-terminate the new string
        result[i][j] = '\0';
        // Move to the next slot in the result array
        i++;
        // 2f. Move the main string pointer forward by the word we just processed
    str += word_len;
}

	// 3. Put the final NULL pointer at the end of the array
    result[i] = NULL;

    return (result);
}

int main()
{
    char *string;
    char **string_array;
    int i;

    i = 0;
    string  = "Hello Puta";
    string_array = ft_split(string);

    while (string_array[i])
    {
        printf("string_array[i] = %s\n", string_array[i]);
        i++;
    }
    return (0);
}