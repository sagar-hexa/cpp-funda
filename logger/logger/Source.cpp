
//logger.h
void log_print(char* filename, int line, char *fmt, ...);

#define doFreqLogsInFile 1
#define doLatencyMeasLogsInFile 1

#if (doFreqLogsInFile == 0)
#define  INFO_FREQ_PRINT  printf
#else
#define INFO_FREQ_PRINT(...) log_print(__FILE__, __LINE__, __VA_ARGS__ )
#endif

#if (doLatencyMeasLogsInFile == 0)
#define  INFO_LATENCY_PRINT  printf
#else
#define INFO_LATENCY_PRINT(...) log_print(__FILE__, __LINE__, __VA_ARGS__ )
#endif






//logger.c
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
//test.c
#include <stdio.h>

FILE *fp;
static int SESSION_TRACKER; //Keeps track of session

//char* print_time()
//{
//	int size = 0;
//	time_t t;
//	char *buf;
//
//	t = time(NULL); /* get current calendar time */
//
//	char *timestr = asctime_s(localtime(&t));
//	timestr[strlen(timestr) - 1] = 0;  //Getting rid of \n
//
//	size = strlen(timestr) + 1 + 2; //Additional +2 for square braces
//	buf = (char*)malloc(size);
//
//	memset(buf, 0x0, size);
//	snprintf(buf, size, "[%s]", timestr);
//
//	return buf;
//}
void log_print(char* filename, int line, char *fmt, ...)
{
	va_list         list;
	char            *p, *r;
	int             e;
	float e1;  // assign type whatever pass
	if (SESSION_TRACKER > 0)
		fopen_s(&fp, "log.txt", "a+");
	else
		fopen_s(&fp, "log.txt", "w");

	//fprintf(fp, "%s ", print_time());
	//fprintf(fp, "[%s][line: %d] ", filename, line);
	va_start(list, fmt);

	for (p = fmt; *p; ++p)
	{
		if (*p != '%')//If simple string
		{
			fputc(*p, fp);
		}
		else
		{
			switch (*++p)
			{
				/* string */
			case 's':
			{
						r = va_arg(list, char *);

						fprintf(fp, "%s", r);
						continue;
			}

				/* integer */
			case 'd':
			{
						e = va_arg(list, int);

						fprintf(fp, "%d", e);
						continue;
			}

				/* double */
			case 'g':
			{
						e1 = va_arg(list, double);

						fprintf(fp, "%g", e1);
						continue;
			}
			

			default:
				fputc(*p, fp);
			}
		}
	}
	va_end(list);
	fputc('\n', fp);
	SESSION_TRACKER++;
	fclose(fp);
}



int main()
{

	float x = 199.25, i = 0;
	char *s = "Bitter Truth";
	int test = 120;
	double check = 122.22;
	while (i<5)
	{
		INFO_FREQ_PRINT("Hello World ");
		INFO_LATENCY_PRINT("Zing is back !!! %s %g", s, x++,test);
		i++;
	}

	getchar();
}


//pass %g for float , %lf for double 