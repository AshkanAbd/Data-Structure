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

    public static int[] mergeSort(int[] array) {
        int size = array.length;
        int[] dst = new int[size];
        System.arraycopy(array, 0, dst, 0, size);
        mergeSort(dst, 0, size - 1);
        return dst;
    }

    public static int[] quickSort(int[] array) {
        int size = array.length;
        int[]dst = new int[size];
        System.arraycopy(array,0,dst,0,size);

        return dst;
    }

    private static void quickSort(){
        
    }

    private static void mergeSort(int[] array, int start, int end) {
        if (start >= end) return;
        int mid = (start + end) / 2;
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        merge(array, start, mid, end);
    }

    private static void merge(int[] array, int start, int mid, int end) {
        int a[] = new int[mid - start + 1];
        int b[] = new int[end - mid];
        System.arraycopy(array, start, a, 0, mid - start + 1);
        System.arraycopy(array, mid + 1, b, 0, end - mid);
        int x = 0, y = 0;
        for (int i = start; i <= end; i++) {
            if (x >= mid - start + 1) {
                array[i] = b[y];
                y++;
            } else if (y >= end - mid) {
                array[i] = a[x];
                x++;
            } else if (a[x] < b[y]) {
                array[i] = a[x];
                x++;
            } else {
                array[i] = b[y];
                y++;
            }
        }
    }

    private static void swap(int[] arr, int a, int b) {
        int c = arr[a];
        arr[a] = arr[b];
        arr[b] = c;
    }

}
