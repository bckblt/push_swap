/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:02:27 by bakarabu          #+#    #+#             */
/*   Updated: 2025/03/22 12:40:26 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char *a, char b)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	if (a[0] == '\0')
		return (0);
	while (a[i] != '\0')
	{
		while (a[i] == b && a[i] != '\0')
			i++;
		if (a[i] != '\0')
		{
			word++;
			while (a[i] != b && a[i] != '\0')
				i++;
		}
	}
	return (word);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= s_len)
	{
		a = (char *)malloc(sizeof(char) * 1);
		if (!a)
			return (0);
		a[0] = '\0';
		return (a);
	}
	if (len > s_len - start)
		len = s_len - start;
	a = malloc((len + 1) * sizeof(char));
	if (!a)
		return (0);
	while (i < len)
		a[i++] = s[start++];
	a[i] = '\0';
	return (a);
}

char	**ft_split(char *s, char c)
{
	char	**result;
	int		i;
	size_t	start;
	int		re;
	size_t	end;

	i = 0;
	re = 0;
	result = malloc (sizeof(char *) * (count_word(s, c) + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		if (end > start)
			result[re++] = ft_substr(s, start, end - start);
	}
	free(s);
	result[re] = (NULL);
	return (result);
}

void	ft_wrerror(t_list **stack_a, t_list **stack_b)
{
	write(2, "Error\n", 6);
	if (stack_a || stack_b)
		ft_freed(stack_a, stack_b);
	exit (1);
}

void	write_error(int ac, char **av)
{
	if (ac == 1 || !av[1])
		exit (1);
	if (av[1][0] == '\0')
		ft_wrerror (NULL, NULL);
	if (av[1][0] == ' ' && av[1][1] == '\0')
	{
		write(1, "Error\n", 6);
		exit (1);
	}
}
