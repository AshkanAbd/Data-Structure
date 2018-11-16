package SortAlgorithms;

public class SortAlgorithms {
    private int[] array;

    public SortAlgorithms(int[] array) {
        this.array = array;
    }

    public int[] bubbleSort() {
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

    public int[] mergeSort() {
        int size = array.length;
        int[] dst = new int[size];
        System.arraycopy(array, 0, dst, 0, size);
        mergeSort(dst, 0, size - 1);
        return dst;
    }

    public int[] quickSort() {
        int size = array.length;
        int[] dst = new int[size];
        System.arraycopy(array, 0, dst, 0, size);
        quickSort(dst, 0, size - 1);
        return dst;
    }

    public int[] insertionSort() {
        int size = array.length;
        int[] dst = new int[size];
        System.arraycopy(array, 0, dst, 0, size);
        for (int i = 1; i < size; i++) {
            int k = i;
            int temp = dst[k];
            for (int j = i - 1; j >= 0; j--) {
                if (dst[i] < dst[j]) {
                    k--;
                } else {
                    break;
                }
            }
            if (k != i) {
                System.arraycopy(dst, k, dst, k + 1, i - k);
                dst[k] = temp;
            }
        }
        return dst;
    }

    public int[] selectionSort() {
        int size = array.length;
        int[] dst = new int[size];
        System.arraycopy(array, 0, dst, 0, size);
        for (int i = size - 1; i >= 0; i--) {
            int max = i;
            for (int j = i - 1; j >= 0; j--) {
                if (dst[j] > dst[max]) {
                    max = j;
                }
            }
            if (max != i) {
                swap(dst, max, i);
            }
        }
        return dst;
    }

    private void quickSort(int[] array, int start, int end) {
        if (start >= end) return;
        int p = start, temp;
        for (int i = start + 1; i <= end; i++) {
            if (array[p] > array[i]) {
                temp = array[i];
                System.arraycopy(array, start, array, start + 1, i - start);
                p++;
                array[start] = temp;
            }
        }
        quickSort(array, start, p - 1);
        quickSort(array, p + 1, end);
    }

    private void mergeSort(int[] array, int start, int end) {
        if (start >= end) return;
        int mid = (start + end) / 2;
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        merge(array, start, mid, end);
    }

    private void merge(int[] array, int start, int mid, int end) {
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

    private void swap(int[] arr, int a, int b) {
        int c = arr[a];
        arr[a] = arr[b];
        arr[b] = c;

    }

    public int[] getArray() {
        return array;
    }

    public void setArray(int[] array) {
        this.array = array;
    }
}
