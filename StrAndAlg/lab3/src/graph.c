#include "graph.h"

#define LCHILD(x) 2 * (x + 1) - 1
#define RCHILD(x) 2 * (x + 1)
#define PARENT(x) (x - 1) / 2

/////////////MISC//////////
int getrand(int min, int max) {
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}
double wtime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}
//////////////////////////
minHeap *heap_create(int maxsize) {
    minHeap *h;
    h = malloc(sizeof(*h));
    if (h != NULL) {
        h->maxsize = maxsize;
        h->size = 0;
        h->nodes = malloc(sizeof(*h->nodes) * (maxsize + 1));
        if (h->nodes == NULL) {
            free(h);
            return NULL;
        }
    }
    return h;
}

void swap(node *n1, node *n2) {
    node temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
void heapify(minHeap *hp, int i) {
    int smallest =
        (LCHILD(i) < hp->size && hp->nodes[LCHILD(i)].data < hp->nodes[i].data)
            ? LCHILD(i)
            : i;
    if (RCHILD(i) < hp->size &&
        hp->nodes[RCHILD(i)].data < hp->nodes[smallest].data) {
        smallest = RCHILD(i);
    }
    if (smallest != i) {
        swap(&(hp->nodes[i]), &(hp->nodes[smallest]));
        heapify(hp, smallest);
    }
}

void insertNode(minHeap *hp, int key, int data) {
    if (hp->size >= hp->maxsize) {
        return;
    }
    hp->nodes[hp->size].key = key;
    hp->nodes[hp->size].data = data;

    for (int i = hp->size;
         i > 0 && hp->nodes[i].data < hp->nodes[PARENT(i)].data;
         i = PARENT(i)) {
        swap(&hp->nodes[i], &hp->nodes[PARENT(i)]);
    }
    hp->size++;
}

node extractMinNode(minHeap *hp) {
    node minNode;
    if (hp->size) {
        minNode.key = hp->nodes[0].key;
        minNode.data = hp->nodes[0].data;
        hp->nodes[0].data = hp->nodes[--(hp->size)].data + 1;
        heapify(hp, 0);
    } else {
        printf("\nMin Heap is empty!\n");
    }
    return minNode;
}
int decrease_key(struct minHeap *h, int key, int data, int numOfPoints) {
    int index;
    for (index = 0; index < numOfPoints; ++index) {
        if (h->nodes[index].key == key) {
            break;
        }
    }

    h->nodes[index].data = data;

    while (index > 0 && h->nodes[index].data < h->nodes[PARENT(index)].data) {
        swap(&h->nodes[index], &h->nodes[PARENT(index)]);
        index = PARENT(index);
    }
    return index;
}
void initConnectivityMatrix(int (*cMatrix)[GRAPHSIZE][GRAPHSIZE]) {

    srand(wtime());
    int path;
    int l = 0;
    for (int i = 0; i < GRAPHSIZE; ++i) {
        for (int j = l++; j < GRAPHSIZE; ++j) {
            if (i == j) {
                path = 0;
            } else {
                path = getrand(0, 999);
            }
            if (path < getrand(0, 999)) {
                path = INF;
            } /*
             if (path == INF) {
                 printf("%3d ", 0);
             } else {
                 printf("%3d ", path);
             }*/

            (*cMatrix)[i][j] = path;
            (*cMatrix)[j][i] = path;
        }
        /*printf("\n");
        for (int k = GRAPHSIZE - l; k < GRAPHSIZE; ++k) {
            printf("    ");
        }*/
    }
    printf("\n");
}

void initConnectivityMatrixGRID(int (*cMatrix)[GRIDGRAPHSIZE][GRIDGRAPHSIZE]) {
    int path;
    int l = 0;
    int graphLength = sqrt(GRIDGRAPHSIZE);
    for (int i = 0; i < GRIDGRAPHSIZE; ++i) {
        for (int j = l++; j < GRIDGRAPHSIZE; ++j) {
            path = 0;
            if ((j == i + 1 && ((i + 1) % graphLength != 0)) ||
                ((j == i + graphLength) && (i + 1 != GRIDGRAPHSIZE))) {
                path = 1;
            }
            //    printf("%d ", path);
            if (!path) {
                path = INF;
            }
            (*cMatrix)[i][j] = path;
            (*cMatrix)[j][i] = path;
        }
        /*    printf("\n");
            for (int k = GRIDGRAPHSIZE - l; k < GRIDGRAPHSIZE; ++k) {
                printf("  ");
            }*/
    }
    printf("\n");
}