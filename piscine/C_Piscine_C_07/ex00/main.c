/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:27:35 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/26 17:16:28 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(char *src);

int	main(void)
{
	printf("%s\n", strcmp(strdup("484df41hdy1h111fs1fsd15sf15sdf115d15fdgs15gfd4sg1615df156g1515g4erg4561esg156gr15156g15eg15eg15e51e51g1515ge156e156eg156e15156ge516e1551eg51eg15g1551eg15e516eg15e15eg1515e55eg51e15e51g5151eg15eg1515egr515151erg51er51e51e551ee5eg51egr51er51er5er5eg51e5r1e51rg5egr5eg51erg5e1r51e6rg51egr516ee5g15e1g5e1g5e1g51ger51egr51erg55reg5er55er55"), ft_strdup("484df41hdy1h111fs1fsd15sf15sdf115d15fdgs15gfd4sg1615df156g1515g4erg4561esg156gr15156g15eg15eg15e51e51g1515ge156e156eg156e15156ge516e1551eg51eg15g1551eg15e516eg15e15eg1515e55eg51e15e51g5151eg15eg1515egr515151erg51er51e51e551ee5eg51egr51er51er5er5eg51e5r1e51rg5egr5eg51erg5e1r51e6rg51egr516ee5g15e1g5e1g5e1g51ger51egr51erg55reg5er55er55")) == 0 ?
		"OK" :
		"Fail");
	printf("%s\n", strcmp(strdup("nsodnfss dsgh dsdds \n dfsg sd\t dfg sdfg \r rg h"), ft_strdup("nsodnfss dsgh dsdds \n dfsg sd\t dfg sdfg \r rg h")) == 0 ?
		"OK" :
		"Fail");
	char *str;
	str = ft_strdup("");
	printf("''= '%s'\n", str);
	free(str);
	str = ft_strdup("hello 42");
	printf("'hello 42' = '%s'\n", str);
	free(str);
	str = ft_strdup("nYJatOVzewH0cocq3S7FZBZOWp2ALV29dbOXXRb1KS");
	printf("'nYJatOVzewH0cocq3S7FZBZOWp2ALV29dbOXXRb1KS' = '%s'\n", str);
	free(str);
	str = ft_strdup("LmeOcoRCbxA4wNMYV79QLgI3gwbcix1Tls8P8UchHyp7Xgt");
	printf("'LmeOcoRCbxA4wNMYV79QLgI3gwbcix1Tls8P8UchHyp7Xgt' = '%s'\n", str);
	free(str);
	str = ft_strdup("5KjffADpgVHVL5an");
	printf("'5KjffADpgVHVL5an' = '%s'\n", str);
	free(str);
	str = ft_strdup("yDrdozYAnuXEyUffkzXRCFrlDubi");
	printf("'yDrdozYAnuXEyUffkzXRCFrlDubi' = '%s'\n", str);
	free(str);
	str = ft_strdup("mZ4QUsyLFpIDk1ToqewJc3N6ZUpVaoloaOC9Uhy0Y4");
	printf("'mZ4QUsyLFpIDk1ToqewJc3N6ZUpVaoloaOC9Uhy0Y4' = '%s'\n", str);
	free(str);
	str = ft_strdup("7GLWHYz9Ic3ltYsnnhi4");
	printf("'7GLWHYz9Ic3ltYsnnhi4' = '%s'\n", str);
	free(str);
	str = ft_strdup("PNdulPNIfFcNa8ELuc0E5");
	printf("'PNdulPNIfFcNa8ELuc0E5' = '%s'\n", str);
	free(str);
	str = ft_strdup("E3E3Q7lrXntJHC0FaA60Wqymlmu0StfaAFwdgo8q4nmaq92E");
	printf("'E3E3Q7lrXntJHC0FaA60Wqymlmu0StfaAFwdgo8q4nmaq92E' = '%s'\n", str);
	free(str);
}
