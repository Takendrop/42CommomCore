/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:43:22 by jwozniak          #+#    #+#             */
/*   Updated: 2024/04/06 19:43:23 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

void	sort_three(t_stack *stack_a, int max_index)
{
	if (stack_a->size != 3)
		return ;
	if (stack_a->tail->index != max_index)
	{
		if (stack_a->head->index == max_index)
			rotate("ra", stack_a);
		else
			rrotate("rra", stack_a);
	}
	if (stack_a->head->index > stack_a->head->next->index)
		swap("sa", stack_a);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	max_index;

	if (!(stack_a->size == 4 || stack_a->size == 5))
		return ;
	max_index = stack_a->size - 1;
	while (stack_a->size > 3)
	{
		if (stack_a->head->index == 0 || stack_a->head->index == 1)
			pb(stack_a, stack_b);
		else
			rotate("ra", stack_a);
	}
	sort_three(stack_a, max_index);
	if (stack_b->size == 2)
		if (stack_b->head->index > stack_b->head->next->index)
			swap("sb", stack_b);
	while (stack_b->size != 0)
		pa(stack_a, stack_b);
	if (stack_a->head->index > stack_a->head->next->index)
		swap("sa", stack_a);
}

static int	set_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while (size > 1)
	{
		size /= 2;
		max_bits++;
	}
	return (max_bits);
}

static void	sort_b(t_stack *stack_a, t_stack *stack_b, int max_bits, int i)
{
	int		size;
	t_node	*current;

	size = stack_b->size;
	while (size-- && i <= max_bits)
	{
		current = stack_b->head;
		if (((current->index >> i) & 1) == 1)
			rrotate("rrb", stack_b);
		else
			pa(stack_a, stack_b);
	}
	while (stack_b->size)
		pa(stack_a, stack_b);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		size;
	int		max_bits;
	t_node	*current;
	t_node	*next;

	size = stack_a->size;
	max_bits = set_max_bits(size);
	stack_a->i = 0;
	while (stack_a->i <= max_bits)
	{
		size = stack_a->size;
		current = stack_a->head;
		while (size-- && current != NULL && !is_sorted(stack_a))
		{
			next = current->next;
			if (((current->index >> stack_a->i) & 1) == 1)
				rotate("ra", stack_a);
			else
				pb(stack_a, stack_b);
			current = next;
		}
		sort_b(stack_a, stack_b, max_bits, stack_a->i++);
	}
	while (stack_b->size)
		pa(stack_a, stack_b);
}
