/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:59:33 by wfan              #+#    #+#             */
/*   Updated: 2022/12/23 16:59:52 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd = open("1.txt", O_CREAT | O_RDONLY);
	printf("$--------$\n");
	printf("1: %s", get_next_line(fd));
	printf("$--------$\n");
	/*printf("2: %s", get_next_line(fd));
	printf("$--------$\n");
	printf("3: %s", get_next_line(fd));
	printf("$--------$\n");
	printf("4: %s", get_next_line(fd));
	printf("$--------$\n");
	printf("5: %s", get_next_line(fd));
	printf("$--------$\n");
	printf("6: %s", get_next_line(fd));*/
	return 0;
}
