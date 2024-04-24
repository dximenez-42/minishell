
#include "includes/cleaners.h"

void	clear_env_list(t_content cnt, t_type type)
{
	const t_env_var *var = cnt.oth;

	if (type != OTHER)
		return ;
	if (!var)
		return ;
	free(var->name);
	free(var->value);
	free((void *)var);
}