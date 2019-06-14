#include <jni.h>

int main(int argc, char **argv)
{
	JavaVM         *vm;
	JNIEnv         *env;
	JavaVMInitArgs  vm_args;
	jint            res;
	jclass          cls;
	jmethodID       mid;
	jstring         jstr;
	jobjectArray    main_args;

	vm_args.version  = JNI_VERSION_1_8;
	vm_args.nOptions = 1;
	JavaVMOption options[1];
  	options[0].optionString    = "-Djava.class.path=/home/ubuntu/environment";
  	vm_args.options            = options;
  	vm_args.nOptions           = 1;
  	vm_args.ignoreUnrecognized = JNI_TRUE;

	res = JNI_CreateJavaVM(&vm, (void **)&env, &vm_args);
	if (res != JNI_OK) {
		printf("Failed to create Java VMn");
		return 1;
	}

	cls = (*env)->FindClass(env, "Program");
	if (cls == NULL) {
		printf("Failed to find Main classn");
		return 1;
	}

	mid = (*env)->GetStaticMethodID(env, cls, "main", "([Ljava/lang/String;)V");
	if (mid == NULL) {
		printf("Failed to find main functionn");
		return 1;
	}

	jstr      = (*env)->NewStringUTF(env, "");
	main_args = (*env)->NewObjectArray(env, 1, (*env)->FindClass(env, "java/lang/String"), jstr);
	(*env)->CallStaticVoidMethod(env, cls, mid, main_args);

	return 0;
}
