package app;

import java.util.ArrayDeque;
import java.util.Queue;

public class QueueTest {
    public static void main(String[] args) {
        Queue<Integer> queue = new ArrayDeque<>();
//        queue.add(4);
//        queue.offer(91);
//        queue.add(6);
//        queue.add(10);
//        queue.add(15);
//        queue.add(17);
        for(int i=0; i<150; i++) {
            System.out.print(i+" ");
            queue.add(i);
//            queue.element();
        }

        System.out.println(queue.offer(16));

        queue.forEach(System.out::println);

        for(int i=0; i<15; i++) {
            System.out.print(i+" ");
//            queue.remove();
            queue.poll();
        }
    }
}
