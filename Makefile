MODULES := src/list.c src/person.c
SOURCES := src/main.c $(MODULES)
TARGET := bin
FULLTARGET := $(CURDIR)/$(TARGET)/linked-list

CC = gcc
CFLAGS = -g -Wall -std=c99
CPPFLAGS = -MD -Isrc -DTARGET=$(FULLTARGET)

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
