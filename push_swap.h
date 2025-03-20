/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:02:17 by bakarabu          #+#    #+#             */
/*   Updated: 2025/03/20 19:14:18 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	long			data;
	int				index;
	struct s_list	*next;
}	t_list;

int		error_ft(char *str);
int		ft_maxmin(t_list **stack);
int		ft_intchk(char *str);
int		ft_strlen(const char *str);
int		ft_sameint(t_list **list);
int		ft_strcmp(char *s1, char *s2);
int		index_cfg(t_list **stack);
int		ft_serial(t_list **stack_a);
int		ft_revserial(t_list **stack_a);
int		ft_strlen(const char *str);
long	ft_atoi(const char *str);
char	*ft_makeone(char **av);
char	**ft_split(char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_freed(t_list **stack_a, t_list **stack_b);
void	stack_yazdir(t_list **stack);
void	ft_actions(t_list **stack_a, t_list **stack_b, char *actions);
void	swap_stack(t_list **stack);
void	push_stack(t_list **stack_first, t_list **stack_second);
void	rotate_stack(t_list **stack);
void	reverse_rotate(t_list **stack);
void	ft_sort(t_list **stack_a, t_list **stack_b, int size);
void	ft_radix_sort(t_list **stack_a, t_list **stack_b, int size);
void	ft_short_sort(t_list **stack_a, t_list **stack_b, int max);
void	split_freed(char **split_arr);
t_list	**ft_list_doldur(t_list **stack, char **str);

#endif
