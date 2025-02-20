#include <stdio.h>

int ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strrcmp(char *s1, char *s2)
{
	int	len_s1;
	int	len_s2;
	
	len_s1 = ft_strlen(s1) - 1;
	len_s2 = ft_strlen(s2) - 1;

	while (len_s1 >= 0 && len_s2 >= 0 && s1[len_s1] == s2[len_s2])
	{
		len_s1--;
		len_s2--;
	}
	if (len_s1 >= 0 && len_s2 >= 0)
		return (s1[len_s1] - s2[len_s2]);
	return (0);
}

int main()
{
	printf("%d\n", ft_strrcmp("caca.ber", ".be"));
}