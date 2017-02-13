#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, i=0, *p, soma=0;
	float media;
	printf("Digite um valor inteiro\n");
	scanf("%d", &n);
	p = malloc(sizeof(int)*n);
	for (i=0;i<n;i++){
		p[i] = rand();
		printf("%d", p[i]);
	}
	for (i=0; i<n; i++){
		soma = soma + p[i];
	}
	media = soma/n;
	printf ("\n %f", media);
	return 0;
}
