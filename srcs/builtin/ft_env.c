#include <minishell.h>

void	ft_env(t_env *env)
{
	t_env	*var;

	var = env;
	// fprintf(stderr, "uhhh\n");
	while (var)
	{
		// ft_printf("%s=",var->name);
		ft_putstr_fd(var->name, STDOUT);
		write(1, "=", 1);
		if (var->value)
			ft_putstr_fd(var->value, STDOUT);
		write(1, "\n", 1);
		var = var->next;
	}
}