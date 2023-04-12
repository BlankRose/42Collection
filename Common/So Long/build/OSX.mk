# ********************************************************************* #
#          .-.                                                          #
#    __   /   \   __                                                    #
#   (  `'.\   /.'`  )   So Long - OSX.mk                                #
#    '-._.(;;;)._.-'                                                    #
#    .-'  ,`"`,  '-.                                                    #
#   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        #
#       //\   /         Last Updated: Wed Apr 12 13:25:42 CEST 2023     #
#      ||  '-'                                                          #
# ********************************************************************* #

#       /\\                                                          
#      /  \\    CAUTION: Dont touch below unless you know what you   
#     / || \\      are doing! If you think it needs improvement,     
#    /  ..  \\     feels free to make a Pull Request. Thanks :)      
#   /========\\                                                      



#==--------------------------------------==#
# *                                      * #
#              SPECIAL MACROS              #
# *                                      * #
#==--------------------------------------==#

# LANGUAGE CORRECTOR
LANG_LOW = $(shell echo "$(LANGUAGE)" | tr '[:upper:]' '[:lower:]')
ifneq (, $(filter asm s assembly, $(LANG_LOW)))
	FILE_EXTENSION := .cpp
else ifneq (, $(filter c, $(LANG_LOW)))
	FILE_EXTENSION := .c
else ifneq (, $(filter cpp c++, $(LANG_LOW)))
	FILE_EXTENSION := .s
else
	FILE_EXTENSION := .$(LANGUAGE)
endif


# SOURCES MANAGEMENT
ifneq ($(GENERIC_FOLDER), )
	SRC		= $(foreach file, $(GENERIC_FILES), $(GENERIC_FOLDER)$(FOLD)$(file)$(FILE_EXTENSION))
else
	SRC 	= $(foreach file, $(GENERIC_FILES), $(file)$(FILE_EXTENSION))
endif
ifneq ($(BIN_FOLDER), )
	OBJ		= $(foreach file, $(GENERIC_FILES), $(BIN_FOLDER)$(FOLD)$(file).o)
else
	OBJ		= $(SRC:$(FILE_EXTENSION)=.o)
endif
HEADERS		= $(foreach inc, $(INCLUDES), $(shell find $(inc) -type f -name "*.h"))
ifneq ($(SOURCES), )
	SRC		+= $(SOURCES)
	OBJ		+= $(OBJECTS)
endif


# COMPILATION CONTROL
LINKS		= $(addprefix -L, $(LIB_FOLDER)) \
			  $(addprefix -l, $(LIB_FILES)) \
			  $(EXT_BINARIES) $(LINKER_PARAMS)
FLAGS		= $(addprefix -I, $(INCLUDES)) \
			  $(addprefix -D, $(DEFINES)) \
			  $(EXTRA_PARAMS)
ifeq ($(COMPILER), default)
	ifeq ($(FILE_EXTENSION), .cpp)
		COMPILER = c++
	else ifeq ($(FILE_EXTENSION), .c)
		COMPILER = gcc
	else
		COMPILER = gcc
	endif
endif


# SYSTEM CONTROL
FOLD			= /
NOERR			= || true
SILENT			= > /dev/null 2>&1
STOP			= && false
CONTINUE		= $(SILENT) $(NOERR)
ifeq ($(SILENCE_OTHER), true)
	SILENT_MK	= $(SILENT)
endif
ifeq ($(SILENCE_THIS), true)
	SILENT_TS	= $(SILENT)
endif


# PRE-GENERATED COMMANDS
CMD_COMPILE		= $(COMPILER) $(FLAGS) -o $@ -c $<
CMD_COMPILE_ASM	= nasm $(FLAGS) -o $@ -c $<
CMD_MKDIR		= mkdir -p $(shell dirname $@) $(CONTINUE)
ifneq ($(EXT_FOLDER), )
	GO_EXT		= mkdir $(EXT_FOLDER) $(SILENT); cd $(EXT_FOLDER) $(SILENT);
endif
GET_REPOS		= $(GO_EXT) $(foreach rep, $(REPOSITORIES), git clone $(rep) $(CONTINUE); )
MAKE_REQUIERD	= $(GO_EXT) $(foreach dir, $(REQUIERD), make -sC $(dir) $(SILENT_MK); )
MAKE_CLEAR		= $(GO_EXT) $(foreach dir, $(REQUIERD), make fclean -sC $(dir) $(SILENT_MK); )



#==--------------------------------------==#
# *                                      * #
#              MAKEFILE RULES              #
# *                                      * #
#==--------------------------------------==#

d: lib/libft.a
requierd: lib/libft.a
lib/libft.a:
ifneq ($(REPOSITORIES), )
	@printf "$(GET_NEEDING)" $(SILENT_TS)
	@$(GET_REPOS)
endif
ifneq ($(REQUIERD), )
	@printf "$(CMP_NEEDING)" $(SILENT_TS)
	@$(MAKE_REQUIERD)
endif

$(BIN_FOLDER)/%.o: $(GENERIC_FOLDER)/%.s $(HEADERS)
	@$(CMD_MKDIR) $(SILENT_TS)
	@printf "$(CMP_WORKING)" $(SILENT_TS)
	@$(CMD_COMPILE_ASM) $(SILENT_TS)

