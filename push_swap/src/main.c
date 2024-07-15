/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:37:59 by jwozniak          #+#    #+#             */
/*   Updated: 2024/04/07 18:38:00 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/push_swap.h"

static t_stack	*init_and_fill(int *split, int size)
{
	t_stack	*stack_a;
	t_node	*tmp;
	int		i;

	stack_a = init_stack();
	if (stack_a == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tmp = init_node(split[i]);
		if (tmp == NULL)
			return (free_stack(stack_a), NULL);
		add_back(stack_a, tmp);
		i++;
	}
	return (stack_a);
}

static int	*split_arg(char *arg, int *size)
{
	char	**ssplit;
	int		*split;
	int		i;

	ssplit = ft_split(arg, ' ');
	if (ssplit == NULL)
		return (NULL);
	*size = get_ssize(ssplit);
	split = (int *)malloc(*size * sizeof(int));
	if (split == NULL)
		return (free_ssplit(ssplit), NULL);
	i = 0;
	while (ssplit[i] != NULL)
	{
		if (!is_nbr(ssplit[i]) || ft_atol(ssplit[i]) < -2147483648
			|| ft_atol(ssplit[i]) > 2147483647)
			return (free(split), free_ssplit(ssplit), put_error(), NULL);
		split[i] = ft_atoi(ssplit[i]);
		i++;
	}
	free_ssplit(ssplit);
	return (split);
}

static int	*validate_and_split(int argc, char **argv, int *size)
{
	int		*split;
	int		i;

	if (argc == 1)
		return (*size = 0, NULL);
	if (argc == 2)
		return (split_arg(argv[1], size));
	else
	{
		*size = argc - 1;
		split = (int *)malloc(*size * sizeof(int));
		if (split == NULL)
			return (NULL);
		i = argc - 1;
		while (i > 0)
		{
			if (!is_nbr(argv[i]) || ft_atol(argv[i]) < -2147483648
				|| ft_atol(argv[i]) > 2147483647)
				return (free(split), put_error(), NULL);
			split[i - 1] = ft_atoi(argv[i]);
			i--;
		}
	}
	return (split);
}

static void	perform_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (is_sorted(stack_a))
		return ;
	else if (size == 2 && stack_a->head > stack_a->tail)
		swap("sa", stack_a);
	else if (size == 3)
		sort_three(stack_a, 2);
	else if (size == 4 || size == 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	int		*split;
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	split = validate_and_split(argc, argv, &size);
	if (split == NULL)
		return (1);
	stack_a = init_and_fill(split, size);
	if (stack_a == NULL)
		return (free(split), 1);
	if (has_duplicates(split, size))
		return (free_stack(stack_a), free(split), put_error(), 1);
	free(split);
	put_index(stack_a);
	stack_b = init_stack();
	if (stack_b == NULL)
		return (free_stack(stack_a), 1);
	perform_sort(stack_a, stack_b, size);
	return (free_stack(stack_a), free_stack(stack_b), 0);
}
