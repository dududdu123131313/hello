#include <iostream>
using namespace std;

//快速排序
int Partition(int a[], int low, int high) {
	int hhh = a[low];
	while (low < high) {
		while (hhh < a[high])
			high--;
		//a[low] = a[high];
		if (hhh > a[high]) {
			int temp;
			temp = a[high];
			a[high] = hhh;
			a[low] = temp;
			low++;
			print(a, 8);
		}

		while (hhh > a[low])
			low++;
		//a[high] = a[low];
		if (hhh < a[low]) {
			int Temp;
			Temp = a[low];
			a[low] = hhh;
			a[high] = Temp;
			high--;
			print(a, 8);
		}
	}
	//   a[low] = hhh;
	//print(a, 8);
	return low;
}
void quickSort(int a[], int low, int high) {

	if (low < high)
	{
		int pivotpos;
		pivotpos = Partition(a, low, high);
		quickSort(a, low, pivotpos - 1);
		quickSort(a, pivotpos + 1, high);
	}

}

int main() {
	int a[8] = { 42,38,65,97,76,13,27,49 };
	cout << "初始序列如下" << endl;
	print(a, 8);
	cout << "下面输出每趟排序后的序列" << endl;
	quickSort(a, 0, 7);
	print(a, 8);
	return 0;
}

//冒泡
void bubbleSort(int a[], int n) {
	bool flag;
	int i, j, temp;
	for (i = 0; i <= n - 1; i++) {
		flag = 0;
		for (j = n - 1; j > i; j--) {
			if (a[j - 1] > a[j]) {
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				flag = 1;
			}

		}
		print(a, n);
		if (flag == 0)
			return;

	}
}
int main() {
	int a[8] = { 42,38,65,97,76,13,27,49 };
	cout << "初始序列如下" << endl;
	print(a, 8);
	cout << "下面输出每趟排序后的序列" << endl;
	bubbleSort(a, 8);
	//print(a, 8);
	return 0;
}

//归并
int* b = (int*)malloc((7 + 1) * sizeof(int));
void Merge(int a[], int low, int mid, int high) {
	int i, j, k;
	for (k = low; k <= high; k++)
		b[k] = a[k];
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
		if (b[i] <= b[j])
			a[k] = b[i++];
		else
			a[k] = b[j++];
	}
	while (i <= mid)   a[k++] = b[i++];
	while (j <= high)   a[k++] = b[j++];

}
void MergeSort(int a[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);
		Merge(a, low, mid, high);
		print(a, 7);
	}
}

int main() {
	int a[8] = { 42,38,65,97,76,13,27,49 };
	cout << "初始序列如下" << endl;
	print(a, 7);
	cout << "下面输出每趟排序后的序列" << endl;
	MergeSort(a, 0, 7);
	print(a, 7);
	return 0;
}