/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:36:01 by jwozniak          #+#    #+#             */
/*   Updated: 2024/04/06 19:36:02 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

void	swap(char *str, t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->head;
	second = stack->head->next;
	stack->head = second;
	first->next = second->next;
	first->prev = first;
	second->next = first;
	second->prev = NULL;
	if (stack->tail == second)
		stack->tail = first;
	ft_putendl_fd(str, 1);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (stack_b->size == 0)
		return ;
	tmp = stack_b->head;
	stack_b->head = stack_b->head->next;
	if (stack_b->head == NULL)
		stack_b->tail = NULL;
	else
		stack_b->head->prev = NULL;
	if (stack_a->size == 0)
	{
		tmp->next = NULL;
		stack_a->head = tmp;
		stack_a->tail = tmp;
	}
	else
	{
		tmp->next = stack_a->head;
		stack_a->head->prev = tmp;
		stack_a->head = tmp;
	}
	stack_a->size++;
	stack_b->size--;
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (stack_a->size == 0)
		return ;
	tmp = stack_a->head;
	stack_a->head = stack_a->head->next;
	if (stack_a->head == NULL)
		stack_a->tail = NULL;
	else
		stack_a->head->prev = NULL;
	if (stack_b->size == 0)
	{
		tmp->next = NULL;
		stack_b->head = tmp;
		stack_b->tail = tmp;
	}
	else
	{
		tmp->next = stack_b->head;
		stack_b->head->prev = tmp;
		stack_b->head = tmp;
	}
	stack_a->size--;
	stack_b->size++;
	ft_putendl_fd("pb", 1);
}

void	rotate(char *str, t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	stack->tail->next = tmp;
	tmp->next = NULL;
	tmp->prev = stack->tail;
	stack->tail = tmp;
	ft_putendl_fd(str, 1);
}

void	rrotate(char *str, t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	tmp->prev = NULL;
	tmp->next = stack->head;
	stack->head->prev = tmp;
	stack->head = tmp;
	ft_putendl_fd(str, 1);
}
