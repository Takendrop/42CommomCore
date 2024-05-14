/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:05:24 by jwozniak          #+#    #+#             */
/*   Updated: 2024/04/07 17:05:25 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*init_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->data = data;
	new_node->index = 0;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*init_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (new_stack == NULL)
		return (NULL);
	new_stack->size = 0;
	new_stack->head = NULL;
	new_stack->tail = NULL;
	return (new_stack);
}

void	add_back(t_stack *stack, t_node *node)
{
	if (stack->head == NULL)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		node->next = NULL;
		node->prev = stack->tail;
		stack->tail->next = node;
		stack->tail = node;
	}
	stack->size++;
}

void	put_index(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;
	int		index;

	current = stack->head;
	while (current != NULL)
	{
		tmp = stack->head;
		index = 0;
		while (tmp != NULL)
		{
			if (tmp->data < current->data)
			{
				index++;
			}
			tmp = tmp->next;
		}
		current->index = index;
		current = current->next;
	}
}
