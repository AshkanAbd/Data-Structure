package SortAlgorithms;

import java.util.Arrays;

public class SortAlgorithms {

    public static int[] bubbleSort(int[] array) {
        int[] dst = new int[array.length];
        int size = array.length;
        System.arraycopy(array, 0, dst, 0, array.length);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - 1; j++) {
                if (dst[j] > dst[j + 1])
                    swap(dst, j, j + 1);

            }
        }
        return dst;
    }

    private static void swap(int[] arr, int a, int b) {
        int c = arr[a];
        arr[a] = arr[b];
        arr[b] = c;
    }

}
