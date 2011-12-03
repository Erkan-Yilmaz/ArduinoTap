
BIN_DIR = /usr/bin
LIB_DIR = /usr/share/arduino/libraries
MAN_DIR = /usr/share/man

install: man
	install ./libraries/ArduinoTap/runino $(BIN_DIR)
	cp -ar ./libraries/ArduinoTap $(LIB_DIR)/ArduinoTap
	cp ./runino.1.gz $(MAN_DIR)/man1

uninstall:
	rm -f $(BIN_DIR)/runino
	rm -rf $(LIB_DIR)/ArduinoTap
	rm -f $(MAN_DIR)/man1/runino.1.gz

pod:
	podchecker libraries/ArduinoTap/runino

man:
	pod2man --name=runino --section=1 --center="User Contributed Arduino Documentation" --release="Arduino 1.0" libraries/ArduinoTap/runino > runino.1
	gzip --best -f runino.1

