all:
	g++ sha512.cpp main.cpp -o keygen
	echo "Now, run make install"
install:
	cp keygen /usr/bin
