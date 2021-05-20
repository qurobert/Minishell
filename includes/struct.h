/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:10:33 by qurobert          #+#    #+#             */
/*   Updated: 2021/05/20 09:38:13 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "exec.h"

typedef enum		e_status
{
	status_env,
	status_export,
	none
}					t_status;

typedef struct		s_env
typedef enum	e_error
{
	cmd_not_found
}				t_error;



typedef struct s_env

{
	char			*key;
	char			*content;
	t_status		status;
	struct s_env	*next;
}					t_env;

typedef	struct		s_tree
{	
	struct s_btree	*left;
	struct s_btree	*right;
	t_type_enum		type;
	t_type_union	exec;
}					t_tree;

typedef struct s_all
{
	t_env	*env;
	t_list	*gc;
}				t_all;

#endif
