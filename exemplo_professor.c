#include <stdio.h>
#include <stdlib.h>

struct cel{
	int conteudo;
	struct cel *proximo;
};


typedef struct cel    celula;

celula * nova_celula(int valor){
	celula *p = malloc(sizeof(celula));
	
	
	p -> conteudo = valor;
	p -> proximo = NULL;
	
	return p;
}

void adiciona_fim(celula **topo, celula *no){
	celula *p = *topo;
	while (p->proximo != NULL)
		p = p-> proximo;
		
		p-> proximo = no;
}


void exibe_no(celula *no){
	printf("conteudo: %d\n", no ->conteudo);
}

/*busca de um no */
celula *busca_no(celula *topo, int conteudo){
	
	celula *p = NULL;
		
	for(p = topo; p!= NULL; p = p->proximo){
		if (p->conteudo == conteudo)
			break;
	}
	return p;
}

/*busca no anterior */
celula *busca_anterior(celula *topo, int conteudo){
	
	celula *p = NULL;
			
	for(p = topo; p!=NULL; p = p->proximo){
		if ((p->proximo != NULL)&& (p->proximo->conteudo == conteudo))
			break;
	}
	return p;
}



int main (void){
	
	celula *topo =NULL;
	celula *no, *p;
	int i;
	
	/*cria topo da lista */
	topo = nova_celula(1);
	
	/*adiciona nos a lista*/
	for(i=1; i<=10; i++){
		no = nova_celula(i);
		adiciona_fim(&topo, no);
	}
	
	

	/*procura por um elemento nó dentro da lista*/ 	
	no = busca_anterior(topo, 5);
	
	if(no != NULL)
		exibe_no(no);
	
	
	/*exibe conteudo da lista*/
	for(p=topo; p!= NULL; p= p->proximo)
		exibe_no(p);
		
	return 0;
}


int main2(void){
	celula *topo = NULL;
	celula *no;
	celula *p;
	
	/*criar topo da lista*/
		topo = nova_celula(1);
	
	/* cria um no para inserçao na lista */
	no = nova_celula(2);
	
	/* insere o no fim da lista*/
	adiciona_fim(&topo, no);	
	//topo ->proximo= no;
	
	
	/*cria novo no para inserçao na lista*/
	no = nova_celula(3);
	
	/* insere o no fim da lista*/
	adiciona_fim(&topo, no);
	
	/*percorre toda a lista ate posicionar no seu ulitmo nó */
	p = topo;
	
	while(p -> proximo != NULL)
		p = p -> proximo;
	
	/*insere o nó no final da lista */	
	p -> proximo = no;	
		
	/*exibe o conteubo da lista toda */
	
	for(p = topo; p!= NULL; p = p-> proximo){
	
		printf("conteudo: %d\n", p->conteudo);
	}
			
	return 0;
	
}
