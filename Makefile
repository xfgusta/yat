yat:
	gcc yat.c -o yat

install:
	mkdir -p $(DESTDIR)/usr/bin
	install -m 0755 yat $(DESTDIR)/usr/bin/yat

uninstall:
	rm -f $(DESTDIR)/usr/bin/yat

clean:
	rm -f yat
