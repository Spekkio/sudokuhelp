AUTOMAKE_OPTIONS = subdir-objects

ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS} -I m4

include aminclude.am

MOSTLYCLEANFILES = $(DX_CLEANFILES)

AM_CFLAGS = -pedantic -Wall -Wextra -Werror

AM_CPPFLAGS =$(DEPS_CFLAGS)

bin_PROGRAMS = sudokuhelp

sudokuhelp_SOURCES = src/detect.c src/draw.c src/globals.h src/setup.c src/sort.c src/detect.h src/draw.h src/main.c src/setup.h src/sort.h config.h

sudokuhelp_LDADD = $(DEPS_LIBS)

EXTRA_DIST = autogen.sh $(DX_CONFIG) doc/html
