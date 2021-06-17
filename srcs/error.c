/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:50:43 by alafranc          #+#    #+#             */
/*   Updated: 2021/06/17 13:11:48 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cmd_not_found(t_all *a, char *cmd)
{
	a->status_cmd = 127;
	ft_printf(2, "minichiale: %s: %s\n", cmd, "command not found");
}

void	ft_no_such_file(t_all *a, char *cmd)
{
	a->status_cmd = 1;
	ft_printf(1, "minichiale: %s: %s\n", cmd, strerror(2));
}

void	ft_error_is_a_directory(t_all *a, char *cmd)
{
	a->status_cmd = 126;
	ft_printf(1, "minichiale: %s: %s\n", cmd, "is a directory");
}

void	ft_error_msg(char *msg_error, t_list *gc)
{
	ft_printf(2, "Error:\n%s\n", msg_error);
	exit(EXIT_FAILURE);
	ft_lstclear(&gc, free);
}
