echo -e "position startpos\nquit" | ../challenger

gprof -b -p ../challenger gmon.out
