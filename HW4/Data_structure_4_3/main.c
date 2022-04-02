#include <stdio.h>
#define MAX 101

int Graph[MAX][MAX] = {0};
int n;

typedef struct edge {
    int u, v, w;
} edge;

typedef struct edge_list {
    edge data[MAX];
    int n;
} edge_list;

edge_list elist;
edge_list spanlist;

void kruskalAlgo();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sort();
void print();

// Applying Krushkal Algo
void kruskalAlgo() {
    int belongs[MAX], i, j, cno1, cno2;
    elist.n = 0;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++) {
            if (Graph[i][j] != 0) {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = Graph[i][j];
                elist.n++;
            }
        }

    sort();

    for (i = 0; i < n; i++)
        belongs[i] = i;

    spanlist.n = 0;

    for (i = 0; i < elist.n; i++) {
        cno1 = find(belongs, elist.data[i].u);
        cno2 = find(belongs, elist.data[i].v);

        if (cno1 != cno2) {
            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n = spanlist.n + 1;
            applyUnion(belongs, cno1, cno2);
        }
    }
}

int find(int belongs[], int vertexno) {
    return (belongs[vertexno]);
}

void applyUnion(int belongs[], int c1, int c2) {
    int i;

    for (i = 0; i < n; i++)
        if (belongs[i] == c2)
            belongs[i] = c1;
}

// Sorting algo
void sort() {
    int i, j;
    edge temp;

    for (i = 1; i < elist.n; i++)
        for (j = 0; j < elist.n - 1; j++)
            if (elist.data[j].w > elist.data[j + 1].w) {
                temp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = temp;
            }
}

// Printing the result
void print() {
    int i, cost = 0;

    for (i = 0; i < spanlist.n; i++) {
        cost = cost + spanlist.data[i].w;
    }
    if(cost != 0) {
        printf("> %d\n", cost);
    }else{
        printf("> NO connected\n");
    }
}

int main() {

    int m;
    int switer = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, num;
        scanf("%d %d %d", &a, &b, &num);
        Graph[a][b] = num;
        Graph[b][a] = num;
    }
    if (n == 2 && m == 0) {
        printf("> NO connect");
        switer = 1;
    }
    if (n != 2 && m != 1 && switer != 1) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (Graph[i][j] == 0) {
                    count++;
                }
            }
            if (count >= n - 1) {
                switer = 1;
                printf("> NO connect");
                break;
            }
            count = 0;
        }
    }
    if (switer != 1) {
        kruskalAlgo();
        print();
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d",Graph[i][j]);
            if(j < n - 1){
                printf(" ");
            }
        }
        if(i < n - 1){
            printf("\n");
        }
    }

    return 0;
}