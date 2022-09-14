package app;

public class Queue<E> {
    private Node<E> front;
    private Node<E> rear;

    public Queue() {
        this.front = null;
        this.rear = null;
    }

    public void enqueue(E data) {
        if (front == null) {
            this.rear = this.front = new Node<>(data);
        } else {
            this.rear.next = new Node<>(data);
            this.rear = this.rear.next;
        }
    }

    public void dequeue() {
        if (front != null) {
            Node<E> temp = this.front;
            this.front = this.front.next;
            temp.next = null;
        }
    }

    public boolean empty() {
        return this.front == null;
    }

    public E front() {
        return this.front.data;
    }
}
