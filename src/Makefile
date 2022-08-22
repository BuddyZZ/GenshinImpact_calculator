#$@--目标文件，$^--所有的依赖文件，$<--第一个依赖文件。
target=calculator
#
objects=origin.o character.o enemy.o environment.o artifact.o  weapon.o logger.o calculate.o main.o 
flags=-std=c++11 -std=gnu++11
#flags=''
${target}:${objects}
	g++ ${flags} -o ${@} ${objects} 

.PHONY : clean 
clean:
	-rm ${target} ${objects}
