# Copyright (C) 2017 Daniel Page <csdsp@bristol.ac.uk>
#
# Use of this source code is restricted per the CC BY-NC-ND license, a copy of 
# which can be found via http://creativecommons.org (and should be included as 
# LICENSE.txt within the associated archive or repository).

# =============================================================================

UNAME   := $(shell uname -s)

SOURCES  = $(wildcard *.c)
TARGETS  = $(patsubst %.c, %, ${SOURCES})

# -----------------------------------------------------------------------------

${TARGETS} : % : %.c %.h
	@gcc -Wall -std=gnu99 -O3 -o ${@} $(filter %.c, ${^})

# -----------------------------------------------------------------------------

all   :             ${TARGETS}

ifeq (${UNAME},Linux)
clean    :
	@rm --force ${TARGETS}
endif
ifeq (${UNAME},Darwin)
clean    :
	@rm -f      ${TARGETS}
endif

# =============================================================================
