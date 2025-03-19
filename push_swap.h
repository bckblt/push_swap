#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	long data;
	int index;
	struct s_list *next;
}	t_list;

int ft_maxmin(t_list **stack);
void	ft_freed(t_list **stack_a , t_list **stack_b);
char	*ft_makeone(char **av);
int ft_intchk(char *str);
char	**ft_split(char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int ft_strlen(const char *str);
long	ft_atoi(const char *str);
t_list **ft_list_doldur(t_list **stack, char **str);
void stack_yazdir(t_list **stack);
int ft_sameint(t_list **list);
void ft_actions(t_list **stack_a, t_list **stack_b, char *actions);
void swap_stack(t_list **stack);
void push_stack(t_list **stack_first, t_list **stack_second);
void rotate_stack(t_list **stack);
void reverse_rotate(t_list **stack);
int	ft_strcmp(char *s1, char *s2);
void    ft_sort(t_list **stack_a, t_list **stack_b, int size);
int index_cfg(t_list **stack);
int ft_serial(t_list **stack_a);
int ft_revserial(t_list **stack_a);
void ft_radix_sort(t_list **stack_a, t_list **stack_b, int size);
void    ft_short_sort(t_list **stack_a, t_list **stack_b, int max);
int ft_strlen(const char  *str);

#endif