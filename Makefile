all:
	javac JNIExample.java -h .
	g++ -c JNIExample.cpp -I "C:\Program Files\Java\jdk-15.0.1\include" -I "C:\Program Files\Java\jdk-15.0.1\include\win32" -L "C:\Program Files\Java\jdk-15.0.1\lib" -ljvm -pthread
	g++ -shared -o JNIExample.dll JNIExample.o