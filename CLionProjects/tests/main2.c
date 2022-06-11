#define MYERR(...) do{ \
	printf("@ %s (%d): ", __FILE__, __LINE__); \
	printf(__VA__ARGS__); \
}while(0)
