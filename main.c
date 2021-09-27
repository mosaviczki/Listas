//Julia e Monique
//Testado no Dev-C e VSCode
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Lista simples
struct No
{
    int chave;
    struct No *prox;
};
typedef struct No No;

No* insereInicio(No **prim, int chave);
void insereMeio(No **prim, int num, int ant);
void imprimeLista(No *prim);
void removeInicio(No **prim);
No *buscaNo(No *prim, int k);
void removeMeio(No **prim, int k);

int main()
{
	No *prim = NULL, *p=NULL;

	int a, ant, chave;
	printf("-----Menu-----\n1-Insere inicio\n2-Insere meio\n3-Remocao inicio\n4-Remocao meio\n5-Busca elemento\n6-Imprime lista\n0-SAIR\n");

	do
    {
		printf("\nInforme a opcao: ");
        scanf("%d", &a);
        switch(a)
	    {
		case 1:
		    printf("Informe o valor do no: ");
			scanf("%d", &chave);
			insereInicio(&prim,chave);break;
		case 2:
			printf("Informe o valor que queira adicionar e seu antecesor: ");
			scanf("%d %d", &chave, &ant);
			insereMeio(&prim,chave, ant);break;
		case 3:
			removeInicio(&prim);
            break;
		case 4:
			printf("Informe o valor que deseja remover: ");
			scanf("%d", &chave);
			removeMeio(&prim, chave);
            break;
		case 5:
			printf("Informe o valor que deseja buscar: ");
			scanf("%d", &chave);
			p=buscaNo(prim, chave);
            if(p)
                printf("Elemento encontrado!");
                else
                    printf("Elemento nao encontrado!");
             break;
		case 6:
			imprimeLista(prim);break;
		case 7:break;

		default:
        {
            if(a != 0)
		    printf("Entrada invalida!");break;
        }
       }

	}while(a != 0);
}

No* insereInicio(No **prim, int valor)
{
	assert(prim);
    No* noAux;
    noAux = (No *) malloc(sizeof(No));
	if(noAux == NULL)
	   return NULL;
    noAux->chave = valor;
    noAux->prox = NULL;
    noAux->prox = *prim;
    *prim = noAux;
    return *prim;
}

