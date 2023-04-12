# ********************************************************************* #
#          .-.                                                          #
#    __   /   \   __                                                    #
#   (  `'.\   /.'`  )   So Long - WindowsNT.mk                          #
#    '-._.(;;;)._.-'                                                    #
#    .-'  ,`"`,  '-.                                                    #
#   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        #
#       //\   /         Last Updated: Wed Mar 22 11:43:03 CET 2023      #
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
ifneq (, $(filter CPP CPp Cpp cPP cPp cpP cpp c++ C++, $(LANGUAGE)))
	FILE_EXTENSION := .cpp
else ifneq (, $(filter C c, $(LANGUAGE)))
	FILE_EXTENSION := .c
else
	FILE_EXTENSION := .$(LANGUAGE)
endif


# SOURCES MANAGEMENT
ifneq ($(GENERIC_FOLDER), )
	SRC		= $(foreach file, $(GENERIC_FILES), $(GENERIC_FOLDER)$(FOLD)$(file)$(FILE_EXTENSION))
else
	SRC 	= $(foreach file, $(GENERIC_FILES), $(file)$(FILE_EXTENSION))
endif
OBJ			= $(SRC:$(FILE_EXTENSION)=.o)
POBJ		= $(OBJ)
ifneq ($(SOURCES), )
	SRC		+= $(SOURCES)
	OCJ		+= $(OBJECTS)
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
FOLD			= \\ 
NOERR			= || exit 0
SILENT			= > NUL 2>&1
STOP			= && exit 1
CONTINUE		= $(SILENT) $(NOERR)
ifeq ($(SILENCE_OTHER), true)
	SILENT_MK	= $(SILENT)
endif
ifeq ($(SILENCE_THIS), true)
	SILENT_TS	= $(SILENT)
endif


# PRE-GENERATED COMMANDS
CMD_COMPILE		= $(COMPILER) $(FLAGS) -o $@ -c $<
CMD_COMPBIN		= $(COMPILER) $(FLAGS) -o $(BIN_FOLDER)$(FOLD)$(shell basename $@) -c $<
CMD_PRINT		= echo
CMD_CLEAR		= del /f /q /s
ifneq ($(suffix $(NAME)), .a)
	CMD_EXE		= .exe
endif
ifneq ($(EXT_FOLDER), )
	GO_EXT		= ((mkdir $(EXT_FOLDER) $(SILENT) && cd $(EXT_FOLDER) $(SILENT)) || cd $(EXT_FOLDER) $(SILENT))
else
	GO_EXT		= exit 0
endif
GET_REPOS		= $(GO_EXT) $(foreach rep, $(REPOSITORIES), && (git clone $(rep) $(SILENT) || git pull $(r) $(SILENT)) )
MAKE_REQUIERD	= $(GO_EXT) $(foreach dir, $(REQUIERD), && make -C $(dir) $(SILENT_MK) )
MAKE_CLEAR		= $(GO_EXT) $(foreach dir, $(REQUIERD), && make fclean -C $(dir) $(SILENT_MK) )



#==--------------------------------------==#
# *                                      * #
#              MAKEFILE RULES              #
# *                                      * #
#==--------------------------------------==#

d: dependencies
requierd: dependencies
dependencies:
ifneq ($(REPOSITORIES), )
	@echo $(GET_NEEDING) $(SILENT_TS)
	@$(GET_REPOS)
endif
ifneq ($(REQUIERD), )
	@echo $(CMP_NEEDING) $(SILENT_TS)
	@$(MAKE_REQUIERD)
endif

$(BIN_FOLDER)/%.o: $(GENERIC_FOLDER)/%.c
	@mkdir $(BIN_FOLDER) $(CONTINUE) $(SILENT_TS)
	@echo $(CMP_WORKING) $(SILENT_TS)
	@$(CMD_COMPBIN) $(SILENT_T)S

$(BIN_FOLDER)/%.o: $(GENERIC_FOLDER)/%.cpp
	@mkdir $(BIN_FOLDER) $(CONTINUE) $(SILENT_TS)
	@echo $(CMP_WORKING) $(SILENT_TS)
	@$(CMD_COMPBIN) $(SILENT_TS)

