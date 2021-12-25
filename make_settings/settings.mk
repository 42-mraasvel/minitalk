ifndef SETTINGS_MK
SETTINGS_MK = 1

# Compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

ifeq ($(shell uname),Linux)
	ECHO = echo -n
else
	ECHO = echo
endif

# Colors
RED		=\033[0;31m
GREEN	=\033[0;32m
YELLOW	=\033[0;33m
BLUE	=\033[0;34m
PINK	=\033[0;35m
CYAN	=\033[0;36m
CLEAR	=\033[0m

endif # SETTINGS_MK
