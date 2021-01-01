// Reads raw PCM file format and prints the samples in signed integer format on the standard output.
// Initial version A, Deyan Levski, deyan.levski@gmail.com, 15.07.2014
//
//
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
#define SAMPLE_RATE 48000 // Hz
#define BITS_PER_SAMPLE 32 // bits
#define N_SAMPLES 1602 // n
#define SWAP(a,b) tempr=(a);(a)=(b);(b)=tempr
int convertBitSize(unsigned int in, int bps)
{
	const unsigned int max = (1 << (bps - 1)) - 1;
	return in > max ? in - (max << 1) : in;
}

int readPCM(int *data, unsigned int samp_rate, unsigned int bits_per_samp, unsigned int num_samp)

{
	FILE *fp;
	unsigned char buf;
	unsigned int i, j;
	errno_t err;
	err = fopen_s(&fp,"D:\\readPCM\\file_oneSample.pcm", "rb");
	if (err)
	{
		cout << "file open succefull" << endl;
	}
	for (i = 0; i < num_samp; ++i) {

		unsigned int tmp = 0;

		for (j = 0; j != bits_per_samp; j += 8) {
			fread(&buf, 1, 1, fp);
			tmp += buf << j;
		}

		data[i] = convertBitSize(tmp, bits_per_samp);

	}
	return 0;
}

#pragma once

class CFourier
{
public:
	double pi;
	unsigned long int fundamental_frequency;
	float *vector;
	CFourier(void);
	~CFourier(void);
	// FFT 1D
	void ComplexFFT(float data[], unsigned long number_of_samples, unsigned int sample_rate, int sign);
};


CFourier::CFourier(void)
{
	pi = 4 * atan((double)1); vector = NULL;
}

CFourier::~CFourier(void)
{
	if (vector != NULL)
		delete[] vector;
}

// FFT 1D
void CFourier::ComplexFFT(float data[], unsigned long number_of_samples, unsigned int sample_rate, int sign)
{

	//variables for the fft
	unsigned long n, mmax, m, j, istep, i;
	double wtemp, wr, wpr, wpi, wi, theta, tempr, tempi;

	//the complex array is real+complex so the array 
	//as a size n = 2* number of complex samples
	//real part is the data[index] and 
	//the complex part is the data[index+1]

	//new complex array of size n=2*sample_rate
	if (vector != NULL)
		delete[] vector;

	vector = new float[2 * sample_rate];

	//put the real array in a complex array
	//the complex part is filled with 0's
	//the remaining vector with no data is filled with 0's
	for (n = 0; n<sample_rate; n++)
	{
		if (n<number_of_samples)
			vector[2 * n] = data[n];
		else
			vector[2 * n] = 0;
		vector[2 * n + 1] = 0;
	}

	//binary inversion (note that the indexes 
	//start from 0 witch means that the
	//real part of the complex is on the even-indexes 
	//and the complex part is on the odd-indexes)
	n = sample_rate << 1;
	j = 0;
	for (i = 0; i<n / 2; i += 2) {
		if (j > i) {
			SWAP(vector[j], vector[i]);
			SWAP(vector[j + 1], vector[i + 1]);
			if ((j / 2)<(n / 4)) {
				SWAP(vector[(n - (i + 2))], vector[(n - (j + 2))]);
				SWAP(vector[(n - (i + 2)) + 1], vector[(n - (j + 2)) + 1]);
			}
		}
		m = n >> 1;
		while (m >= 2 && j >= m) {
			j -= m;
			m >>= 1;
		}
		j += m;
	}
	//end of the bit-reversed order algorithm

	//Danielson-Lanzcos routine
	mmax = 2;
	while (n > mmax) {
		istep = mmax << 1;
		theta = sign*(2 * pi / mmax);
		wtemp = sin(0.5*theta);
		wpr = -2.0*wtemp*wtemp;
		wpi = sin(theta);
		wr = 1.0;
		wi = 0.0;
		for (m = 1; m<mmax; m += 2) {
			for (i = m; i <= n; i += istep) {
				j = i + mmax;
				tempr = wr*vector[j - 1] - wi*vector[j];
				tempi = wr*vector[j] + wi*vector[j - 1];
				vector[j - 1] = vector[i - 1] - tempr;
				vector[j] = vector[i] - tempi;
				vector[i - 1] += tempr;
				vector[i] += tempi;
			}
			wr = (wtemp = wr)*wpr - wi*wpi + wr;
			wi = wi*wpr + wtemp*wpi + wi;
		}
		mmax = istep;
	}
	//end of the algorithm

	//determine the fundamental frequency
	//look for the maximum absolute value in the complex array
	fundamental_frequency = 0;
	for (i = 2; i <= sample_rate; i += 2)
	{
		if ((pow(vector[i], 2) + pow(vector[i + 1], 2))>(pow(vector[fundamental_frequency], 2) + pow(vector[fundamental_frequency + 1], 2))) {
			fundamental_frequency = i;
		}
	}

	//since the array of complex has the format [real][complex]=>[absolute value]
	//the maximum absolute value must be ajusted to half
	fundamental_frequency = (long)floor((float)fundamental_frequency / 2);
	cout << fundamental_frequency << endl;

}



int main(void)
{
	CFourier fft;
	//sample rate of the signal (must be 2^n)
	long sample_rate = 48000;

	//number of samples you want to send for processing in the fft (any)
	//for example 100 samples
	long captured_samples = 1602;

	//frequency of the signal (has to be smaller than sample_rate/2)
	//for example 46
	int frequency = 250;

	//float data[5000] = { 0x00 };

	int datafft[5000] = { 0x00 };
	printf("SAMPLE RATE = [%d] BITS PER SAMPLE = [%d] N SAMPLES = [%d]\n", SAMPLE_RATE, BITS_PER_SAMPLE, N_SAMPLES);

	int *data = (int *)malloc(N_SAMPLES * sizeof(int));

	readPCM(data, SAMPLE_RATE, BITS_PER_SAMPLE, N_SAMPLES);
	float data1[1602] = { 0x00 };
	unsigned int i;
	for (i = 0; i < N_SAMPLES; ++i) {
		printf("%d\n", data[i]);
		data1[i] = (float)(data[i]);
		//data1[i] = data[i];
	}

	fft.ComplexFFT(data1, captured_samples, 9000, 1);

	getchar();
	return 0;

}