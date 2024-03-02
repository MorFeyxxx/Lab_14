#include <stdio.h>
#include <malloc.h>

typedef struct unordered_array_set {
    int* data;
    size_t size;
    size_t capacity;
} unordered_array_set;

int compare(const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

unordered_array_set create_set(char* str, int n) {
    unordered_array_set set;
    set.size = n;
    set.capacity = n;
    set.data = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        set.data[i] = str[i] - '0';
    }
    qsort(set.data, set.size, sizeof(int), compare);
    return set;
}

int main() {
    int n;
    scanf("%d", &n);
    char sherlock[n+1], moriarty[n+1];
    scanf("%s", sherlock);
    scanf("%s", moriarty);

    unordered_array_set sherlock_set = create_set(sherlock, n);
    unordered_array_set moriarty_set = create_set(moriarty, n);

    int min_slaps = 0, max_slaps = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && moriarty_set.data[j] < sherlock_set.data[i]) {
            j++;
        }
        if (j < n) {
            j++;
        } else {
            min_slaps++;
        }
    }

    j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && moriarty_set.data[j] <= sherlock_set.data[i]) {
            j++;
        }
        if (j < n) {
            max_slaps++;
            j++;
        }
    }

    printf("%d\n", min_slaps);
    printf("%d\n", max_slaps);

    free(sherlock_set.data);
    free(moriarty_set.data);

    return 0;
}