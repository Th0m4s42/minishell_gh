#include <minishell.h>

void add_in_lex_order(t_env **first, t_env *new_var) {
    t_env *tmp;
    t_env *current_var;
    char *var_name;

    // if (first == NULL || new_var == NULL) {
    //     return;
    // }

    var_name = new_var->name;


    // if (*first == NULL || ft_strncmp(var_name, (*first)->name, ft_strlen(var_name)) < 0) {
    if (*first == NULL || ft_strncmp(var_name, (*first)->name, INT_MAX) < 0)
	{
        new_var->next = *first;
        *first = new_var;
        return;
    }
    tmp = *first;
    current_var = (*first)->next;
    // while (current_var != NULL && ft_strncmp(var_name, current_var->name, ft_strlen(var_name)) >= 0) {
    while (current_var != NULL && ft_strncmp(var_name, current_var->name, INT_MAX) >= 0)
	{
        tmp = current_var;
        current_var = current_var->next;
    }
	if (!current_var)
		tmp->next = new_var;
	else
	{
		tmp->next = new_var;
	new_var->next = current_var;
	}

}

// void	add_in_lex_order(t_env *first, t_env *new_var)
// {
// 	t_env	*tmp;
// 	t_env	*current_var;
// 	char	*var_name;

// 	tmp = first;
// 	current_var = first;
// 	var_name = new_var->name;
// 	if (first == NULL)
// 		add_back(&first, new_var);
// 	while (current_var != NULL && ft_strncmp(var_name, current_var->name, ft_strlen(var_name)) > 0)
// 	{
// 		tmp = current_var;
// 		current_var = current_var->next;
// 	}
// 	if (current_var == NULL)
// 		current_var = new_var;
// 	else
// 	{
// 		tmp->next = new_var;
// 		new_var->next = current_var;
// 	}		
// }

void	ft_exp_displ(t_env *env)
{
	t_env	*var;

	var = env;
	fprintf(stderr, "uhhh%s= \n", var->name);
	while (var)
	{
		write(1, "declare -x ", 11);
		ft_putstr_fd(var->name, STDOUT);
		if (var->value)
		{
			write(1, "=", 1);
			write(1, "\"", 1);
			ft_putstr_fd(var->value, STDOUT);
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		var = var->next;
	}
}

void	ft_export(char **cmd, t_shell *shell)
{
	// t_env	*env_var;
	// t_env	*exp_var;
	t_env	*new_var;
	char	*tmp;
	int		i;

	new_var = NULL;
	tmp = NULL;
	i = 1;
	if (!cmd[i])
		ft_exp_displ(shell->fallback_env);
	else
	{
		while(cmd[i])
		{
			// if (!tmp || ft_strlen(cmd[i] - ft_strlen(tmp) <))
		// fprintf(stderr, "cmd[i] = %s\n",cmd[i]);
			tmp = ft_strchr(cmd[i], '=');
			if (tmp && ft_strlen(tmp) == ft_strlen(cmd[i]))
			{
				ft_putstr_fd("minishell: export: `", STDERR);
				ft_putstr_fd(cmd[i], STDERR);
				ft_putendl_fd("': not a valid identifier", STDERR);

			}
			else if (ft_strlen(tmp) > 0)
			{
				new_var = new_env_node(ft_substr(cmd[i], 0, (ft_strlen(cmd[i]) - ft_strlen(tmp))), ft_strdup(tmp + 1));
				add_back(&(shell->env), new_var);
				new_var = new_env_node(ft_substr(cmd[i], 0, (ft_strlen(cmd[i]) - ft_strlen(tmp))), ft_strdup(tmp + 1));
				add_in_lex_order(&(shell)->fallback_env, new_var);
			}
			else 
			{
				new_var = new_env_node(ft_strdup(cmd[i]), NULL);
				add_in_lex_order(&(shell)->fallback_env, new_var);
			}
			i++;
			// tmp = NULL;
		}
	}


				
			



}