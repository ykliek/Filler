#include "filler.h"

int main()
{
	char *str;

	str = ft_strdup("qwe123 wer 34");
	printf("%d\n", ft_atoi(str + 10));
	return (0);
}
