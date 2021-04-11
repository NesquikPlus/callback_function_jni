import java.util.*;

public class JNIExample{
static{
  try{ 
        System.loadLibrary("JNIExample");
  }catch(Exception e){
     System.out.println(e.toString());
  }
}

public native void SetCallback(JNIExample jniexample);

public static void main(String args[]){
     (new JNIExample()).go();
}

public void go(){
    SetCallback(this);
}

 //This will be called from inside the native method    
 public String Callback(String msg){
    return "Java Callback echo:" +msg;
 } 
}  
