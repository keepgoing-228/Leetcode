
typedef struct pair
{
	int num;
	int pow;
} pair;


int getPower(int x){
    if(x == 1)
        return 0;
    return (x % 2) == 0 ? 1+ getPower(x/2) : 1 + getPower(3*x+1);
}

int comp(const void *a, const void *b)
{
	pair *a1 = (pair *)a;
	pair *b1 = (pair *)b;

	return a1->pow - b1->pow;
}


int getKth(int lo, int hi, int k){
    int len = hi - lo + 1;
	pair *arr = calloc(len, sizeof(pair));

	for (int i = lo, j = 0; i <= hi; i++, j++)
	{
		arr[j].num = i;
		arr[j].pow = getPower(i);
	}

	qsort(arr, len, sizeof(pair), comp);

	return arr[k - 1].num;
}
