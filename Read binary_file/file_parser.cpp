#include <stdio.h>
#include <stdlib.h>

//void char2short(unsigned char* pchar, unsigned short* pshort)
//{
//	*pshort = (pchar[0] << 8) | pchar[1];
//}
int main(int argc, char **argv)
{

	int byte_cnt = 0;
	if (argc != 2) 
	{
		printf("usage: %s filename", argv[0]);
	}
	else
	{
		FILE *file = fopen(argv[1], "rb");

		/* fopen returns 0, the NULL pointer, on failure */
		if (file == 0)
		{
			printf("Could not open file\n");
		}
		else
		{
			char size[4] = { 0 };
			//int size;
			char entry_pnt[2] = { 0 };
			char f_len[4] = { 0 };
			char l_len[4] = { 0 };
			int x,y,z,a,b;
			fread(size, 4, 1, file);
			x = (int)size[0];
			printf("%d", x);
			fread(entry_pnt, 2, 1, file);
			y = (int)entry_pnt[0];
			printf("%d", y);

			for (int i = 0; i < y; i++)
			{
				fread(f_len, 4, 1, file);
				z = (int)f_len[0];
				printf("%d", z);
				char *name = (char*)malloc(z + 1);
				fread(name, z, 1, file);
				name[z] = '\0';
				printf("%s", name);

				fread(l_len, 4, 1, file);
				a = (int)l_len[0];
				printf("%d", a);
				char *last_name = (char*)malloc(a + 1);
				fread(last_name, a, 1, file);
				last_name[a] = '\0';
				printf("%s", last_name);

				char *flag, *age, *height;
				flag = (char *)malloc(sizeof(char));
				age = (char *)malloc(sizeof(char));
				height = (char *)malloc(sizeof(char));
				byte_cnt = z + a;
				fread(flag, 1, 1, file);
				printf("%d", *flag);
				byte_cnt = byte_cnt + 1;
				if (*flag == 1)
				{
					fread(age, 1, 1, file);
					byte_cnt = byte_cnt + 1;
					printf("%d", *age);
				}

				if (*flag == 2)
				{
					//fread(age, 1, 1, file);
					fread(height, 1, 1, file);
					byte_cnt = byte_cnt + 1;
					printf("%d ", *height);
				}

				if (*flag == 3)
				{
					fread(age, 1, 1, file);
					byte_cnt = byte_cnt + 1;
					fread(height, 1, 1, file);
					byte_cnt = byte_cnt + 1;
					printf("%d  %d", *age, *height);
				}
			}
			printf("%d", byte_cnt);
			if (byte_cnt % 4 != 0)
			{
				fseek(file, byte_cnt % 4, SEEK_CUR);
			}
			
			char check[4] = { 0 };
			fread(check, 4, 1, file);
			b = (int)check[0];
			printf("%d", b);

			//int len;

			//char2short(f_len,len);
			//printf("%d", len);
			//int x;
			//while ((x = fgetc(file)) != EOF)
			//{
			//	printf("%c", x);
			//}
			fclose(file);
		}
	}

	return 0;
}
