/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:03:36 by vephan            #+#    #+#             */
/*   Updated: 2025/11/24 15:04:03 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

/* push swap */
/* input: stack a - list of integers */
// a1, a2, a3, ...
// | a1 |
// | a2 |
// | a3 |
/* output: displays the list of instructions needed
 to sort stack a with smallest number at the top */
/* variables:*/
// list_a
// list_ops
// cnt - number of instructions
// maxops = max operations allowed
// a_size = nb of arguments in list a
/* Errors - checking arguments*/
// Arguments duplicate!
// Arguments outside of MAX_INT, MIN_INT
// Arguments not integers ()

/*retrieves all the arguments, 
creates a table
*/
int	*parse_list(int argc, char **argv)
{
	int	*ptr;

	

	return (ptr);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	size;
	char	*s;

	i = 0;
	if (argc <= 1)
		//ft_printf ("Error");
	else
	{
		size = argc - 1;
		/*allocate memory and store the numbers */
		while (i < size)
		{
			s = argv[i];
			//check if s is an integer
			ft_atoi(s);
			//check if it is wîthin range [MIN_INT, MAX_INT]
			//check if there are duplicates (check argv[i] vs argv[0]..argv[i - 1)]
			i++;
		}
		/*if there is an error, free the memory*/
	}
}