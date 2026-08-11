选择排序：每轮在未排序部分选出最小值，交换放到未排序区间头部，\(O(n^2)\)，不稳定。
冒泡排序：不断相邻比较交换，每轮把最大值 “冒” 到末尾，原版\(O(n^2)\)，稳定，可优化到最好\(O(n)\)。
插入排序：逐个把元素向前插入前面已排好的序列，接近有序数组效率高，\(O(n^2)\)，稳定。
#include <iostream>
using namespace std;
void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	return;
}
void selectsort(int arr[],int n) {
	if (arr == nullptr || n < 2)return;
	for (int mindex, i = 0; i < n-1; ++i) {
		mindex = i;
		for (int j = i + 1; j < n ; ++j) {
			if (arr[j] < arr[mindex])mindex = j;
		}
		swap(arr, i, mindex);
	}
}
void bubblesort(int arr[], int n) {
	if (arr == nullptr || n < 2)return;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; ++j) {
			if (arr[j] > arr[j + 1])swap(arr, j, j + 1);
		}
	}
}
void insertsort(int arr[], int n) {
	if (arr == nullptr || n < 2)return;
	for (int i = 1; i < n; ++i) {
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; --j) {
			swap(arr, j, j + 1);
		}
	}
}
void print(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		if (i != 0)cout << " ";
		cout << arr[i];
	}
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int* arr;
	arr = new int[n];
	for (int i = 0; i < n; ++i)cin >> arr[i];
	selectsort(arr, n);
	print(arr, n);
	delete arr;
	return 0;
}
