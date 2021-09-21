#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i] && i < n)
	{
		if (big[i] == little[0])
		{
			j = 1;
			while (little[j])
			{
				if (big[i + j] != little[j] || i + j > n)
					break ;
				j++;
			}
			if (j == ft_strlen(little))
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}