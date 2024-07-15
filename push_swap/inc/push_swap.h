/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:39:05 by jwozniak          #+#    #+#             */
/*   Updated: 2024/04/06 19:39:07 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
	int				i;
}	t_stack;

// node
t_node	*init_node(int data);
t_stack	*init_stack(void);
void	add_back(t_stack *stack, t_node *node);
void	put_index(t_stack *stack);

// actions
void	swap(char *str, t_stack *stack);
void	pa(t_stack *stack_dst, t_stack *stack_src);
void	pb(t_stack *stack_dst, t_stack *stack_src);
void	rotate(char *str, t_stack *stack);
void	rrotate(char *str, t_stack *stack);

// sort utils
int		is_sorted(t_stack *stack);
int		is_empty(t_stack *stack);
int		get_ssize(char **ssplit);
int		has_duplicates(int *split, int size);
void	free_stack(t_stack *stack);
void	free_ssplit(char **ssplit);

// sort
void	sort_three(t_stack *stack_a, int max_index);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);

//error
void	put_error(void);
int		is_nbr(char *s);
long	ft_atol(const char *s);

#endif
