#include <iostream>
using namespace std;

typedef struct FLOWER {
	int start;
	int end;
}Flower;

Flower flower[100010];

void quickSort(int start, int end)
{
	int left = start;
	int right = end;
	int pivot = flower[(start + end) / 2].start;
	Flower tmp;

	while (left <= right) {
		while (flower[left].start < pivot) {
			left++;
		}

		while (flower[right].start > pivot) {
			right--;
		}

		if (left <= right) {
			tmp = flower[left];
			flower[left] = flower[right];
			flower[right] = tmp;

			left++;
			right--;
		}
	}

	if (left < end) {
		quickSort(left, end);
	}

	if (right > start) {
		quickSort(start, right);
	}
}

int main()
{
	int n;
	int i, j;
	int sm, sd, em, ed;
	int start, end;
	int theend = 1201;
	int index = 0, count = 0, flag = 0;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> sm >> sd >> em >> ed;
		flower[i].start = sm * 100 + sd;
		flower[i].end = em * 100 + ed;
	}

	quickSort(0, n - 1);

	start = end = 301;

	while (start < theend) {

		for (i = index; i < n; i++) {
			if (flower[i].start <= start) {
				if (flower[i].end > end) {
					end = flower[i].end;
					index = i;
				}
			}
		}

		if (start == end) {
			flag = 1;
			start = theend;
		}
		else {
			start = end;
			count++;
		}
	}

	if (flag == 1) {
		cout << "0\n";
	}
	else {
		cout << count;
	}

	return 0;
}