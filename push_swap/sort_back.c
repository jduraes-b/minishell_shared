/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:13:58 by jduraes-          #+#    #+#             */
/*   Updated: 2023/12/01 19:53:22 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_back(t_stack **a, t_stack **b)
{
	t_stack	*curr;

	curr = *b;
	if (curr)
		curr->sprice = 0;
	while (curr)
	{
		refresh(a, b);
		curr->sprice = curr->position;
		curr->tprice = howmanyrotateback(curr, a);
		if (curr->sprice < (ps_lstsize(*b) / 2))
			curr->cost = tophcost(curr, b, a);
		else

			curr->cost = bottomhcost(curr, b, a);
		curr = curr->next;
	}
}

int	howmanyrotateback(t_stack *s, t_stack **t)
{
	t_stack	*ts;
	t_stack	*tt;
	int		price;

	ts = s;
	tt = *t;
	price = 0;
	while (tt)
	{
		if (targetfindex(ts->f_index, tt, 'a') == tt->f_index)
			return (price);
		else
		{
			price++;
			tt = tt->next;
		}
	}
	return (price);
}

void	sort_back(t_stack **s, t_stack **t)
{
	t_stack	*curr;

	curr = *s;
	while (curr)
	{
		refresh(s, t);
		cost_back(t, s);
		curr = cheapest(s);
		applyb(curr, s, t);
		if (curr)
			curr = curr->next;
	}
}
