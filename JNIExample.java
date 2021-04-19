import java.util.*;

public class JNIExample
{
    // --- Native methods
    public native int intMethod(int n);
    public native boolean booleanMethod(boolean bool);
    public native String stringMethod(String text);
    public native void intArrayMethod(int[] intArray);
    public native void byteArrayMethod(byte[] byteArray);
    public native void classMethod(JNIExample jniexample);

    // --- Main method to test our native library
    public static void main(String[] args) 
    {
        System.loadLibrary("JNIExample");
        JNIExample sample = new JNIExample();
        int square = sample.intMethod(5);
        boolean bool = sample.booleanMethod(true);
        String text = sample.stringMethod("java");

        System.out.println("intMethod: " + square);
        System.out.println("booleanMethod: " + bool);
        System.out.println("stringMethod: " + text);


        int[] intArr = new int[] {1, 1, 2, 3, 5, 8, 13};
        sample.intArrayMethod(intArr);

        for (int i=0; i < 7; i++) {
        	System.out.print(intArr[i] + " ");
        }
        System.out.println();



        byte[] byteArr = new byte[] {52, 23, 52, 74, 2, 51, 13};
        sample.byteArrayMethod(byteArr);

        for (int i=0; i < 7; i++) {
        	System.out.print(byteArr[i] + " ");
        }
        System.out.println();

        (new JNIExample()).go();
    }

	public void go(){
	    classMethod(this);
	}

	public String callMe(String msg){
		System.out.println("callMe: " + msg);
		return "Hello from Java";
	}
}
