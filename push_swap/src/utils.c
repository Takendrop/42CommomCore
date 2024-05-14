/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:43:28 by jwozniak          #+#    #+#             */
/*   Updated: 2024/04/06 19:43:29 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack->size <= 1)
		return (1);
	current = stack->head;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int	get_ssize(char **ssplit)
{
	int	count;

	count = 0;
	if (ssplit == NULL)
		return (0);
	while (*ssplit != NULL)
	{
		count++;
		ssplit++;
	}
	return (count);
}

int	has_duplicates(int *split, int size)
{
	int	i;
	int	j;

	if (split == NULL || size <= 1)
		return (0);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (split[i] == split[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_ssplit(char **ssplit)
{
	int	i;

	if (ssplit == NULL)
		return ;
	i = 0;
	while (ssplit[i] != NULL)
	{
		free(ssplit[i]);
		ssplit[i] = NULL;
		i++;
	}
	free(ssplit);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	if (stack == NULL)
		return ;
	current = stack->head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	free(stack);
}
