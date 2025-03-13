#include <stdio.h>

int main(){
	int n;

	printf("Give me a number to start spitting out squares: ");
	scanf("%d", &n);

	long long sum = 0;

	for(int idx = 1; idx <= n; idx++){
		sum += idx * idx;
	}
	
	printf("The sum of the squares is: %lld\n", sum);

}

