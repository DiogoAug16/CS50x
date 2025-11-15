CC = clang
CFLAGS = -I/usr/local/include -std=c11 -Wall -Werror -ggdb3
LDFLAGS = -L/usr/local/lib
LDLIBS = -lcs50 -lm

%: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@ $(LDLIBS)

clean:
	rm -f *.o compare hello foo