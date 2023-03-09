#include <stdio.h>

// O(n^2) complexity

int get_crowd_size(int timings[], int n) {
    int entries = n/2;

    int entry_times[entries];
    int exit_times[entries];

    for (int i = 0; i < entries; i++) {
        entry_times[i] = timings[i * 2];
        exit_times[i] = timings[i * 2 + 1];
    }

    for (int i = 1; i < entries; i++) {
        for (int j = 0; j < entries - i; j++) {
            if (entry_times[j] > entry_times[j+1]) {
                int tmp = entry_times[j+1];
                entry_times[j+1] = entry_times[j];
                entry_times[j] = tmp;
                tmp = exit_times[j+1];
                exit_times[j+1] = exit_times[j];
                exit_times[j] = tmp;
            }
        }
    }

    int max_size = 0;

    for (int i = 0; i < entries; i++) {
        int current_time = entry_times[i];
        int current_size = 1;
        for (int j = 0; j < i; j++) {
            if (exit_times[j] > current_time) {
                current_size++;
            }
        }

        if (current_size > max_size) {
            max_size = current_size;
        }
    }

    return max_size;
}

// ------------------------TESTS------------------------

int main(void) {
    int timings1[] = { 600, 700,
                       700, 800,
                       800, 900 };
    printf("%d\n", get_crowd_size(timings1, sizeof(timings1)/ sizeof(int)));

    int timings2[] = { 600, 900,
                       700, 900,
                       800, 900 };
    printf("%d\n", get_crowd_size(timings2, sizeof(timings2)/ sizeof(int)));

    int timings3[] = { 1330, 1500,
                       700, 900,
                       900, 1700,
                       1000, 1800,
                       1200, 2000 };
    printf("%d\n", get_crowd_size(timings3, sizeof(timings3)/ sizeof(int)));
}
