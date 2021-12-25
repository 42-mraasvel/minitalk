NAME = server client

include make_settings/settings.mk
include make_settings/src_client.mk
include make_settings/src_server.mk

.PHONY: all
all: $(NAME)

# Name rule doesn't really do anything in this case
$(NAME):

# Server
$(EXEC_SERVER): $(OBJ_SERVER)
	@echo "$(GREEN)""compiling executable server" "$(CLEAR)"
	@$(CC) $(CFLAGS) $(OBJ_SERVER) -o $@
$(OBJ_SERVER): $(ODIR_SERVER)/%.o: $(SDIR_SERVER)/%.c
	@echo "$(BLUE)"creating server $@ "$(CLEAR)"
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) $(IFLAG_SERVER) -o $@ $<

# Client
$(EXEC_CLIENT): $(OBJ_CLIENT)
	@echo "$(GREEN)""compiling executable client" "$(CLEAR)"
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $@
$(OBJ_CLIENT): $(ODIR_CLIENT)/%.o: $(SDIR_CLIENT)/%.c
	@echo "$(BLUE)"creating client $@ "$(CLEAR)"
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) $(IFLAG_CLIENT) -o $@ $<

# Cleanup
.PHONY: clean fclean re
clean:
	@$(ECHO) "$(RED)"
	$(RM) -r $(ODIR_CLIENT)
	$(RM) -r $(ODIR_SERVER)
	@$(ECHO) "$(CLEAR)"
fclean: clean
	@$(ECHO) "$(RED)"
	$(RM) $(NAME)
	@$(ECHO) "$(CLEAR)"
re: fclean
	$(MAKE) all

# Dependency rules
-include $(DEP_CLIENT)
-include $(DEP_SERVER)
