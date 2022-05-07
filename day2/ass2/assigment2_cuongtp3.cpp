#include <iostream>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>

#define ERROR -1
#define SUCCESS 0

#define OPEN_FILE_FAIL 1
#define ALLOWCATE_FAIL 2

#define MAX_LEN_BUF 1024

using namespace std;

#pragma pack(push,1)

typedef struct BMPHeader{
    uint16_t type;              // Magic identifier: 0x4d42
    uint32_t size;              // File size in bytes
    uint16_t reserved1;         // Not used
    uint16_t reserved2;         // Not used
    uint32_t offset;            // Offset to image data in bytes from beginning of file
    uint32_t dib_header_size;   // DIB Header size in bytes
    int32_t  width_px;          // Width of the image
    int32_t  height_px;         // Height of image
    uint16_t num_planes;        // Number of color planes
    uint16_t bits_per_pixel;    // Bits per pixel
    uint32_t compression;       // Compression type
    uint32_t image_size_bytes;  // Image size in bytes
    int32_t  x_resolution_ppm;  // Pixels per meter
    int32_t  y_resolution_ppm;  // Pixels per meter
    uint32_t num_colors;        // Number of colors
    uint32_t important_colors;  // Important colors
} BMPHeader_t;

#pragma pack(pop)

bool bmp_reverse(const char* bmp_path, const char* reserved_bmp_path);
int makeACoppy(int fd_org_file, int fd_coppy_file);

int main()
{
	int err;
	int option;
	const char *imagePath = "test.bmp";
	const char *imagePath2 = "barbara_gray.bmp";
	const char *imageOutPath = "out_put.bmp";
	
	cout << "1.test.bmp\n2.barbara_gray.bmp\nEnter index picture need to convert: ";
	cin >> option;
	
	switch(option)
	{
		case 1:
			err = bmp_reverse(imagePath, imageOutPath);
			break;
			
		case 2:
			err = bmp_reverse(imagePath2, imageOutPath);
			break;
		
		default:
			cout << "Chose again!";
			break;
	}
		
	if(err == SUCCESS)
		cout << "Convert complete!\n";
	
	return 0;
}

bool bmp_reverse(const char* bmp_path, const char* reserved_bmp_path)
{
	bool err = ERROR;
	
	int fd = -1;
	int fd2 = -1;
	int len = 0;
	BMPHeader_t bmp_header;
	char *image_data = NULL;
	char temp;
	
	fd = open(bmp_path, O_RDONLY);
	if(fd == -1)
	{
		cout << "Fail to open file" << endl;
		return ERROR;
	}
	
	fd2 = open(reserved_bmp_path, O_CREAT | O_RDWR);
	if(fd2 == -1)
	{
		cout << "Fail to open file 2" << endl;
		cout << "File \"out_put.bmp\" exited, delete it!" << endl;
		return ERROR;
	}
	
	len = read(fd, &bmp_header, sizeof(BMPHeader_t));
	if(len == -1)
	{
		cout << "Read bmp_header error" << endl;
		return ERROR;
	}
	int len_image = bmp_header.width_px * bmp_header.height_px;
	image_data = new char[len_image];
	
	char arr[bmp_header.width_px][bmp_header.height_px];
	int a;
	char arr2[a];
	if(NULL == image_data)
	{
		cout << "Fail to alocate image_data" << endl;
		return ERROR;
	}
	
	lseek(fd, bmp_header.offset, SEEK_SET);
	
	len = read(fd, image_data, len_image);
	if(len == -1)
	{
		cout << "Read bmp_data error" << endl;
		return ERROR;
	}

//	for(i = 0; i < len_image / 2; i++)
//	{
//		temp = image_data[i];
//		image_data[i] = image_data[len_image - i];
//		image_data[len_image - i] = temp;
//	}

	for (int col = 0; col < bmp_header.width_px; col++)
	{
		for (int row = 0; row <= bmp_header.height_px / 2; row++)
		{
			char tmp = image_data[row * bmp_header.width_px + col];
			image_data[row * bmp_header.width_px + col] = image_data[(bmp_header.height_px - 1 - row) * bmp_header.width_px + col];
			image_data[(bmp_header.height_px - 1 - row) * bmp_header.width_px + col] = tmp;
		}
	}
//
//	printf("%x/", image_data[0]);
//	printf("%x", image_data[len_image]);

	makeACoppy(fd, fd2);
	
	lseek(fd2, bmp_header.offset, SEEK_SET);
	len = write(fd2, image_data, len_image);

	close(fd);
	close(fd2);
	
	return err = SUCCESS;
}

int makeACoppy(int fd_org_file, int fd_coppy_file)
{
	int len = 0;
	char *p_buf = NULL;
	int error;
	
	p_buf = new char[MAX_LEN_BUF];
	if(p_buf == NULL)
	{
		return error = ALLOWCATE_FAIL;
	}
	
	lseek(fd_org_file, 0, SEEK_SET);
	
	do
	{
		len = read(fd_org_file, p_buf, MAX_LEN_BUF);
		write(fd_coppy_file, p_buf, MAX_LEN_BUF);
	}
	while(len != 0);
	
	return error = SUCCESS;
}

