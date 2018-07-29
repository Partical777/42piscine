#include <unistd.h>
#include <stdio.h>

int	ft_is_prime(int nb){
	int i;

	i = 1;
	if(nb <= 1){
		return 0;
  }
	while (i < nb){
    i++;
    if (i != nb && (nb % i) == 0){
      return 0;
    }
  }
  return 1;
}
