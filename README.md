Step 1(Generate cpp header file from desired java file):

	javac JNIExample.java -h .

Step 2(Create and write a cpp implementation for generated header file)

Step 3(Generate dll that will be imported from java code):
	g++ -c JNIExample.cpp -I "C:\Program Files\Java\jdk-15.0.1\include" -I "C:\Program Files\Java\jdk-15.0.1\include\win32"
	g++ -shared -o JNIExample.dll JNIExample.o

Step 4(Run java code):
	java JNIExample