.c.o:
	@echo $(CMP_WORKING) $(SILENT_TS)
	@$(CMD_COMPILE) $(SILENT_TS)

.cpp.o:
	@echo $(CMP_WORKING) $(SILENT_TS)
	@$(CMD_COMPILE) $(SILENT_TS)

ifneq ($(REQUIERD), )
$(NAME): dependencies $(OBJ)
else ifneq ($(REPOSITORIES), )
$(NAME): dependencies $(OBJ)
else
$(NAME): $(OBJ)
endif
	@echo $(CMP_WORKING) $(SILENT_TS)
ifeq ($(suffix $(NAME)), .a)
	@ar -rc $(NAME) $(POBJ)
	@echo $(LIB_SUCCESS) $(SILENT_TS)
else
	@$(COMPILER) -o $(NAME) $(POBJ) $(LINKS) $(FLAGS)
	@echo $(CMP_SUCCESS) $(SILENT_TS)
endif

p: package
pkg: package
package: all
	@mkdir $(PKG_FOLDER) $(CONTINUE)
	@cp $(NAME)$(CMD_EXE) $(PKG_FOLDER) $(foreach i, $(PKG_REQUIERD), && cp -R $(i) $(PKG_FOLDER))
	@echo $(PKG_SUCCESS) $(SILENT_TS)

c: clean
clean:
ifeq ($(BIN_FOLDER), )
	@echo $(CLR_WORKING) $(SILENT_TS)
	@$(CMD_CLEAR) $(OBJ) $(SILENT)
	@echo $(CLR_SUCCESS) $(SILENT_TS)
else
	@if [ -d ./$(BIN_FOLDER) ]; \
		then $(CMD_CLEAR) $(BIN_FOLDER) \
		&&   echo $(CLR_SUCCESS) $(SILENT_TS); \
		else echo $(CLR_FAILURE) $(SILENT_TS); \
	fi
endif

fc: fullclean
fclean: fullclean
fullclean: clean
	@if [ -f $(NAME)$(CMD_EXE) ]; \
		then $(CMD_CLEAR) $(NAME)$(CMD_EXE) \
		&&   echo $(CLR_EXECUTE) $(SILENT_TS); \
		else echo $(CLR_EXEFAIL) $(SILENT_TS); \
	fi

lc: libclean
libc: libclean
libclean:
	@echo $(CLR_NEEDING) $(SILENT_TS)
	@$(MAKE_CLEAR)

dc: dependclean
dependc: dependclean
requierdclean: dependclean
dependclean:
ifeq ($(EXT_FOLDER), )
	@echo $(MISC_NOEXTF)
else
	@if [ -d ./$(EXT_FOLDER) ]; \
		then $(CMD_CLEAR) $(EXT_FOLDER) \
		&&   echo $(CLR_DEPENDS); \
		else echo $(CLR_DEPFAIL); \
	fi
endif

pc: packageclean
pkgc: packageclean
pkgclean: packageclean
packagec: packageclean
packageclean:
	@if [ -d ./$(PKG_FOLDER) ]; \
		then $(CMD_CLEAR) $(PKG_FOLDER) \
		&&   echo $(CLR_PACKAGE) $(SILENT_TS); \
		else echo $(CLR_PKGFAIL) $(SILENT_TS); \
	fi

tea: drink
coffee: drink
drink:
	@echo $(MISC_DRINK)
	@sleep 3
	@echo $(MISC_READY)
	@echo 
	@echo $(DRK)        ██    ██    ██
	@echo $(DRK)      ██      ██  ██ 
	@echo $(DRK)      ██    ██    ██ 
	@echo $(DRK)        ██  ██      ██
	@echo $(DRK)        ██    ██    ██
	@echo 
	@echo     ████████████████████
	@echo     ██                ██$(DRK)████
	@echo     ██                ██$(DRK)  ██
	@echo     ██                ██$(DRK)  ██
	@echo     ██                ██$(DRK)████
	@echo       ██            ██
	@echo   ████████████████████████
	@echo   ██                    ██
	@echo     ████████████████████
	@echo 
