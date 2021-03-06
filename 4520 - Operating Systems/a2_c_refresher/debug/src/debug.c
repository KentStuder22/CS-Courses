#include "../include/debug.h"

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// protected function, that only this .c can use
int comparator_func(const void *a, const void *b) {
    return (uint8_t *)a - (uint8_t *)b;
}

bool terrible_sort(uint16_t *data_array, const size_t value_count) {
    if(value_count == 0 || data_array == NULL)
    {
        return false;
    }
    uint16_t *sorting_array = (uint16_t*)malloc(value_count * sizeof(uint16_t));
    for (size_t i = 0; i < value_count; ++i) {
        sorting_array[i] = data_array[i];
    }

    qsort(sorting_array, value_count, sizeof(sorting_array) / sizeof(uint16_t), comparator_func);

    bool sorted = true;
    for (size_t i = 0; i < value_count; ++i) {
        sorted &= sorting_array[i] < sorting_array[i + 1];
    }

    if (sorted) {
        memcpy(sorting_array, data_array, value_count);
    }
    return true;
}

