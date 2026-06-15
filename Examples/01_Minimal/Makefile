EXEC:=Minimal
CFLAGS=-DNOSIGNALS -DFUNNEL

.PHONY : build-par build-seq clean build
SHELL:=/bin/bash

build-par:
	cc $(EXEC).c -o $(EXEC) -fopenmp $(CFLAGS)

build-seq:
	cc $(EXEC).c -o $(EXEC)_ref $(CFLAGS)

clean:
	rm $(EXEC) $(EXEC)_ref

clean-tmp:
	rm *~


build: build-par build-seq

## Interactive job commands

clean-output:
	rm -rf output/Minimal_interactive

run: clean-output
	./$(EXEC) --trace=0 --ncount=10000000.0 --dir=output/Minimal_interactive --format=McCode --yes -s 1234

profile: build-par
	rocprofv3 -s -- ./$(EXEC) --trace=0 --ncount=1000000.0 --dir=output/Minimal_interactive --format=McCode --yes
