typedef struct NODE {
    int val;
    struct NODE *next;
} NODE;

static NODE *HEAD = NULL;

static NODE *node_alloc(int val) {
    NODE *tmp = (NODE *) malloc(sizeof(NODE));

    if (tmp != NULL) {
        tmp->val = val;
        tmp->next = NULL;
    }
    return tmp;
}

int head_insert(int val) {
    NODE *tmp = node_alloc(val);
    if (tmp == NULL)
        return 0;

    if (HEAD == NULL) {
        TAIL = HEAD = tmp;
    } else {
        tmp->next = HEAD;
        HEAD = tmp;
    }

    return 1;
}

int tail_inser(int val) {
    NODE *tmp = node_alloc(val);

    if (tmp == NULL)
        return 0;
}
