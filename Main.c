#include <stdio.h>

// Функция бинарного поиска в отсортированном массиве
// Возвращает индекс элемента, если он найден, или -1, если не найден
int binary_search(double arr[], int size, double target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Проверяем, равен ли средний элемент целевому
        if (arr[mid] == target) {
            return mid;
        }
        // Если целевой элемент меньше, игнорируем правую половину
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        // Если целевой элемент больше, игнорируем левую половину
        else {
            left = mid + 1;
        }
    }
    
    // Элемент не найден
    return -1;
}

int main() {
    double sorted_array[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    int size = sizeof(sorted_array) / sizeof(sorted_array[0]);
    double target = 5.5;
    
    int result = binary_search(sorted_array, size, target);
    
    if (result != -1) {
        printf("Элемент %f найден по индексу %d\n", target, result);
    } else {
        printf("Элемент %f не найден в массиве\n", target);
    }
    
    return 0;
}
