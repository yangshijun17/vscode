#include <stdio.h>
int mergesort(int A[], int p, int r);
int merge(int A[], int p, int q, int r);
int main()
{
    int n, a[20];
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d", mergesort(a, 1, n));
}
int merge(int A[], int p, int q, int r) {
    int i, j, k, inversion_num = 0;

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[30];
    int R[30];

    for (i = 0; i < n1; i++) L[i] = A[p + i];
    for (j = 0; j < n2; j++) R[j] = A[q + j + 1];

    for(i = j = 0, k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
            inversion_num += n1 - i;
        }
    }

    return inversion_num;
}

int merge_sort(int A[], int p, int r) {
    if (p < r) {
        int inversion_num = 0;
        int q = (p + r) / 2;
        inversion_num += merge_sort(A, p, q);
        inversion_num += merge_sort(A, q + 1, r);
        inversion_num += merge(A, p, q, r);
        return inversion_num;
    } else {
        return 0;
    }
}
