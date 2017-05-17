#include <iostream>

#define TAM 100

using namespace std;

int carlinhos = 0;

void desordenar(int vet[], int tam)
{
	for (int i = tam; i > 0; i--)
	{
		vet[100 - i] = i;
	}
}

void insertion(int vet[], int tam)
{
	int trocas = 0;
	for (int i = 1; i < tam; i++) {
		int escolhido = vet[i];
		int j = i - 1;

		while ((j >= 0) && (vet[j] > escolhido)) {
			trocas++;
			vet[j + 1] = vet[j];
			j--;
		}

		vet[j + 1] = escolhido;
	}
	cout << "- Insertion: " << trocas << endl;
}

void bubble(int vet[], int tam)
{
	int trocas = 0;
	bool swapped;
	do
	{
		swapped = false;
		for (int i = 0; i < tam; i++)
		{
			if (vet[i - 1] > vet[i])
			{
				int aux = vet[i - 1];
				vet[i - 1] = vet[i];
				vet[i] = aux;
				swapped = true;
				trocas++;
			}
		}
	} while (swapped == true);
	cout << "- Bubble: " << trocas << endl;
}
void quick(int vet[], int comeco, int fim)
{
	int pivot, aux;
	int i, j;

	pivot = vet[(comeco + fim) / 2];
	i = comeco;
	j = fim;

	while (i <= j) {
		while (vet[i] <= pivot)
			i++;

		while (vet[j] > pivot)
			j--;

		if (i <= j) {
			aux = vet[i];
			vet[i] = vet[j];
			vet[j] = aux;
			i++; j--;
			carlinhos++;
		}
	}

	if (j > comeco)
		quick(vet, comeco, j);

	if (i < fim)
		quick(vet, j + 1, fim);
}

int main()
{
	int vet[TAM];
	desordenar(vet, TAM);
	insertion(vet, TAM);
	desordenar(vet, TAM);
	bubble(vet, TAM);
	desordenar(vet, TAM);


	quick(vet, 0, TAM);
	cout << "- Quick: " << carlinhos << endl;


	system("pause");
	return 0;
}