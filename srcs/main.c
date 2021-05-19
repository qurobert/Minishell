
#include "minishell.h"

void	read_command_line(t_env **env, t_list **gc)
{
	char	*line;

	(void)env;
	line = NULL;
	ft_printf(1, RED "➜ " BLU "minishell " YEL "✗ " RESET);
	while (get_next_line(0, &line))
	{
		// ft_parse_command_line(gc, line);
		ft_printf(1, RED "➜ " BLU "minishell " YEL "✗ " RESET);
		free(line);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_all *a;

	a = malloc(sizeof(t_all));
	a->gc = NULL;
	ft_lstadd_front(&a->gc, ft_lstnew(a));
	a->env = parse_env(envp, &a->gc);
	ft_printf(1, "%s\n", a->env->key);
	// print_banner();
    // read_command_line(&env, &gc);
	ft_lauch_cmd(NULL, a);
	ft_lstclear(&a->gc, free);
	return (0);
}
