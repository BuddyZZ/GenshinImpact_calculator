SUB_DIR=./src
MAKE=make
ALL:
	cd ${SUB_DIR} && ${MAKE}
.PHONY : clean 
clean:
	cd ${SUB_DIR} && ${MAKE} clean
