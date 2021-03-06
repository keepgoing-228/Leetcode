
typedef struct {
    int* arr;
    int cap;
    int size;
} CustomStack;


CustomStack* customStackCreate(int maxSize) {
    CustomStack * res = malloc(sizeof(CustomStack));
    res->arr = malloc(sizeof(int)*maxSize);
    res->cap = maxSize;
    res->size = 0;
    return res;
}

void customStackPush(CustomStack* obj, int x) {
    if (obj->cap == obj->size) return;
    obj->arr[obj->size++] = x;
}

int customStackPop(CustomStack* obj) {
    if (obj->size == 0) return -1;
    return obj->arr[--obj->size];
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    for (int i = 0; i < k && i < obj->size; i++) {
        obj->arr[i] += val;
    }
}

void customStackFree(CustomStack* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 
 * int param_2 = customStackPop(obj);
 
 * customStackIncrement(obj, k, val);
 
 * customStackFree(obj);
*/