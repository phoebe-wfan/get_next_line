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

#include "get_next_line_bonus.h"
#include <stdio.h>

int main()
{
	int fd1 = open("1.txt", O_CREAT | O_RDONLY);
	int fd2 = open("2.txt", O_CREAT | O_RDONLY);
	int fd3 = open("3.txt", O_CREAT | O_RDONLY);
	printf("$--------$\n");
	printf("1: %s", get_next_line_bonus(fd1));
	printf("$--------$\n");
	printf("2: %s", get_next_line_bonus(fd2));
	printf("$--------$\n");
	printf("3: %s", get_next_line_bonus(fd3));
	printf("$--------$\n");
	printf("4: %s", get_next_line_bonus(fd1));
	printf("$--------$\n");
	printf("5: %s", get_next_line_bonus(fd2));
	printf("$--------$\n");
	printf("6: %s", get_next_line_bonus(fd3));
	printf("$--------$\n");
	printf("7: %s", get_next_line_bonus(fd1));
	return 0;
}
