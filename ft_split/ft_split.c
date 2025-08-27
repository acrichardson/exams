// #include "stdlib.h"
// #include "unistd.h"
// #include <stdio.h>

// int	count_words(char *str)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i] != '\0')
// 	{
// 		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
// 			i++;
// 		if (str[i] != '\0')
// 			count++;
// 		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t'
// 			&& str[i] != '\n')
// 			i++;
// 	}
// 	return (count);
// }

// void	copy_words(char *tab, char *str, int start, int end)
// {
// 	int	j;

// 	j = 0;
// 	while (start < end)
// 		tab[j++] = str[start++];
// 	tab[j] = '\0';
// }

// int	find_next_word(char *str, int *start, int *end)
// {
// 	int	i;

// 	i = *end;
// 	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
// 			|| str[i] == '\n'))
// 		i++;
// 	*start = i;
// 	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
// 		i++;
// 	*end = i;
// 	return (*start < *end);
// }

// int	ft_fill_words(char **tab, char *str)
// {
// 	int	i;
// 	int	word;
// 	int	start;
// 	int	end;

// 	i = 0;
// 	word = 0;
// 	start = 0;
// 	end = 0;
// 	while (find_next_word(str, &start, &end))
// 	{
// 		tab[word] = malloc((end - start + 1) * sizeof(char));
// 		if (tab[word] == NULL)
// 		{
// 			i = 0;
// 			while (i < word)
// 				free(tab[i++]);
// 			free(tab);
// 			return (0);
// 		}
// 		copy_words(tab[word], str, start, end);
// 		word++;
// 	}
// 	tab[word] = NULL;
// 	return (1);
// }

// char	**ft_split(char *str)
// {
// 	char	**out;
// 	int		size;

// 	size = count_words(str);
// 	out = malloc((sizeof(char *) * (size + 1)));
// 	if (!out)
// 		return (NULL);
// 	if (!ft_fill_words(out, str))
// 	{
// 		free(out);
// 		return (NULL);
// 	}
// 	return (out);
// }


// int main()
// {
//     char *string;
//     char **string_array;
//     int i;

//     i = 0;
//     string  = "Hello Puta";

//     string_array = ft_split(string);

//     while (string_array[i])
//     {
//         printf("string_array[i] = %s\n", string_array[i]);
//         i++;
//     }
//     return (0);
// }

// both work fine


#include <stdlib.h> // For malloc
#include <stdio.h>

// Helper function to check if a character is a delimiter (whitespace)
int	is_delimiter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

// Count words (same logic as before, but using the helper function)
int	count_words(char *str)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0; // Flag: 0 if we are not in a word, 1 if we are in a word
	while (*str)
	{
		// If we are NOT in a word and the current char is NOT a delimiter...
		if (!in_word && !is_delimiter(*str))
		{
			in_word = 1; // ...we just entered a word.
			count++;     // ...so we count it.
		}
		// If we ARE in a word and the current char IS a delimiter...
		else if (in_word && is_delimiter(*str))
		{
			in_word = 0; // ...we just left a word.
		}
		str++; // Move to the next character
	}
	return (count);
}

// The main split function
char	**ft_split(char *str)
{
	char	**result;
	int		word_len;
	int		i;
	int		j;

	// 1. Allocate the main array of pointers (+1 for the final NULL)
	result = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!result)
		return (NULL);

	i = 0; 
	while (*str)
	{
		// 2a. Skip any delimiters at the beginning
		while (is_delimiter(*str))
			str++;
		// 2b. If we're at the end of the string, break out of the loop
		if (*str == '\0')
			break;

		// 2c. Find the length of the current word
		// We just point 'j' to the start of the word and walk until we hit a delimiter or end of string.
		j = 0;
		while (str[j] && !is_delimiter(str[j]))
			j++;
		word_len = j; // The length of the word we found

		// 2d. Allocate memory for this word (+1 for the null terminator '\0')
		result[i] = malloc(sizeof(char) * (word_len + 1));
		// 2e. Copy the word into the newly allocated space
		
		j = 0;
		while (j < word_len)
		{
			result[i][j] = str[j];
			j++;
		}
		result[i][j] = '\0'; // Null-terminate the new string
		i++; // Move to the next slot in the result array

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