#$@--目标文件，$^--所有的依赖文件，$<--第一个依赖文件。
target=calculator
objects=main.o para.o character.o weapon.o artifact.o enemy.o calculate.o
#flags=-fmessage-length=0 
#flags=''
${target}:${objects}
	g++ ${flags} -o ${@} ${objects}

.PHONY : clean 
clean:
	-rm ${target} ${objects}
