ifndef SRC_SERVER_MK
SRC_SERVER_MK = 1

EXEC_SERVER := server

SDIR_SERVER := src_server/src
ODIR_SERVER := src_server/obj
IDIR_SERVER := src_server/includes

SRC_SERVER :=	src_server/src/handle_signal.c \
				src_server/src/vecstr_bit.c \
				src_server/src/utils.c \
				src_server/src/main.c \
				src_server/src/ft_putnum.c \
				src_server/src/vecstr.c

OBJ_SERVER :=	$(patsubst $(SDIR_SERVER)%.c,$(ODIR_SERVER)%.o,$(SRC_SERVER))

IFLAG_SERVER := -I$(IDIR_SERVER)

endif # SRC_SERVER_MK
