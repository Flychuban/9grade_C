all: writeParticipants.exe readParticipants.exe changeParticipant.exe

writeParticipants.exe: date.h fileUtil.h participant.h participant.o writeParticipants.c
	gcc writeParticipants.c participant.o -o writeParticipants.exe

readParticipants.exe: date.h fileUtil.h participant.h participant.o readParticipants.c
	gcc readParticipants.c participant.o -o readParticipants.exe

changeParticipant.exe: date.h fileUtil.h participant.h participant.o changeParticipant.c
	gcc changeParticipant.c participant.o -o changeParticipant.exe

participant.o: participant.h participant.c
	gcc -c participant.c -o participant.o

clean:
	del *.o *.exe