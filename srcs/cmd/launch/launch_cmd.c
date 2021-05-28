/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:10:22 by alafranc          #+#    #+#             */
/*   Updated: 2021/05/26 14:53:37 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	launch_if_is_our_cmd(char *cmd, t_all *a, char **cmd_done,
							int	(**ft_cmd)(t_all *a))
{
	int		i;
	t_env	*new_status;

	i = -1;
	while (cmd_done[++i])
	{
		if (!ft_strcmp(cmd, cmd_done[i]))
		{
			if (ft_cmd[i] != NULL)
				a->status_cmd = ft_cmd[i](a);
			else
				ft_printf(1, "not done yet\n");
			return (1);
		}
	}
	return (0);
}

void	ft_exit_status_cmd(t_all *a)
{
	t_env	*new_status;

	new_status = ft_keyshr(a->env, "?");
	if (!new_status)
	{
		new_status = ft_lstnew_env("?", NULL, status_none);
		ft_lstadd_back_env(&a->env, new_status);
		ft_lstadd_front(&a->gc, ft_lstnew(new_status));
	}
	new_status->content = ft_itoa(a->status_cmd);
	ft_lstadd_front(&a->gc, ft_lstnew(new_status->content));
	a->status_cmd = 0;
}

void	ft_launch_cmd(char *cmd, t_all *a, char *name_prg)
{
	char	**cmd_done;
	int		(**ft_cmd)(t_all *a);

	if (!cmd)
		return ;
	cmd_done = list_cmd_done(&a->gc);
	ft_cmd = init_array_instruction_function(&a->gc);
	if (!launch_if_is_our_cmd(cmd, a, cmd_done, ft_cmd))
		ft_launch_execve(cmd, a, name_prg);
}