void insereMeio(No **prim, int num, int ant)
{
    No *novo, *aux;
    novo = (No *) malloc(sizeof(No));
    if(novo)
    {
        novo->chave = num;
        if(*prim == NULL)// Se lista for nula ela recebera o novo e o proximo nulo
        {
            novo->prox = NULL;
            *prim = novo;
        }
        else//Caso exista valor tera ponteiro auxiliar para olha para prim e olhar para mesmo do novo para conseguir inserir em qualquer lugar 
        {
            aux = *prim;
            while(aux->chave != ant && aux->prox)//Enquanto o auxilar for diferente do valor anterior e do proximo
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar!");
}

void removeInicio(No **prim)
{
	if(*prim==NULL)
	{
        printf("LISTA VAZIA");
		return;
	}
 	No *aux = *prim;
  	*prim = (*prim)->prox;
  	free(aux);
}

No *buscaNo(No *prim, int k)
{
	if(prim==NULL)
        printf("LISTA VAZIA ");
	
	while(prim!=NULL)
	{
		if(prim->chave == k)
		    return prim;
		else prim = prim->prox;
	}
	return NULL;
}

void removeMeio(No **prim, int k)
{
	No *ant=NULL, *aux=NULL;
	
	if(*prim==NULL)
	{
        printf("LISTA VAZIA");
		return;
	}
	if(((*prim)->prox==NULL) && ((*prim)->chave==k))
	{
		free(*prim);
		*prim=NULL;
		return;
	}
	if((*prim)->chave==k)
	{
		No *aux = *prim;
  	    *prim = (*prim)->prox;
  	    free(aux);
  	    return;
	}	
	ant=*prim;
	aux=(*prim)->prox;
	
	while(aux->chave!=k)
	{
		ant=aux;
		aux=aux->prox;
	}
	
	assert(ant);
	ant->prox=aux->prox;
	free(aux);
}
void imprimeLista(No *prim)
{
	if(prim==NULL)
	{
        printf("LISTA VAZIA");
		return;
	}	
	while(prim!=NULL)
	{
		printf("\n%d", prim->chave);
		prim=prim->prox;
	}
}

//Lista com cabeça
/*typedef struct No
{
  int chave;
  struct No *prox;
}No;

typedef struct NoCab
{
  int chave;
  int n_nos;
  struct No *prox;
}NoCab;
//As funções não mudam na lista com cabeca, o que difere e apenas o ponteiro que e passado para as fun��es, 
//que no caso � o ->prox do no cabeca

No *NoCabeca();
void insereInicio(No *prim, int valor);
No *alocaNo(int valor);
void insereMeio(No **prim, int num, int ant);
void imprimeLista(No *prim);
No *buscaNo(No *prim, int k);
void removeInicio(No **prim);
void removeMeio(No **prim, int k);

int main()
{
	No *prim=NoCabeca(), *p=NULL;
	int a, ant, valor;
	printf("-----Menu-----\n1-Insere inicio\n2-Insere meio\n3-Remocao inicio\n4-Remocao meio\n5-Busca elemento\n6-Imprime lista\n0-SAIR\n");
	do
    {
    	printf("\nInforme a opcao: ");
        scanf("%d", &a);
        switch(a)
	    {
		case 1:
		    printf("Informe o valor: ");
			scanf("%d", &valor);
			insereInicio(prim, valor);
		    break;
		case 2:
			printf("Informe o valor que queira adicionar e seu antecesor: ");
			scanf("%d %d", &valor, &ant);
			insereMeio(&prim, valor, ant);
			break;
		case 3:
			removeInicio(&prim->prox);
            break;
		case 4:
			printf("Informe o valor que deseja remover: ");
			scanf("%d", &valor);
			removeMeio(&prim->prox, valor);
            break;
		case 5:
			printf("Informe o valor que deseja buscar: ");
			scanf("%d", &valor);
			p=buscaNo(prim->prox, valor);
			if(p)
                printf("Elemento encontrado!");
            else
                printf("Elemento nao encontrado!");
            break;
		case 6:
			imprimeLista(prim->prox);break;
		case 7:
		  break;
		default:
		    if(a != 0)
		    printf("Entrada invalida!");break;
       }

	}while(a != 0);
	return 0;
}

No *NoCabeca()//lista para iniciar nó cabeca
{
    No* cabeca = (No *)malloc(sizeof(No));
    if (cabeca == NULL) 
	    return NULL;
    cabeca->chave = -1; 
    cabeca->prox = NULL;
    return cabeca; // retorno do header
}

void insereInicio(No *prim, int valor)//Insere começa com o nó depois do cabeça
{ 
    No *aux;
    aux = alocaNo(valor);
    if(aux == NULL) 
	    return;
    aux->prox = prim->prox;
    prim->prox = aux;
}

No *alocaNo(int val)
{
    No *alc; 
    alc = (No *) malloc(sizeof(No)); 
    if (alc == NULL)
	    return NULL;
    alc->chave = val;
    alc->prox = NULL;
    return alc;
}

void insereMeio(No **prim, int num, int ant)
{
    No *novo, *aux;
    novo = (No *) malloc(sizeof(No));
    if(novo)
    {
        novo->chave = num;
        if(*prim == NULL)//Quando n�o encontra o valor, ira inserir no come�o
        {
            novo->prox = (*prim)->prox;
            (*prim)->prox = novo;
        }
        else
        {
            aux = *prim;
            while(aux->chave != ant && aux->prox)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar!");
}

No *buscaNo(No *cabeca, int k)
{
	if(cabeca==NULL)
		printf("Lista Vazia");
	
	while(cabeca!=NULL)
	{
		if(cabeca->chave==k)
		    return cabeca;
		else 
		    cabeca=cabeca->prox;
	}
	return NULL;
}

void removeInicio(No **cabeca)
{
 	if(*cabeca==NULL)
	{
        printf("LISTA VAZIA");
		return;
	}	
 	No *aux = *cabeca;
  	*cabeca = (*cabeca)->prox;
  	free(aux);
}

void removeMeio(No **cabeca, int k)
{
	No *ant=NULL, *aux=NULL;
	
	if((*cabeca)==NULL)
	{
        printf("Lista vazia");
		return;
	} 	
	if(((*cabeca)->prox==NULL) && ((*cabeca)->chave==k))
	{
		free(*cabeca);
		*cabeca=NULL;
		return;
	}	
	if((*cabeca)->chave==k)
	{
		No *aux = *cabeca;
  	    *cabeca = (*cabeca)->prox;
  	    free(aux);
  	    return;
	}	
	ant=*cabeca;
	aux=(*cabeca)->prox;
		
	while(aux->chave!=k)
	{
			ant=aux;
			aux=aux->prox;
	}	
	assert(ant);
	ant->prox=aux->prox;
	free(aux);
} 
void imprimeLista(No *cabeca)
{
    if(cabeca==NULL)
	{
    	printf("Lista vazia\n");
		return;
	}
	else
	{
		printf("LISTA:");
        while(cabeca!=NULL)
	    {
		    printf("\n%d", cabeca->chave);
	     	cabeca=cabeca->prox;
	    }
	}	
}
*/

//Lista circular
/*typedef struct circular
{
	int chave;
	struct circular *prox;
}No;


void insereInicio(No **prim, int valor);
void insereMeio(No **prim, int valor, int ant);
No *buscaNo(No *ult, int k);
void removeCircularinicio(No **ult);
void imprimeLista(No *prim);
void removeMeio(No **ult, int k);

int main()
{
	No *prim = NULL, *p=NULL;

	int a, ant, valor;
	printf("-----Menu-----\n1-Insere inicio\n2-Insere meio\n3-Remocao inicio\n4-Remocao meio\n5-Busca elemento\n6-Imprime lista\n7-SAIR\n");

	do
    {
		printf("\nInforme a opcao: ");
        scanf("%d", &a);
        switch(a)
	    {
		case 1:
            printf("Informe o valor: ");
            scanf("%d", &valor);
            insereInicio(&prim,valor);
		    break;
		case 2:
			printf("Informe o valor e seu antecessor: ");
            scanf("%d %d", &valor, &ant);
            insereMeio(&prim, valor, ant);
			break;
		case 3:
			removeCircularinicio(&prim);
            break;
		case 4:
			printf("Informe o valor que deseja remover: ");
			scanf("%d", &valor);
			removeMeio(&prim, valor);
            break;
		case 5:
			printf("Informe o valor que deseja buscar: ");
			scanf("%d", &valor);
			p=buscaNo(prim, valor);
			if(p)
                printf("Elemento encontrado!");
            else
                printf("Elemento nao encontrado!");
            break;
		case 6:
			imprimeLista(prim);break;
		case 7:break;
		default:
		    if(a != 0)
		    printf("Entrada invalida!");break;
       }

	}while(a != 0);
	return 0;
}
void insereInicio(No **prim, int valor)
{
    assert(prim);	
    if(*prim == NULL)
    {	
        *prim = (No *) malloc(sizeof(No));
        if(*prim != NULL)//o proximo não ira olhar para nulo, e sim para prim
        {	
			(*prim)->chave = valor;
			(*prim)->prox = *prim;
        }	
   }
   else
    {
        No *aux = (No *) malloc(sizeof(No));
        if (aux == NULL) return;
        aux->chave = valor;		
        aux->prox = (*prim)->prox;	
        (*prim)->prox = aux;
    }
}

void insereMeio(No **prim, int num, int ant)
{
    No *novo = malloc(sizeof(No)), *aux;
    if(novo)
    {
        
        if(*prim == NULL)
        {
            *prim = (No *) malloc(sizeof(No));
            if(*prim != NULL)
            {	
		    	(*prim)->chave = num;
		    	(*prim)->prox = *prim;
            }
        }
        else
        {
			novo->chave = num;
            aux = *prim;
            while(aux->chave != ant && aux->prox)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar!");
}
No *buscaNo(No *ult, int k)//Ponteiro agora marca o ultimo elemento da lista
{
	if (ult == NULL) 
	    printf("\nLista Vazia! ");

	else
	{
        No *aux=ult->prox;
    	do
    	{
		    if(aux->chave==k)
		    return aux;
		    else aux=aux->prox;
    	}while(ult->prox!=aux);//Utiliza-se do... while ao invés de while e o critério de parada 
	    //é o ponteiro auxiliar, que começa no primeiro elemento da lista, 
	    //percorrê-la inteira até chegar no primeiro elemento novamente
	}
	return NULL;
}


void removeCircularinicio(No **ult)
{
		if((*ult)==NULL)
		printf("Lista vazia"); 
		return;
	
 	No *aux = (*ult)->prox;
 	if(aux!=aux->prox)
 	{
  	(*ult)->prox = aux->prox;
  	free(aux);
    }//Para a remoção no início apenas o ->prox do último elemento é alterado,
	//passando a olhar para o segundo elemento que no fim será o primeiro
    else
    {
    	free(*ult);
    	*ult=NULL;
	}//Nova condição: a lista tem apenas um elemento que olha a si mesmo
}

void removeMeio(No **ult, int k)
{
	No *ant=NULL, *aux=NULL;
	
	if((*ult)==NULL)
		printf("Lista vazia"); 
		return;
		
		if(((*ult)->prox==*ult) && ((*ult)->chave==k))
		{
			free(*ult);
    	    *ult=NULL;
    	    return;
		}//O critério para verificar se há apenas um nó na lista que possui
		//o valor a ser removido é ult->prox olhar para ult
		
		if((*ult)->chave==k)
		{
			No *aux = *ult;
			ant=(*ult)->prox;
		    while(ant->prox!=*ult)
			{
				ant=ant->prox;
			}
  	        
  	        ant->prox=(*ult)->prox;
			*ult = ant;
  	         free(aux);
  	         return;
		}//caso o elemento a ser removido seja o último,
		//percorre-se a lista toda até o penúltimo nó para que o ponteiro ant possa marcá-lo, 
		//para que ele possa ser o último nó
		
		ant=*ult;
		aux=(*ult)->prox;
		
	while(aux->chave!=k)
	{
			ant=aux;
			aux=aux->prox;
	}
	
	assert(ant);
	ant->prox = aux->prox;
	free(aux);
}
void imprimeLista(No *prim)
{
	if (prim == NULL)
	{
        printf("\nLista Vazia!");
		return;
	}
	else
	{
		No *naux = prim->prox;
		printf("LISTA");
		do
	    {
		    printf("\n%d", naux->chave);
		    naux = naux->prox;
	    }while(prim->prox != naux);//Utiliza-se do... while ao invés de while e o critério de parada 
	//é o ponteiro auxiliar, que começa no primeiro elemento da lista, 
	//percorrê-la inteira até chegar no primeiro elemento novamente
	}	
}*/
/*
//LISTA DUPLAMENTE ENCADEADA
struct Noduplo
{
    int chave;
    struct Noduplo *prox;
    struct Noduplo *ant;
};
typedef struct Noduplo Noduplo;

Noduplo* insereInicio(Noduplo **prim, int valor);
Noduplo* insereMeio(Noduplo **prim, int num, int anterior);
void imprimeLista(Noduplo *prim);
void removeInicio(Noduplo **prim);
Noduplo *buscaNo(Noduplo *prim, int k);
void removeMeio(Noduplo **prim, int k);

int main()
{
	Noduplo *prim = NULL, x, *p=NULL;

	int a, ant, valor;
	printf("-----Menu-----\n1-Insere inicio\n2-Insere meio\n3-Remocao inicio\n4-Remocao meio\n5-Busca elemento\n6-Imprime lista\n0-SAIR\n");

	do
    {
        printf("\nInforme a opcao: ");
        scanf("%d", &a);
        switch(a)
	    {
		case 1:
			printf("Informe o valor: ");
            scanf("%d", &valor);
            insereInicio(&prim, valor);
		    break;
		case 2:
			printf("Informe o valor e seu antecessor: ");
            scanf("%d %d", &valor, &ant);
            insereMeio(&prim, valor, ant);
			break;
		case 3:
			removeInicio(&prim);
            break;
		case 4:
			printf("Informe o valor que deseja remover: ");
			scanf("%d", &valor);
			removeMeio(&prim, valor);
            break;
		case 5:
			printf("Informe o valor que deseja buscar: ");
			scanf("%d", &valor);
			p=buscaNo(prim, valor);
            if(p)
                printf("Elemento encontrado!");
                else
                    printf("Elemento nao encontrado!");
            break;
		case 6:
			imprimeLista(prim);break;
		case 7:break;

		default:
		    if(a != 0)
		    printf("Entrada invalida!");break;
       }

	}while(a != 0);
}

Noduplo* insereInicio(Noduplo **prim, int valor)//A diferença é que nessa atualiza o valor anterior
{
    assert(prim);
    Noduplo* naux = (Noduplo*) malloc(sizeof(Noduplo));
    naux->chave = valor;
    naux->prox = *prim;
    naux->ant = NULL;// auxiliar olha para o proximo e o anterior 
    if (*prim != NULL)
        (*prim)->ant = naux;
    *prim = naux;
    return naux;
}
Noduplo* insereMeio(Noduplo **prim, int num, int anterior)
{
    Noduplo *naux = malloc(sizeof(Noduplo)), *aux;
    if(naux)
    {
        naux->chave = num;
        if(*prim == NULL)//Insere no inicio caso não exista valor
        {
            naux->prox = NULL;
            naux->ant = NULL;
            *prim = naux;
        }
        else//Necessario 2 auxiliares e o proximo olha pro anterior
        {
            aux = *prim;
            while(aux->chave != anterior && aux->prox)
                aux = aux->prox;
            naux->prox = aux->prox;
            aux->prox->ant = naux;
            naux->ant = aux;
            aux->prox = naux;
        }
        return naux;
    }
    else
    {
    	printf("Erro ao alocar!");
	}
}

void removeInicio(Noduplo **prim)
{
  	if(*prim==NULL)
	{
        printf("Lista vazia");
		return;
    }
 	Noduplo *aux = *prim;
  	*prim = (*prim)->prox;
  	(*prim)->ant=NULL;//A única diferença é que temos que fazer o ->ant do segundo elemento 
	//olhar pra nulo(que será agora o primeiro)
  	free(aux);
}

void removeMeio(Noduplo **prim, int k)
{
    if(*prim==NULL)
	{
        printf("Lista vazia");
		return;
    }	
	if(((*prim)->prox==NULL) && ((*prim)->chave==k))
	{
		free(*prim);
		*prim=NULL;
		return;
	}
	if((*prim)->chave==k)
	{
		Noduplo *aux = *prim;
	  	*prim = (*prim)->prox;
	  	(*prim)->ant=NULL;//A única diferença é que temos que fazer o ->ant do segundo elemento 
        //olhar pra nulo(que será agora o primeiro)
	  	free(aux);
         return;
	}
	//Agora que temos acesso ao elemento anterior, será necessário apenas buscar o valor que será excluído
	//e depois atualizar o ->prox do anterior e o ->ant do próximo ao excluído
	Noduplo *aux=*prim;
	while(aux->chave!=k)
	{
		aux=aux->prox;
	}
			
	if(aux->prox==NULL)
	{
		aux->ant->prox=NULL;
		free(aux);
	}
		else
		{
			aux->ant->prox=aux->prox;
			aux->prox->ant=aux->ant;
			free(aux);
		}
}

Noduplo *buscaNo(Noduplo *prim, int k)
{
	if(prim==NULL)
	{
        printf("Lista vazia");
    }
	while(prim!=NULL)
	{
		if(prim->chave==k)
		return prim;
		else prim=prim->prox;
	}
	return NULL;
}

void imprimeLista(Noduplo *prim)
{
	if(prim==NULL)
	{
        printf("Lista vazia");
		return;
    }		
	while(prim!=NULL)
	{
		printf("\n%d", prim->chave);
		prim=prim->prox;
	}
}*/
