all: Program.jar CallingJava

LDFLAGS += -L/usr/lib/jvm/java-1.8.0-openjdk-amd64/jre/lib/amd64/jli -L/usr/lib/jvm/java-1.8.0-openjdk-amd64/jre/lib/amd64/server/
LIBS += -ljli -ljvm 
CFLAGS += -I/usr/lib/jvm/java-1.8.0-openjdk-amd64/include/ -I/usr/lib/jvm/java-1.8.0-openjdk-amd64/include/linux/
Program.jar: Program.class
	jar -cvf $@ $^

Program.class: Program.java
	javac Program.java
	
CallingJava: CallingJava.c
	gcc -o $@ $^ ${CFLAGS} ${LDFLAGS} ${LIBS}
