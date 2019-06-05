export RM:=del
export NAME:=graph
export CFLAGS+= -Wall -std=c11 -pedantic -Wextra -O1 -I..\include
includes=include\Graph.h

.PHONY: example test install uninstall clean

# возмоно надо добавить цель lib$(NAME).a
build:
	$(MAKE) -C src

example:
	$(MAKE) -C src $(NAME)

test: build
	$(MAKE) -C test

# Установка библиотеки в подпапки указанные в переменной PREFIX.
# После установки можно создать новый проект в другом месте и использовать эту библиотеку из него.
# В зависимостях цели указано, что библиотека должна быть построена сперва
install: build
	copy src\lib$(NAME).a $(PREFIX)\lib
	copy $(includes) $(PREFIX)\include
 
uninstall:
	$(RM) "$(PREFIX)\lib\lib$(NAME).a"
	$(RM) "$(PREFIX)\$(includes)"

clean:
	$(MAKE) -C src clean