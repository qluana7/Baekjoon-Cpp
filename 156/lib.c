/*
 * The library of 156/0 coding.
 * ** read_ex has bug. Please don't use it **
 *
 * When use function, replace "#define type" to type want to use
 * 
 * Tip :
 *   Declare input buffer and pointer for input buffer
 * 
 *   ex) char buffer[100], *buffer_pointer = buffer;
 * 
 *   Because this functions modify pointer position.
 * 
 * 
 *   Or use buffer sturcture
 * 
 *   ex)
 *   char b[100]; buffer buf;
 *   buf.buffer = b;
 *   buf.bufpos = b;
 *   buf.size = 100;
 *   buf.position = 0;
 */

/* 
 * Description :
 *   Type definition
 *
 * Defines :
 *   - type_t : The type for return or parameter
 *   - size_t : The type for size
 */

#define type_t int
#define size_t unsigned int

/* 
 * Description :
 *   The buffer structure
 * 
 * Member :
 *   - buffer : The buffer that data will store
 *   - bufpos : Current buffer pointer
 *   - size : Buffer size
 *   - position : Position of bufpos
 * 
 * Notes :
 *   When declare this struct, you have to init buffer and set size.
 *   And bufpos set to buffer. Default value of position is 0.
 * 
 *   Because you can't use malloc, you have to set buffer
 *   with stack variable.
 */

typedef struct {
    char* buffer,* bufpos;
    size_t size, position;
} buffer;

/*
 * Description :
 *   The function clear used buffer and read more from stdin.
 * 
 * Parameters :
 *   - zb : Input buffer
 *   - bsize : Buffer size
 *   - pos : Buffer position
 * 
 * Return :
 *   None
 * 
 * Notes :
 *   This function clear used value in buffer.
 *   Then, read from stdin.
 * 
 *   After call, need to set buffer pointer to start of buffer.
 */

void read_ex(char* zb, size_t bsize, size_t pos) {
    if (pos == 0) return;
    
    size_t msize = bsize - pos;
    memmove(zb, zb + pos, msize);
    
    char* b = zb + msize;
    syscall(0, 0, b, pos);
}

void buffer_read_ex(buffer* buf) {
    if (buf->position == 0) return;
    
    size_t msize = buf->size - buf->position;
    memmove(buf->buffer, buf->buffer + buf->position, msize);
    
    char* b = buf->buffer + msize;
    syscall(0, 0, b, buf->position);
    
    buf->position = 0;
    buf->bufpos = buf->buffer;
}

/*
 * Description :
 *   The function write to stdout
 * 
 * Parameters :
 *   - zb : Output buffer
 *   - len : length of output
 * 
 * Return :
 *   None
 * 
 * Notes :
 *   This function continues even if letter is '\0'
 */

void write(char* zb, size_t len) {
    syscall(1, 1, zb, len);
}

void buffer_write(buffer* buf, size_t len) {
    syscall(1, 1, buf->bufpos, len);
}

/*
 * Description :
 *   The function return value read from input buffer
 * 
 * Parameters :
 *   - zb : Input buffer
 * 
 * Return :
 *   A value read from input buffer
 * 
 * Notes :
 *   After read, buffer pointer will point to
 *   Next starting position.
 * 
 *   For example, if input is "100 300",
 *   after function called, pointer will point to '3'.
 */

#define digit(c) ('0' <= c && c <= '9')

type_t readi(char* b) {
	type_t n = 0;
	while (*b && digit(*b))
		n = n * 10 + *b++ - '0';
	b++;
	
	return n;
}

/* This version modify buffer pointer */
type_t readi(char** zb) {
	char* b = *zb;
	
	type_t n = 0;
	while (*b && digit(*b))
		n = n * 10 + *b++ - '0';
	b++;
	
	*zb = b;
	
	return n;
}

type_t buffer_readi(buffer* buf) {
	char* b = buf->bufpos;
	
	type_t n = 0;
	while (*b && digit(*b))
    { n = n * 10 + *b++ - '0'; buf->position++; }
	b++; buf->position++;
	
	buf->bufpos = b;
	
	return n;
}

/*
 * Description :
 *   The function that set value to output buffer
 *   and return its length
 * 
 * Parameters :
 *   - zb : Output buffer
 *   - n : Value to convert
 *   - c : Char that will place on end of output
 * 
 * Return :
 *   Length of output
 * 
 * Notes :
 *   The length is value that exclude last char.
 *   It is same as { (int)log10(n) + 1 }
 */

int itoa(char* buf, int n, char c) {
    char *tmp = buf;
	int q = 0, t = 0; char neg = 0;
    
    if (n < 0) { *buf = '-'; buf++; neg = 1; n = -n; }
	
	if (n == 0) {
		*buf = 48; buf++;
		*buf = c;
		
		return 1 + neg;
	}
	
	while (n != 0) { *buf++ = n % 10 + 48; n /= 10; q++; }
	
	for (int i = 0, l = q >> 1; i < l; i++) {
		char* st = tmp + i, *ed = buf - i - 1;
		char tc = *st; *st = *ed; *ed = tc;
	}
	
	*buf = c;
	
	return q + neg;
}

/* This version modify buffer pointer */
type_t itoa(char** zb, type_t n, char c) {
	char* buf = *zb;
	type_t q = 0, t = 0; char neg = 0;
    
    if (n < 0) { *buf = '-'; buf++; neg = 1; n = -n; }
	
	if (n == 0) {
		*buf = 48; buf++;
		*buf = c;
		
		*zb = buf;
		
		return 1 + neg;
	}
	
	while (n != 0) { *buf++ = n % 10 + 48; n /= 10; q++; }
	
	for (int i = 0, l = q >> 1; i < l; i++) {
		char* st = *zb + i, *ed = buf - i - 1;
		char tc = *st; *st = *ed; *ed = tc;
	}
	
	*buf = c;
	
	*zb = buf;
	
	return q + neg;
}

type_t buffer_itoa(buffer* buf, type_t n, char c) {
	char* b = buf->bufpos;
	type_t q = 0; char neg = 0;
    
    if (n < 0) { *b = '-'; b++; buf->position++; neg = 1; n = -n; }
	
	if (n == 0) {
		*b = 48; b++; buf->position++;
		*b = c;
		
		buf->bufpos = b;
		
		return 1 + neg;
	}
	
	while (n != 0) { *b++ = n % 10 + 48; n /= 10; q++; }
	
	for (int i = 0, l = q >> 1; i < l; i++) {
		char* st = buf->bufpos + i, *ed = b - i - 1;
		char tc = *st; *st = *ed; *ed = tc;
	}
	
	*b = c;
	
	buf->bufpos = b;
    buf->position += q + neg;
	
	return q + neg;
}

/*
 * Description :
 *   The function that return size of string
 * 
 * Parameters :
 *   - zb : Start position of string.
 * 
 * Return :
 *   Length of string.
 * 
 * Notes :
 *   This function reads value from buffer until meet '\0'.
 *   The length is value that exclude '\0'.
 */

size_t strlen(char* zb) {
	size_t r = 0;
	while (*zb != '\n' && *zb != 0) { zb++; r++; }
	
	return r;
}

/*
 * Description :
 *   The function that copy string to source string.
 * 
 * Parameters :
 *   - src : Source string
 * 	 - data : Data String
 * 
 * Return :
 *   None
 * 
 * Notes :
 *   This function copy value from data until meet '\0'.
 *   '\0' is inserted at the end of the source.
 */

void strcpy(char* src, char* data) {
    for (;*data; src++, data++) *src = *data;
    *(++src) = '\0';
}