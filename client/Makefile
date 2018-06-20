# Это комментарий, который говорит, что переменная CC указывает компилятор, используемый для сборки
CC=g++ -std=c++14
#Это еще один комментарий. Он поясняет, что в переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS=-c 
SFML_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

all: card_game

card_game: abstractcard.o client.o deck.o droparea.o dropspace.o entitycard.o entitywithpropertycard.o field.o game.o info.o interlayer.o log.o main.o mainwindow.o menu.o party.o player.o propertycard.o pugixml.o sfmlcard.o user.o clientparser.o config.o
	$(CC) abstractcard.o client.o deck.o droparea.o dropspace.o entitycard.o entitywithpropertycard.o field.o game.o info.o interlayer.o log.o main.o mainwindow.o menu.o party.o player.o propertycard.o pugixml.o sfmlcard.o  user.o clientparser.o config.o -o card_game $(SFML_FLAGS)

client.o : client.cpp
	$(CC) $(CFLAGS) client.cpp

abstractcard.o: abstractcard.cpp
	$(CC) $(CFLAGS) abstractcard.cpp

deck.o : deck.cpp
	$(CC) $(CFLAGS) deck.cpp

droparea.o : droparea.cpp
	$(CC) $(CFLAGS) droparea.cpp

dropspace.o : dropspace.cpp
	$(CC) $(CFLAGS) dropspace.cpp

entitycard.o : entitycard.cpp
	$(CC) $(CFLAGS) entitycard.cpp

entitywithpropertycard.o : entitywithpropertycard.cpp
	$(CC) $(CFLAGS) entitywithpropertycard.cpp

field.o : field.cpp
	$(CC) $(CFLAGS) field.cpp

game.o : game.cpp
	$(CC) $(CFLAGS) game.cpp

info.o: info.cpp
	$(CC) $(CFLAGS) info.cpp

interlayer.o : interlayer.cpp
	$(CC) $(CFLAGS) interlayer.cpp

log.o : log.cpp
	$(CC) $(CFLAGS) log.cpp

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

mainwindow.o : mainwindow.cpp
	$(CC) $(CFLAGS) mainwindow.cpp

menu.o : menu.cpp
	$(CC) $(CFLAGS) menu.cpp

party.o : party.cpp
	$(CC) $(CFLAGS) party.cpp

player.o : player.cpp
	$(CC) $(CFLAGS) player.cpp

propertycard.o : propertycard.cpp
	$(CC) $(CFLAGS) propertycard.cpp

pugixml.o : pugixml.cpp
	$(CC) $(CFLAGS) pugixml.cpp

sfmlcard.o : sfmlcard.cpp
	$(CC) $(CFLAGS) sfmlcard.cpp

user.o : user.cpp
	$(CC) $(CFLAGS) user.cpp

clientparser.o : clientparser.cpp
	$(CC) $(CFLAGS) clientparser.cpp

config.o : config.cpp
	$(CC) $(CFLAGS) config.cpp

clean:
	rm -rf *.o card_game