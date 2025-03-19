#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}


int ft_strlen(const char  *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}
