#include <stdio.h>
#include <stdlib.h>

typedef struct node { 
    int value; 
    struct node *left; 
    struct node *right; 
    struct node *parent; 
} node;

typedef struct tree { 
    int num; 
    struct node *head; 
} tree;

void init(tree *t){
    t->head = NULL;
    t->num = 0;
}

int insert(tree *t, int value)
{
    if(t->head == NULL) 
    {
        t->head = malloc(sizeof(node)); 
        t->head->parent = NULL; 
        t->head->left = NULL; 
        t->head->right = NULL; 
        t->head->value = value; 
        t->num++; 
        return 0; 
    }

    node *temp = t->head; 
    while(temp->value != value) 
    {
        if(value > temp->value) 
        {
            if(temp->right != NULL) 
            {
                temp = temp->right;
            }
            else 
            {
                temp->right = malloc(sizeof(node)); 
                temp->right->value = value; 
                temp->right->parent = temp; 
                temp->right->right = NULL; 
                temp->right->left = NULL; 
                t->num++; 
                return 0; 
            }
        }
        else 
        {
            if(temp->left != NULL) 
            {
                temp = temp->left; 
            }
            else 
            {
                temp->left = malloc(sizeof(node)); 
                temp->left->value = value; 
                temp->left->parent = temp; 
                temp->left->right = NULL; 
                temp->left->left = NULL; 
                t->num++; 
                return 0; 
            }
        }
    }
    return 1; 
}

typedef struct node_list { 
    node *value; 
    struct node_list *next; 
    struct node_list *prev; 
} node_list;

typedef struct list { 
    struct node_list *head; 
    struct node_list *tail; 
} list;

void init_list(list *l)
{
    l->head = NULL;
    l->tail = NULL;
}

int push_front(list *l, node *value) 
{
    node_list *temp = malloc(sizeof(node_list)); 
    temp->value = value; 
    temp->next = l->head; 
    temp->prev = NULL; 
    if (l->head)
        l->head->prev = temp;
    l->head = temp; 
    if (l->tail == NULL)
        l->tail = temp;
    return 0;
}

node_list* pop_last(list *l) 
{
    node_list *temp = l->tail; 
    if (temp == NULL) 
        return NULL; 
    if (temp->prev != NULL) 
        temp->prev->next = NULL; 
    l->tail = temp->prev; 
    return temp; 
}

void width(tree *t) 
{
    list *l = NULL; 
    l = malloc(sizeof(list)); 
    init_list(l); 
    push_front(l, t->head); 
    while (l->tail != NULL){ 
        node_list* temp = pop_last(l); 
        if(temp->value->left != NULL) 
            push_front(l, temp->value->left); 
        if (temp->value->right != NULL) 
            push_front(l, temp->value->right); 
        printf("%d ", temp->value->value); 
        free(temp); 
    }
}


int main() {
    tree *t = NULL;
    t = malloc(sizeof(tree));
    init(t);
    int a;
    for (int i = 0; i < 7; i++){
        scanf("%d",&a);
        insert(t, a);
    }
    width(t);
    return 0;
}

