all: fillPatientData.exe readPatients.exe

fillPatientData.exe: patient.h fillPatientData.c patient.o fileUtil.h
	gcc fillPatientData.c patient.o -o fillPatientData.exe

readPatients.exe: patient.h readPatients.c patient.o fileUtil.h patientLinkedList.o
	gcc readPatients.c patient.o patientLinkedList.o -o readPatients.exe

patient.o: patient.h patient.c
	gcc -c patient.c -o patient.o

patientLinkedList.o: patientLinkedList.c patientLinkedList.h patient.h
	gcc -c patientLinkedList.c -o patientLinkedList.o

clean: 
	del *.o *.exe