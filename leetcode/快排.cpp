#include <iostream>
#include <vector>
#include <algorithm> // ����swap����

using namespace std;

// Hoare��������
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low];  // ѡ���һ��Ԫ����Ϊ����
    int i = low - 1;       // ��ָ���ʼ��
    int j = high + 1;      // ��ָ���ʼ��

    while (true) {
        // ���������ҵ���һ�����ڵ���pivot��Ԫ��
        do {
            i++;
        } while (arr[i] < pivot);

        // ���������ҵ���һ��С�ڵ���pivot��Ԫ��
        do {
            j--;
        } while (arr[j] > pivot);

        // ��ָ������ʱ���ط�����
        if (i >= j) {
            cout << i << " " << j << endl;
            return i;
        }
        

        // ����������������Ԫ�ض�
        std::swap(arr[i], arr[j]);
    }
}

// ��������ݹ麯��
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi�Ƿ����㣬arr[pi]������ȷλ��
        int pi = partition(arr, low, high);

        // �ݹ���������������������
        quickSort(arr, low, pi-1);      // ע���������piλ��
        quickSort(arr, pi , high); // �������Ҳ��Ԫ��
    }
}

// ���Դ���
int main() {
    std::vector<int> arr = { 1,2,3,4,5,9,8,7 };
    int n = arr.size();

    std::cout << "ԭʼ����: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    quickSort(arr, 0, n - 1);

    std::cout << "�����: ";
    for (int x : arr) std::cout << x << " ";
    return 0;
}