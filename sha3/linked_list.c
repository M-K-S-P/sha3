struct node {
    int da;
    struct node* plink;
}; typedef struct node *node;

node linked_list(int* narr, int n){
    static int i = 0;
    node t = NULL;
    if(n != 0){
        t = (node)malloc(sizeof(struct node*));
        t->da = narr[i++];
        t->plink = linked_list(narr, --n);
    }
    return t;
}

node go_to(node ll, int number){
    while(number){
        ll = ll->plink;
        number--;
    }
    return ll;
}