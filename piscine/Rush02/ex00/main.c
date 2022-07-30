/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:36:44 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/30 15:51:37 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char **argv)
{
	// ./rush-02 42
	if (argc == 2)
	{
		//     parse default numbers.dict file
		read_file("numbers.dict");
		// [1] Check is number
	}
	// ./rush-02 francais.dict 42
	else if (argc == 3)
	{
		// [1] parse given *.dict file
		input_file = open(argv[1], O_RDONLY);
		// [2] Check is number		
	}
	else
		print_error();
}
