#define BUFFER_SIZE 1024

typedef struct buffer {
	char data[BUFFER_SIZE];	
	int len;
	int start;
} BUF;

void printBuffer(BUF *buffer) {
	int i;
	for(i = 0; i < 20; i++) {
		printf("%d: 0x%x  | ", i, buffer->data[i]);
	}
	printf("\n");
	printf("Buffer len: %d\n", buffer->len);
	printf("Buffer start: %d\n", buffer->start);
}

BUF *newBuffer() {
	BUF *buffer;
	buffer = malloc(sizeof(BUF));
	buffer->len = 0;
	buffer->start = 0;
	buffer->checksum = 0;
	return buffer;
}

void pushBufferByte(BUF *buffer, char c) {
	//printf("Pushing byte: 0x%x\n", c);
	buffer->data[buffer->len] = c;		
	buffer->len++;
}

void bufferIndex(BUF *buffer, int index, char c) {
	buffer->data[index] = c;
}

void pushBuffer(BUF *buffer, char *c, int length) {
	sprintf(&(buffer->data[buffer->len]), "%s", c);
	buffer->len += length;
}

int popBuffer(BUF *buffer, char *c) {
	if(buffer->start == buffer->len) {
		printf("Nothing left to pop\n");
		return -1;
	}
	*c = buffer->data[buffer->start];
	buffer->start++;	
	return 1;
}
