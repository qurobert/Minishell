/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:08:59 by alafranc          #+#    #+#             */
/*   Updated: 2021/05/30 21:18:10 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*delete_char(int index_char, char *str, t_list *gc)
{
	int		i;
	int		j;
	char	*new_str;

	if (!str)
		return (NULL);
	new_str = malloc_gc(&gc, sizeof(char) * ft_strlen(str));
	i = -1;
	j = -1;
	while (str[++i])
		if (i != index_char)
			new_str[++j] = str[i];
	new_str[++j] = '\0';
	return (new_str);
}

void	ft_delete_line_to_cursor(t_all *a, int *cursor, char **line)
{
	while (*cursor > 0)
		ft_backspace(a, cursor, line);
}

void	ft_delete_line(t_all *a, int *cursor, char **line)
{
	if (!line || !(*line))
		return ;
	while ((size_t)(*cursor) < ft_strlen(*line))
		ft_right_arrow(cursor, *line);
	while (*cursor > 0)
		ft_backspace(a, cursor, line);
}


void	ft_backspace(t_all *a, int *cursor, char **line)
{
	int	i;

	if (*cursor == 0 || !line || !(*line))
		return ;
	(*cursor)--;
	tputs(tgetstr("le", NULL), 1, ft_putchar_int);
	tputs(tgetstr("dc", NULL), 1, ft_putchar_int);
	*line = delete_char(*cursor, *line, a->gc);
}