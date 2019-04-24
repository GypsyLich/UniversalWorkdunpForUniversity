#include "graph.h"
#include "searchAlg.h"
#include <stdio.h>

int main() {
    int connectivityMatrix[GRAPHSIZE][GRAPHSIZE];
    int prev[GRAPHSIZE];
    int marked[GRAPHSIZE];
    int dist[GRAPHSIZE];
    int i, timer, j, p = 0;
    initConnectivityMatrix(&connectivityMatrix);
    minHeap *priorityQueue = heap_create(GRAPHSIZE);

    timer = wtime();
    dist[0] = 0;
    prev[0] = -1;
    insertNode(priorityQueue, 0, dist[0]);
    for (i = 1; i <= GRAPHSIZE; ++i) {
        dist[i] = INF;
        marked[i] = 0;
        prev[i] = -1;
        insertNode(priorityQueue, i, dist[i]);
    }

    for (i = 0; i < GRAPHSIZE - 1; ++i) {
        node minNode = extractMinNode(priorityQueue);
        marked[minNode.key] = 1;
        for (j = 0; j < GRAPHSIZE; ++j) {
            p = dist[minNode.key] + connectivityMatrix[minNode.key][j];
            if (p < dist[j] && !marked[j]) {
                dist[j] = p;
                decrease_key(priorityQueue, j, dist[j], GRAPHSIZE);
                prev[j] = minNode.key;
            }
        }
    }
    printf("time: %f\n", wtime() - timer);
    for (i = 1; i < GRAPHSIZE; i++) {
        if (dist[i] >= INF) {
            printf("Distance of node %d is not found\n", i);
            printf("Path= None\n");
        } else {
            printf("Distance of node %d = %d\n", i, dist[i]);
            printf("Path= %d", i);

            j = i;
            while (j != 0) {
                j = prev[j];
                printf("<-%d", j);
            }
            printf("\n");
        }
    }

    ////////////////////////////////////////////////////
    printf("\n-------------------------------------------------------------"
           "---\n");

    int gPrev[GRIDGRAPHSIZE];
    int gMarked[GRIDGRAPHSIZE];
    int gDist[GRIDGRAPHSIZE];
    int connectivityGridMatrix[GRIDGRAPHSIZE][GRIDGRAPHSIZE];
    initConnectivityMatrixGRID(&connectivityGridMatrix);

    timer = wtime();
    minHeap *GRIDPriorityQueue = heap_create(GRIDGRAPHSIZE);

    gDist[0] = 0;
    gPrev[0] = -1;
    insertNode(GRIDPriorityQueue, 0, gDist[0]);
    for (i = 1; i < GRIDGRAPHSIZE; ++i) {
        gDist[i] = INF;
        gMarked[i] = 0;
        gPrev[i] = -1;
        insertNode(GRIDPriorityQueue, i, gDist[i]);
    }
    for (i = 0; i < GRIDGRAPHSIZE - 1; ++i) {
        node minNode = extractMinNode(GRIDPriorityQueue);

        gMarked[minNode.key] = 1;
        for (j = 0; j < GRIDGRAPHSIZE; ++j) {
            p = gDist[minNode.key] + connectivityGridMatrix[minNode.key][j];
            if (p < gDist[j] && !gMarked[j]) {
                gDist[j] = p;
                decrease_key(GRIDPriorityQueue, j, gDist[j], GRIDGRAPHSIZE);
                gPrev[j] = minNode.key;
            }
        }
    }

    printf("time: %f\n", wtime() - timer);
    for (i = 1; i < GRIDGRAPHSIZE; i++) {
        printf("Distance of node %d = %d\n", i, gDist[i]);
        printf("Path= %d", i);

        j = i;
        while (j != 0) {
            j = gPrev[j];
            printf("<-%d", j);
        }
        printf("\n");
    }
    scanf("%d", &i);
    /*























































































































































































































    */
    printf(
        R"H(⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢟⣩⢿⡟⣿⣿⠟⣻⣿⣿⣿⡿⠛⣛⣿⣿⣿⣿⣿⣿⣿⣟⢛⣿⡿⣻⣟⣿⣿⣿⣿⣿⣿⣿⣟⢿⣝⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣫⢖⣽⡾⢫⣾⣿⣿⢰⣿⣿⣿⣿⣿⣾⣿⣿⣿⢿⣿⠿⣛⣭⣵⣾⣿⣽⡟⣾⣿⣿⣿⣿⣿⣿⣿⣿⣧⡙⠳⣌⡻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢡⢡⣿⡿⣡⢿⣿⣿⡏⣼⣿⣿⣿⣿⣿⣿⣿⡿⣟⣭⣶⡿⠟⠛⢹⣿⠃⢿⠁⣿⣿⣿⣿⣿⣧⣿⣿⣿⣿⣷⡀⠨⡻⣮⡻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⡿⣾⣿⢷⣿⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣿⣿⣫⣵⠿⠊⠀⠀⠀⣾⡿⣠⡈⠀⠉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⠀⠹⣎⠻⣎⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⡇⣿⡿⢸⠟⣿⣿⣿⡇⣿⣿⣿⣿⡏⣿⣿⣟⠯⠒⠀⠀⠀⠀⠀⣿⡇⣿⡇⢰⣿⣸⢸⣿⡟⣿⣿⣿⣿⣿⣿⡷⠁⠀⢻⣇⠘⢷⡙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⣿⣿⡇⣾⠀⢿⣿⣿⣿⣿⣿⣿⣿⣧⣿⡿⠑⠀⠀⠀⠀⠀⠀⠀⣿⡇⣿⡇⢿⣿⣿⣾⣿⣿⣿⣿⣿⢿⣿⣻⠁⠀⠀⠈⣿⡆⢈⢿⡜⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⣿⣿⡇⡿⠀⣄⢿⣷⣿⣿⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣇⣿⢻⡸⣿⣿⣿⣿⣿⣿⣿⣿⡞⣿⣿⣿⡄⡇⠀⣿⣿⢸⢸⣻⣌⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⡇⣇⣤⣿⣾⡏⣿⣿⣿⣿⣿⢸⠀⠀⢀⣤⣶⠿⠟⠛⠛⠛⠿⣿⣿⣧⠳⣹⣿⣿⣿⣿⣇⢿⣿⢻⡹⣿⣿⣿⡇⣇⣿⣿⢸⣿⡏⣿⣆⢻⣿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡌⣿⡇⣿⣿⣿⣿⣏⣿⣿⣿⣿⡇⢸⠀⠀⠻⠋⠀⢀⣠⣤⣤⣀⠀⠀⠙⡿⠧⠈⠳⢿⣿⣿⣿⢪⣿⡇⠳⣻⣿⣿⣇⣿⣿⣿⣼⣿⢣⣿⣿⣆⢃⠀⠀⠀⠀⠐⠒⠒⠒⠬⠭⠍⣛⣛⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⢹⣿⣿⠟⠉⠙⠻⢿⣿⢿⡟⠃⢸⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣧⠀⠀⠈⠀⠀⠀⠀⠀⠉⠙⢆⠬⠟⠛⠛⠛⢿⣿⣿⣿⣿⡿⡙⣸⣿⣟⣿⡸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠂⠩⠍⢛⡛⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⡟⠁⠀⡐⠲⢄⢸⣿⠘⠀⠀⣿⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣶⣄⠀⠀⣿⡟⡽⡿⣱⣵⣿⣿⢏⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠒⠒⠨⠭⠍⢛⣛⡻⠿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⢸⠀⠀⠓⠤⡔⢹⣿⣆⠀⠀⣿⠀⠀⠀⣀⠀⠈⠛⠛⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⠀⠀⠙⠉⢸⣟⣯⣾⣿⣵⡿⠋⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠒⢍⡻⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡌⣇⠀⡔⠊⣙⢸⢸⣿⡇⡀⣿⠀⠀⠀⠈⠓⠦⠤⢤⣤⡤⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⠟⠀⠀⠀⠀⣾⣿⡿⠟⣋⣥⣾⠃⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠸⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⣿⣄⠑⠉⠈⢹⢸⣿⣿⣷⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣄⠀⠉⠉⠉⠀⠀⠀⠀⡼⣩⣴⣾⣿⣿⣿⣿⢰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⢸⢱⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⣿⣿⣿⣷⣶⣾⢸⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠉⠒⠒⠒⠊⠀⢰⢡⣿⣿⣿⣿⣿⣿⣿⠘⠀⠀⠀()⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⢸⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢁⣿⣿⣿⡿⣿⣿⡸⣿⣿⣿⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠇⣾⣿⣿⣿⣿⣿⣿⡇⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡟⣾⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⢧⣿⢿⡇⣿⣿⣿⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼⢸⣿⣿⣿⣿⣿⣿⣿⡇⠃⠀⠀⠀||⠀⠀\\⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀//⠀=====||=====⡇⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⡼⣸⣿⡟⣼⡿⣿⡇⣿⣿⣿⢸⢢⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⢃⣿⣿⣿⣿⣿⣿⣿⣿⢡⠀⠀⠀⠀||⠀⠀⠀\\⠀⠀⠀⠀⠀⠀⠀⠀//⠀⠀⠀⠀⠀⠀⠀|| ⠀⠀⠀⢠⢃⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢃⣧⣿⡟⣼⣿⣻⠁⢷⢻⣿⣿⢸⡀⠻⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⢏⣼⣿⣿⣿⣿⣿⣿⣿⣿⠸⠀⠀⠀⠀||⠀⠀⠀⠀\\⠀⠀⠀⠀⠀⠀//⠀⠀⠀⠀⠀⠀⠀⠀||⠀ ⠀⠀⢸⢸⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣼⣿⡟⣵⣿⣯⠻⡀⢸⢸⣿⣿⣸⡇⠀⠈⠻⣿⣶⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⢞⣡⣾⣿⣿⣿⣿⣿⣿⣿⣿⡏⡀⠀⠀⠀⠀||⠀⠀⠀⠀⠀\\⠀⠀⠀⠀//⠀⠀⠀⠀⠀⠀⠀⠀⠀||⠀⠀ ⠀⡾⣸⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢡⣿⠿⠞⠛⠛⠋⢀⢧⠘⣾⣿⣿⡏⡇⠀⠀⠀⠈⠻⣿⣿⣗⣦⣄⡀⠀⠀⠀⠀⢀⣀⣠⡴⠖⠛⣩⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⡇⠀⠀⠀⠀||⠀⠀⠀⠀⠀⠀\\⠀⠀//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀||⠀⠀ ⠀⡇⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⠟⣫⠔⠊⠉⠀⠀⠀⠀⠀⠀⢸⡘⡆⣇⣿⣿⡇⣷⡀⠀⠀⠀⠀⠀⣼⣟⣽⣿⣿⣿⣷⠶⣛⣩⣭⣴⡶⢋⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢁⠁⠀⠀⠀⠀||⠀⠀⠀⠀⠀⠀⠀\\//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀||⠀⠀ ⢠⡇⣿⣿⣿⣿
⣿⣿⣿⣿⢟⡵⠋⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠁⢹⣸⢻⣿⣇⣿⠙⢦⡀⠀⠀⠀⣇⠈⠻⣿⠝⢋⣥⣾⣿⣿⡿⢛⠕⣱⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⢰⣿⣿⣿⣿
⣿⣿⡿⣣⠋⢀⡠⠤⠒⠉⠁⠀⠀⠈⠐⠢⢄⡀⠀⠀⢻⣾⣿⣿⢸⠀⠀⠙⢦⡀⠀⡇⢣⡀⠉⠻⣶⠤⣍⣉⠁⠂⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀_____⠀   _____⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⢸⣿⣿⣿⣿
⣿⣿⠱⡡⠒⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠑⠄⡈⢧⣿⣿⢸⡇⠀⠀⠀⠙⢦⡇⠀⠱⡀⠀⠈⠳⣄⠉⠙⠳⢦⣭⣙⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⡩⠚⠉⠻⣄⠀⠀⠀⠀⠀⠀⠀/⠀⠀   \  /     \⠀⠀⠀⠀⠀⠀⠀⠀⠀⡏⣾⣿⣿⣿⣿
⣿⣿⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢦⢄⡘⢾⣿⣿⡏⡇⠀⠀⠀⠀⠀⠙⢶⣄⢳⠀⣀⡀⠘⢦⣀⣀⣀⣈⠙⠳⡎⢿⣿⣿⣿⣿⣿⡿⢛⡵⠋⠀⠀⠀⠀⠙⢆⠀⠀⠀⠀⠀/ ⠀⠀⠀⠀⠀⠀\/⠀⠀  ⠀⠀⠀\ ⠀⠀⠀⠀⠀⠀⠀⡇⣿⣿⣿⣿⣿
⣿⣿⣌⢂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠱⡌⠢⡙⢿⣧⣿⠀⢀⣠⡶⡫⣩⡷⢿⣦⢱⢋⣩⡿⡶⣿⣾⠫⣪⡆⠀⡇⢣⠹⣿⣿⣿⢋⠔⠁⠀⢀⡴⢪⣱⣄⠰⡺⣆⠀⠀ ⠀| ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⠀⠀⠀|⠀⠀⠀⠀⠀⠀⠀⢰⢱⣿⣿⣿⣿⣿
⣿⣿⣿⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢦⢰⠸⣿⢸⣊⡿⡫⣪⣾⠯⣺⡾⡻⣫⣿⡿⣪⡾⡳⣩⡾⡫⣳⠀⡇⠀⢣⠹⣿⣿⢸⡄⠀⠈⠉⠉⠉⠉⠉⠑⢬⡊⠀⠀⠀⠀⠀\⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀ ⠀⠀/⠀⠀⠀⠀⠀⠀⠀⣀⡼⣘⢿⣿⣿⣿⣿
⣿⣿⣿⡆⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⡀⣿⣿⡯⣪⡾⡋⣺⡾⡫⣪⡾⣧⢸⡾⡫⣪⡾⡫⣪⡾⡻⣀⡇⠀⠀⢧⢻⢋⡎⠀⠀⢀⣀⡤⠤⢤⣀⠀⠀⢙⣦⠀⠀⠀⠀⠀\⠀⠀⠀⠀⠀ ⠀⠀⠀⠀⠀ /⠀⠀⠀⠀⠀⣀⠔⠊⠀⠀⠘⢦⢻⣿⣿⣿
⣿⣿⣿⣧⢻⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⠋⣨⡾⡫⢪⡾⡫⢺⣾⡻⣼⣾⡫⣪⡾⡫⣪⡾⣿⡀⠀⠀⠘⡆⠄⣧⠀⠉⠁⠀⠀⠀⠀⠈⠙⠦⣝⣍⣳⠀⠀⠀⠀⠀\⠀⠀⠀⠀ ⠀⠀⠀ ⠀/⠀⠀⠀⠀⢀⡬⠃⠁⠃⣀⠤⠄⢸⡜⣿⣿⣿
⣿⣿⣿⣿⡜⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣿⡶⡋⣮⡾⡋⣊⣶⡻⣺⡶⣯⣫⡿⡫⣪⡾⡫⣪⡾⣧⡀⠀⠀⢹⡀⡆⠀⠀⠀⣀⣀⣀⣀⣀⣀⣀⣄⡙⢦⡀⠀⠀⠀⠀⠀\⠀⠀⠀ ⠀⠀⠀ /⠀⠀⠀⠀⠀⠀⠓⣒⣪⠭⠕⠒⠒⠆⡃⢿⣿⣿
⣿⣿⣿⣿⡇⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣆⣴⣯⣤⡶⡋⢙⡶⡯⣪⣯⠻⣏⡾⡫⣺⡾⡻⣪⡿⡫⣢⠀⠀⢧⠻⡆⠀⠈⠀⠀⠀⠀⠀⠈⠉⠉⢩⠄⠳⠄⠀⠀⠀⠀⠀\⠀⠀ ⠀⠀ /⠀⠀⠀⠀⠀⡴⠚⠋⠓⢢⠀⠀⠀⠀⠀⢸⡘⣿⣿
⣿⣿⣿⣿⢃⣿⣷⠀⠀⠀⢨⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢎⡴⡫⢊⡶⠋⣪⡶⡋⢻⠑⠌⠢⡾⡫⣪⡾⣫⠮⡞⠁⠒⠂⠀⢹⢧⠀⠀⠀⣤⠤⠴⠒⠒⠒⠂⠊⠉⠁⠀⠀⠀⠀⠀⠀⠀\⠀ ⠀ /⠀⠀⠀⠀⠀⠀⢛⣦⠶⠦⠴⠖⠐⠲⠤⠄⡜⣰⣿⣿
⣿⣿⣿⣿⢸⣿⣿⣧⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢦⣷⣋⣀⣴⣋⢊⡴⢻⠀⠈⠢⠈⠚⡋⠉⠀⠀⠘⢦⠀⠀⠀⠀⠹⣦⠀⠀⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\  /⠀⠀⠀⠀⠀⣠⡞⣋⠒⠂⠀⠀⠀⠀⠀⠀⠈⡇⣿⣿⣿
⣿⣿⣿⡏⡾⣿⣿⣟⣧⠀⠸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢧⠀⠀⠉⠉⠉⠙⠛⠀⠀⠀⠑⡄⠈⢆⠀⠀⠀⠈⢳⡀⠀⠀⠀⠙⡷⣄⠈⠉⠓⠒⠲⠤⢤⡤⢀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⠀  ⠀⠈⠹⣛⣛⠛⠭⠉⠁⠓⠶⢀⢘⣴⣿⣿⣿
⣿⣿⣿⡇⡇⢸⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⡀⡤⢤⡤⠤⢳⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠄⠈⡆⠀⠀⠀⠀⢷⠀⠀⠀⠀⢘⡞⠳⣄⠀⠀⠀⠀⠸⢰⣶⣶⣶⣶⣭⣭⣭⣤⣐⣒⣒⡀⠠⠤⢀⠀   ⠀⠀⠙⠛⠯⢤⣀⡀⠀⣀⠏⣾⣿⣿⣿⣿
⣿⣿⣿⣧⣧⣼⣿⣿⣿⣼⣷⣤⣤⣤⣤⣤⣤⣴⣶⣬⣭⣭⣥⣤⣤⣤⣷⣤⣤⣤⣶⣥⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣼⣤⣽⣤⣤⣤⣤⣼⣦⣤⣤⣴⣥⣤⣤⣬⣧⣤⣤⣤⣤⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣭⣿⣶⣶⣦⣤⣤⣤⣤⣾⣭⣯⣵⣾⣿⣿⣿⣿⣿)H");
    printf("\n");
    return 0;
}