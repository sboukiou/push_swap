#include "../includes/push_swap.h"
#include <stdio.h>


t_node	*stack_create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

t_node	*stack_push(t_node **head, t_node	*node)
{
	t_node	*temp;

	if (!head)
		return (NULL);
	if (!(*head))
	{
		*head = node;
		return (node);
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
	return (node);
}

void	stack_free(t_node **head)
{
	t_node	*temp;
	t_node	*to_free;

	if (!head)
		return ;
	temp = *head;
	while (temp)
	{
		to_free = temp;
		temp = temp->next;
		free(to_free);
	}
	head = NULL;
}

void	stack_print(t_node *head)
{
	t_node	*temp;

	temp = head;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
}
