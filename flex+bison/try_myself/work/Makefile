work:	work.l work.y work.h workfun.c
	bison -d work.y && \
	flex -owork.lex.c work.l && \
	cc -g -o $@ work.tab.c work.lex.c workfun.c -lm

.PHONY: clean
clean:
	rm -f work.tab.c work.lex.c work.tab.h
