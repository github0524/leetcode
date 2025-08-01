#include <iostream>
#include <vector>
#include <algorithm> // 用于swap函数

using namespace std;

// Hoare分区函数
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low];  // 选择第一个元素作为枢轴
    int i = low - 1;       // 左指针初始化
    int j = high + 1;      // 右指针初始化

    while (true) {
        // 从左向右找到第一个大于等于pivot的元素
        do {
            i++;
        } while (arr[i] < pivot);

        // 从右向左找到第一个小于等于pivot的元素
        do {
            j--;
        } while (arr[j] > pivot);

        // 当指针相遇时返回分区点
        if (i >= j) {
            cout << i << " " << j << endl;
            return i;
        }
        

        // 交换不符合条件的元素对
        std::swap(arr[i], arr[j]);
    }
}

// 快速排序递归函数
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi是分区点，arr[pi]已在正确位置
        int pi = partition(arr, low, high);

        // 递归排序分区点两侧的子数组
        quickSort(arr, low, pi-1);      // 注意这里包含pi位置
        quickSort(arr, pi , high); // 分区点右侧的元素
    }
}

// 测试代码
int main() {
    std::vector<int> arr = { 1,2,3,4,5,9,8,7 };
    int n = arr.size();

    std::cout << "原始数组: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    quickSort(arr, 0, n - 1);

    std::cout << "排序后: ";
    for (int x : arr) std::cout << x << " ";
    return 0;
}