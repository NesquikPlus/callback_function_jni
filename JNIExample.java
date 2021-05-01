import java.util.*;

public class JNIExample
{
    public static byte packet_data[] = {0, 0, 0, 0, 0};
    // --- Native methods
    public native void initMethod();

    public static void main(String[] args) 
    {
        System.loadLibrary("JNIExample");
        JNIExample sample = new JNIExample();

        //Thread that runs cpp code's main loop.
        Thread t1 = new Thread
        (    new Runnable(){
                public void run(){  
                    sample.initMethod();
                }  
            }
        );
        t1.start();


        while(true)
        {
            System.out.print("Java main loop, arr: ");
            for(int i=0; i < packet_data.length; i++){
                System.out.print(packet_data[i] + " ");
            }
            System.out.println();
            try
            {
                Thread.sleep(1000);
            }
            catch(InterruptedException ex)
            {
                Thread.currentThread().interrupt();
            }
        }
    }

    //When a packet arrives this method is called by cpp code.
    public static void callback_method(byte[] arr)
    {
        System.out.println("Java callback method.");
        for(int i=0; i < packet_data.length; i++){
            packet_data[i] = arr[i];
        }
    }
}
