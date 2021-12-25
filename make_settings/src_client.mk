ifndef SRC_CLIENT_MK
SRC_CLIENT_MK = 1

EXEC_CLIENT := client

SDIR_CLIENT := src_client/src
ODIR_CLIENT := src_client/obj
IDIR_CLIENT := src_client/includes

SRC_CLIENT :=	src_client/src/send_data.c \
				src_client/src/utils.c \
				src_client/src/valid_args.c \
				src_client/src/main.c \
				src_client/src/ft_atoi.c

OBJ_CLIENT :=	$(patsubst $(SDIR_CLIENT)%.c,$(ODIR_CLIENT)%.o,$(SRC_CLIENT))

IFLAG_CLIENT := -I$(IDIR_CLIENT)

endif # SRC_CLIENT_MK
