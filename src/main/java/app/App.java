package app;

public class App 
{
    public static void main( String[] args )
    {
        Queue<Integer> q = new Queue<>();
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
        q.enqueue(5);
        q.enqueue(6);
//        q.dequeue();q.dequeue();q.dequeue();
        System.out.println(q.empty());

        while(!q.empty()) {
            System.out.print(q.front()+"<-");
            q.dequeue();
        }
    }
}
