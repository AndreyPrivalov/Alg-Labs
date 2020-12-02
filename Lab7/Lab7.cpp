﻿#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <queue>

using namespace std;

struct graph {
	int** matrix;
	int size;
}m;


int* generate_list(int size, int value) {
	int* NUM = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		NUM[i] = value;
	}
	return NUM;
}

void outputMatrix(graph m) {
	printf_s(" ");
	for (int i = 0; i < m.size; i++) {
		printf_s("%2d ", i);
	}
	printf_s("\n");
	for (int i = 0; i < m.size; i++) {
		printf_s("%2d ", i);
		for (int j = 0; j < m.size; j++) {
			printf_s("%2d ", m.matrix[i][j]);
		}
		printf_s("\n");
	}
}

//Заполнение массива
void fillMatrix(graph m) {
	int value;
	for (int i = 0; i < m.size; i++) {
		for (int j = i + 1; j < m.size; j++) {

			value = rand() % 10;
			if (value < 3)
				value = 0;
			else
				value = rand() % 8;

			m.matrix[i][j] = value;
			m.matrix[j][i] = m.matrix[i][j];
		}
	}
}

//Создание двумерного массива
int** createMatrix(int size) {
	int** matrix = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++) {
		matrix[i] = (int*)calloc(size, sizeof(int));
	}
	return matrix;
}



void BFSD(int v, graph m, queue <int> q, int* DIST) {
	q.push(v);
	DIST[v] = 0;
	while (q.empty() != true) {
		v = q.front();
		q.pop();
		for (int i = 0; i < m.size; i++) {
			if (m.matrix[v][i] > 0 && DIST[i] > DIST[v] + m.matrix[v][i]) {
				q.push(i);
				DIST[i] = DIST[v] + m.matrix[v][i];
			}
		}
	}
}

bool checkNewVertex(int* NUM) {
	for (int i = 0; i < m.size; i++) {
		if (NUM[m.size - i - 1] == 0) {
			return true;
			break;
		}
	}
	return false;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	queue <int> q;
	int* DIST;

	int v;

	printf_s("Количество вершин графа:");
	scanf_s("%d", &m.size);

	DIST = generate_list(m.size, 1000);

	m.matrix = createMatrix(m.size);
	fillMatrix(m);
	outputMatrix(m);
	printf_s("\n");
	printf_s("Расстояния до вершин: \n\n");

	for (int i = 0; i < m.size; i++) {
		printf_s("%2d: ", i);
		BFSD(i, m, q, DIST);

		for (int i = 0; i < m.size; i++) {
			printf_s("%d ", DIST[i]);
			DIST[i] = 1000;
		}

		printf_s("\n");
	}

}