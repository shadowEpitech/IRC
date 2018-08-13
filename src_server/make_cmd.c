/*
** EPITECH PROJECT, 2018
** By Shadow
** File description:
** make_cmd
*/

#include "my.h"

int	is_maj(char *line)
{
	int	i;
	
	for (i = 0; line[i]; i++)
	{
		if (isalpha(line[i]) != 0)
		{
			if (line[i] < 65 || line[i] > 90)
				return (1);
		}
	}
	return (0);
}

int	is_a_cmd(char *line)
{
	char **tab;
	tab = my_str_to_wordtab(line, " \r");
	if (is_maj(tab[0]) == 0 || tab[0][0] == '/')
		return (0);
	return (1);
}

char	*make_cmd(char **tab, int pos)
{
	int	i;
	int	total_len;
	char	*cmd;

	for (i = pos; tab[i]; i++);
	total_len = i;
	for (i = pos; tab[i]; i++)
		total_len += strlen(tab[i]);
	cmd = malloc(sizeof(char) * total_len + 1);
	cmd = strcpy(cmd, tab[pos]);
	for (i = pos + 1; tab[i]; i++)
	{
		cmd = strcat(cmd, " ");
		cmd = strcat(cmd, tab[i]);
	}
	return (cmd);
}
