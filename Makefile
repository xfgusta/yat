all:
	cc yat.c -o yat

install:
	install -m 0755 yat /usr/local/bin/yat

uninstall:
	rm -f /usr/local/bin/yat

clean:
	rm -f yat
