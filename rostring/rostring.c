#include <unistd.h>
#include <stdbool.h>

// Function to skip spaces and tabs
int	skip_spaces(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

// Function to find the end of a word
int	find_word_end(char *str, int i)
{
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		i++;
	return (i);
}

// Function to print a word from start to end
void	print_word(char *str, int start, int end)
{
	write(1, &str[start], end - start);
}

void	rostring(char *str)
{
	int	    i;
	int 	start;
	int	    end;
	int 	first_word_start;
	int	    first_word_end;
	bool	first_word_printed;

	i = 0;
	first_word_printed = false;
	
	// 1. Skip leading spaces
	i = skip_spaces(str, i);
	
	// 2. Save the first word
	first_word_start = i;
	first_word_end = find_word_end(str, i);
	i = first_word_end;
	
	// 3. Skip spaces after first word
	i = skip_spaces(str, i);
	
	// 4. Print the rest of the words
	while (str[i] != '\0')
	{
		// Get the start and end of the next word
		start = i;
		end = find_word_end(str, i);
		i = end;
		
		// Print the word followed by a space
		print_word(str, start, end);
		write(1, " ", 1);
		first_word_printed = true;
		
		// Skip any spaces after this word
		i = skip_spaces(str, i);
	}
	
	// 5. Print the first word at the end
	if (first_word_printed) // Only print a space if we printed other words first
		write(1, " ", 1);
	print_word(str, first_word_start, first_word_end);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}