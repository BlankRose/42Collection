# ********************************************************************* #
#          .-.                                                          #
#    __   /   \   __                                                    #
#   (  `'.\   /.'`  )   So Long - General.mk                            #
#    '-._.(;;;)._.-'                                                    #
#    .-'  ,`"`,  '-.                                                    #
#   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        #
#       //\   /         Last Updated: Thu Mar 23 15:44:11 CET 2023      #
#      ||  '-'                                                          #
# ********************************************************************* #

a: all
everything: all
all: $(NAME)

ac: allclean
allc: allclean
allclean: libclean fullclean packageclean

tc: trueclean
truec: trueclean
trueclean: allclean dependclean

re: remake
remake: fullclean all

ra: remakeall
remakeall: allclean all

ifneq ($(NAME), run)
r: run
run: all
else
t: test
test: all
endif
	@./$(NAME) $(ARGUMENTS)

#####   DLC PACK   #####
# Additional rules, which is only defined for
# this given project (not part of the C-Template)

n: norminette
norm: norminette
norminette:
	@norminette `find $(GENERIC_FOLDER) inc -type f`

f: fix
fix:
	@install_name_tool -change libmlx.dylib ./mlx/libmlx.dylib $(NAME)

#####   RUINS   #####
# Old artifact used for making loading bars
# Its left as a remain in case I want to reimplement them better..

#	CMP_WORK_CT	= $(MSG_WORK) [$(CMP_COUNT) / $(CMP_TOTAL)] Compiling $@ ... $(MSG_NRET)
#	CMP_TOTAL	= $(shell awk -F' ' '{printf NF}' <<< "$(SRC)")
#	CMP_COUNT	= 0

#	@$(CMD_PRINT) $(CMP_WORK_CT) $(SILENT_TS)
#	@$(eval CMP_COUNT = $(shell expr $(CMP_COUNT) + 1))
