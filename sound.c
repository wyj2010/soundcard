#include "sound.h"
#include <stdio.h>

//function definition of displayWAVheader()
void displayWAVheader(char filename[]){
	WAVHeader myhdr;	//an instance of defined struct
	FILE *fp;
	fp = fopen(filename, "r");	//open a file for reading
	if(fp == NULL){		//if fopen is failed
		printf("ERROR of opening file!\n");
		return;
	}
	fread(&myhdr, sizeof(WAVHeader), 1, fp);
	fclose(fp);
	printID(myhdr.chunkID);
	printf("Chunk size: %d\n", myhdr.chunkSize);
	printID(myhdr.format);
	printID(myhdr.subchunk1ID);
	printf("Subchunk 1 size: %d\n", myhdr.subchunk1Size);
	printf("Audio format: %d\n", myhdr.audioFormat);
	printf("Number of channels: %d\n", myhdr.numChannels);
	printf("Sample rate: %d\n", myhdr.sampleRate);
	printf("Byte rate: %d\n", myhdr.byteRate);
	printf("Block align: %d\n", myhdr.blockAlign);
	printf("Bits per sample: %d\n", myhdr.bitsPerSample);
	printID(myhdr.subchunk2ID);
	printf("Sub chunk 2 size: %d\n", myhdr.subchunk2Size);
}
void printID(char id[]){
	int i;
	for(i=0; i<4; i++){
		printf("%c", id[i]);
	}
	printf("\n");
}
/* Function definition of displayBar().This function opens "test.wav" and read the data part of the file.
The sample should be in S16_LE format, and there are 16k of them. The function processes every 200 samples and calculate their RMS values
and render the value as a bar. */
void displayBar(char filename[]){
	int i;
	FILE *fp;
	short int samples(SAMPLERATE);
	WAVHeader myhdr;	//dummy header to skip over the reading from the file
	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("ERROR opening the file!\n");
		return;
	}
	fread(&myhdr, sizeof(WAVHeader), 1, fp);
	fread(&samples, sizeof(short), SAMPLERATE, fp);
	fclose(fp);
	//all the samples of 1sec are read to the array samples[], we need to run a loop 80 times for 80 bars
	//this loop will calculate a RMS value of 200 samples
	for(i=0; i<80; i++){
		
	}
}
