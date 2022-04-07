MODULES := src/list.c src/person.c
SOURCES := src/main.c $(MODULES)
TARGET := bin
FULLTARGET := $(CURDIR)/$(TARGET)/linked-list

TESTLIB := $(CURDIR)/testlib
TESTSOURCES := tests/tests.c
TESTOBJECTS := $(TESTSOURCES:%.c=%.o)
TESTDEPS := $(TESTSOURCES:%.c=%.d)
TESTTARGET := $(CURDIR)/tests/runtest

TESTLIBDIR := $(TESTLIB)/lib
TESTINCDIR := $(TESTLIB)/include

CC = gcc
CFLAGS = -g -Wall -std=c99
CPPFLAGS = -MD -Isrc -I$(TESTINCDIR) -DTARGET=$(FULLTARGET)
LDFLAGS = -static

OBJECTS := $(SOURCES:%.c=%.o)
DEPS := $(SOURCES:%.c=%.d)

.PHONY: defaul mkdir clean

default: $(FULLTARGET)
	@echo "#### $< built ####"

$(FULLTARGET): mkdir $(OBJECTS) Makefile
	$(LINK.c) -o $@ $(OBJECTS)

mkdir:
	-mkdir -p $(TARGET)

clean:
	$(RM) -r $(OBJECTS) $(TARGET) $(DEPS)

test: $(TESTTARGET)
	(cd tests; $(TESTTARGET))
	@echo "#### $< executed ####"

$(TESTTARGET): $(FULLTARGET) $(TESTOBJECTS)
	$(LINK.c) -o $(TESTTARGET) $(TESTOBJECTS) -lm -lcunit -L$(TESTLIBDIR) -lsnptest
	@echo "#### $@ built ####"
