#include <stdlib.h>
#include "libft.h"

static int	ft_inset(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trim;
	int		i;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_inset(set, s1[start]))
		start++;
	if (start == (end + 1))
		start = 0;
	while (ft_inset(set, s1[end]))
		end--;
	if (end == -1)
		return (ft_strdup(""));
	trim = (char *)malloc(end - start);
	if (!trim)
		return (NULL);
	i = 0;
	while (start <= end && end != -1)
	{
		trim[i] = s1[start];
		i++;
		start++;
	}
	return (trim);
}