$(BIN_FOLDER)/%.o: $(GENERIC_FOLDER)/%.c $(HEADERS)
	@$(CMD_MKDIR) $(SILENT_TS)
	@printf "$(CMP_WORKING)" $(SILENT_TS)
	@$(CMD_COMPILE) $(SILENT_TS)

$(BIN_FOLDER)/%.o: $(GENERIC_FOLDER)/%.cpp $(HEADERS)
	@$(CMD_MKDIR) $(SILENT_TS)
	@printf "$(CMP_WORKING)" $(SILENT_TS)
	@$(CMD_COMPILE) $(SILENT_TS)

.s.o: $(HEADERS)
	@printf "$(CMP_WORKING)" $(SILENT_TS)
	@$(CMD_COMPILE_ASM) $(SILENT_TS)

.c.o: $(HEADERS)
	@printf "$(CMP_WORKING)" $(SILENT_TS)
	@$(CMD_COMPILE) $(SILENT_TS)

.cpp.o: $(HEADERS)
	@printf "$(CMP_WORKING)" $(SILENT_TS)
	@$(CMD_COMPILE) $(SILENT_TS)

ifneq ($(REQUIERD), )
$(NAME): lib/libft.a $(OBJ)
else ifneq ($(REPOSITORIES), )
$(NAME): lib/libft.a $(OBJ)
else
$(NAME): $(OBJ)
endif
	@printf "$(CMP_WORKING)" $(SILENT_TS)
ifeq ($(suffix $(NAME)), .a)
	@ar -rc $(NAME) $(OBJ)
	@printf "$(LIB_SUCCESS)" $(SILENT_TS)
else
	@$(COMPILER) -o $(NAME) $(OBJ) $(LINKS) $(FLAGS)
	@printf "$(CMP_SUCCESS)" $(SILENT_TS)
endif

p: package
pkg: package
package: all
	@mkdir $(PKG_FOLDER) $(CONTINUE)
	@cp $(NAME)$(CMD_EXE) $(PKG_FOLDER) $(foreach i, $(PKG_REQUIERD), && cp -R $(i) $(PKG_FOLDER))
	@printf "$(PKG_SUCCESS)" $(SILENT_TS)

c: clean
clean:
ifeq ($(BIN_FOLDER), )
	@printf "$(CLR_WORKING)" $(SILENT_TS)
	@rm -Rf $(OBJ) $(SILENT)
	@printf "$(CLR_SUCCESS)" $(SILENT_TS)
else
	@if [ -d ./$(BIN_FOLDER) ]; \
		then rm -Rf $(BIN_FOLDER) \
		&&   printf "$(CLR_SUCCESS)" $(SILENT_TS); \
		else printf "$(CLR_FAILURE)" $(SILENT_TS); \
	fi
endif

fc: fullclean
fclean: fullclean
fullclean: clean
	@if [ -f $(NAME)$(CMD_EXE) ]; \
		then rm -Rf $(NAME)$(CMD_EXE) \
		&&   printf "$(CLR_EXECUTE)" $(SILENT_TS); \
		else printf "$(CLR_EXEFAIL)" $(SILENT_TS); \
	fi

lc: libclean
libc: libclean
libclean:
	@printf "$(CLR_NEEDING)" $(SILENT_TS)
	@$(MAKE_CLEAR)

dc: dependclean
dependc: dependclean
requierdclean: dependclean
dependclean:
ifeq ($(EXT_FOLDER), )
	@printf $(MISC_NOEXTF)
else
	@if [ -d ./$(EXT_FOLDER) ]; \
		then rm -Rf $(EXT_FOLDER) \
		&&   printf "$(CLR_DEPENDS)"; \
		else printf "$(CLR_DEPFAIL)"; \
	fi
endif

pc: packageclean
pkgc: packageclean
pkgclean: packageclean
packagec: packageclean
packageclean:
	@if [ -d ./$(PKG_FOLDER) ]; \
		then rm -Rf $(PKG_FOLDER) \
		&&   printf "$(CLR_PACKAGE)" $(SILENT_TS); \
		else printf "$(CLR_PKGFAIL)" $(SILENT_TS); \
	fi

tea: drink
coffee: drink
drink:
	@printf "$(MISC_DRINK)$(NUL)"
	@sleep 3
	@printf "$(MISC_READY)$(END)"
	@printf "$(END)"
	@printf "$(DRK)        ██    ██    ██$(END)"
	@printf "$(DRK)      ██      ██  ██$(END)"
	@printf "$(DRK)      ██    ██    ██$(END)"
	@printf "$(DRK)        ██  ██      ██$(END)"
	@printf "$(DRK)        ██    ██    ██$(END)"
	@printf "$(END)"
	@printf "    ████████████████████$(END)"
	@printf "    ██                ██$(DRK)████$(END)"
	@printf "    ██                ██$(DRK)  ██$(END)"
	@printf "    ██                ██$(DRK)  ██$(END)"
	@printf "    ██                ██$(DRK)████$(END)"
	@printf "      ██            ██$(END)"
	@printf "  ████████████████████████$(END)"
	@printf "  ██                    ██$(END)"
	@printf "    ████████████████████$(END)"
	@printf "$(END)"
