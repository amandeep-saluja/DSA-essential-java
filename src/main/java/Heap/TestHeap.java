package Heap;

import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;

public class TestHeap {
    public static void main(String[] args) {
        Integer[] arr = {10, 15, 20, 13, 6, 90};
        Queue<Integer> heap = new PriorityQueue<>((a, b) -> b-a);

        heap.addAll(Arrays.asList(arr));

        while(!heap.isEmpty()) {
            System.out.println(heap.peek());
            heap.remove(heap.peek());
        }
    }
}
