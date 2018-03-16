#include <stdio.h>
#include <stdlib.h>

typedef struct _data
{    int valor;
    struct _data *prox;
} Data;

typedef struct
{    Data *cabeca;
    int tamanho;
} Stack;

void Insere(Stack *s, int val, int indice)
{    Data *tmp = (Data*)malloc(sizeof(Data));

    if((indice == 0) || (s->cabeca == NULL))
    {    tmp -> valor = val;
        tmp -> prox = s->cabeca;
        s -> cabeca = tmp;
    }
    else
    {    Data *iter = s -> cabeca;
        tmp -> valor = val;

        int i;
        if(indice >= s -> tamanho) i = s -> tamanho - 1;
        else i = indice - 1;
        while(i--) iter = iter -> prox;

        tmp -> prox = iter -> prox;
        iter -> prox = tmp;
    }

    (s -> tamanho)++;
}

void Deleta(Stack *s, int indice)
{    Data *iter = s -> cabeca;

    if((indice >= s -> tamanho) || (s -> cabeca == NULL)) return;
    else if(indice == 0)
    {    s -> cabeca = iter -> prox;
        free(iter);
    }
    else
    {    Data *iter2;

        int i = indice - 1;
        while(i--) iter = iter->prox;

        iter2 = iter->prox->prox;
        free(iter->prox);
        iter -> prox = iter2;
    }

    (s -> tamanho)--;
}

void Print(Stack *s)
{    if(s -> cabeca == NULL) printf("empty\n");
    else
    {    Data *iter = s -> cabeca;

        while(iter != NULL)
        {    printf("%d ", iter -> valor);
            iter = iter -> prox;
        }
        printf("\n");
    }
}

int main()
{    Stack *s = (Stack*)malloc(sizeof(Stack));
    s -> cabeca = NULL;
    s -> tamanho = 0;

    char tmp;
    int M, N;

    while(scanf("%c", &tmp) && (tmp != 'q'))
    {    switch(tmp)
        {    case 'f':
                scanf("%d", &N);
                Insere(s, N, 0);
                break;
            case 'i':
                scanf("%d %d", &M, &N);
                Insere(s, N, M);
                break;
            case 'r':
                Deleta(s, 0);
                break;
            case 'd':
                scanf("%d", &M);
                Deleta(s, M);
        }

        scanf("%c", &tmp);
        Print(s);
    }
}
