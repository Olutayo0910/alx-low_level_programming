#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <stdlib.h>
/**
 * print_entry_point_address - prints address for entry point
 * @magic: ELF magic.
 *
 * Return: no return.
 */
void print_entry_point_address(char *magic)
{
	int i;
	int begin;
	char sys;

	printf("  Entry point address:               0x");

	sys = magic[4] + '0';
	if (sys == '1')
	{
		begin = 26;
		printf("80");
		for (i = begin; i >= 22; i--)
		{
			if (magic[i] > 0)
				printf("%x", magic[i]);
			else if (magic[i] < 0)
				printf("%x", 256 + magic[i]);
		}
		if (magic[7] == 6)
			printf("00");
	}

	if (sys == '2')
	{
		begin = 26;
		for (i = begin; i > 23; i--)
		{
			if (magic[i] >= 0)
				printf("%02x", magic[i]);
			else if (magic[i] < 0)
				printf("%02x", 256 + magic[i]);
		}
	}
	printf("\n");
}

/**
 * print_type - prints the type
 * @magic: ELF magic.
 *
 * Return: no return.
 */
void print_type(char *magic)
{
	char type;

	if (magic[5] == 1)
		type = magic[16];
	else
		type = magic[17];

	printf("  Type:                              ");
	if (type == 0)
		printf("NONE (No file type)\n");
	else if (type == 1)
		printf("REL (Relocatable file)\n");
	else if (type == 2)
		printf("EXEC (Executable file)\n");
	else if (type == 3)
		printf("DYN (Shared object file)\n");
	else if (type == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", type);
}

/**
 * print_osabi - prints the osabi
 * @magic: ELF magic.
 *
 * Return: no return.
 */
void print_osabi(char *magic)
{
	char osabi = magic[7];

	printf("  OS/ABI:                            ");
	if (osabi == 0)
		printf("UNIX - System V\n");
	else if (osabi == 2)
		printf("UNIX - NetBSD\n");
	else if (osabi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", osabi);

	printf("  ABI Version:                       %d\n", magic[8]);
}

/**
 * print_version - prints the version
 * @magic: ELF magic.
 *
 * Return: no return.
 */
void print_version(char *magic)
{
	int version = magic[6];

	printf("  Version:                           %d", version);

	if (version == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}

/**
 * print_data - prints the data
 * @magic: ELF magic.
 *
 * Return: no return.
 */
void print_data(char *magic)
{
	char data = magic[5];

	printf("  Data:                              2's complement");
	if (data == 1)
		printf(", little endian\n");
	if (data == 2)
		printf(", big endian\n");
}

/**
 * print_magic - prints magic info.
 * @magic: ELF magic.
 *
 * Return: no return.
 */
void print_magic(char *magic)
{
	int bytes;

	printf("  Magic:  ");

	for (bytes = 0; bytes < 16; bytes++)
		printf(" %02x", magic[bytes]);

	printf("\n");
}

/**
 * check_sys - check the version system.
 * @magic: ELF magic.
 *
 * Return: no return.
 */
void check_sys(char *magic)
{
	char sys = magic[4] + '0';

	if (sys == '0')
		exit(98);

	printf("ELF Header:\n");
	print_magic(magic);

	if (sys == '1')
		printf("  Class:                             ELF32\n");

	if (sys == '2')
		printf("  Class:                             ELF64\n");

	print_data(magic);
	print_version(magic);
	print_osabi(magic);
	print_type(magic);
	print_entry_point_address(magic);
}

/**
 * check_elf - check if it is an elf file.
 * @magic: ELF magic.
 *
 * Return: 1 if it is an elf file, 0 if not.
 */
int check_elf(char *magic)
{
	int addr = (int)magic[0];
	char E = magic[1];
	char L = magic[2];
	char F = magic[3];

	if (addr == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}

/**
 * main - check the code.
 * @argc: number of arguments.
 * @argv: arguments vector.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int fd, ret_read;
	char magic[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Err: file can not be open\n");
		exit(98);
	}

	lseek(fd, 0, SEEK_SET);
	ret_read = read(fd, magic, 27);

	if (ret_read == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file can not be read\n");
		exit(98);
	}

	if (!check_elf(magic))
	{
		dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
		exit(98);
	}

	check_sys(magic);
	close(fd);

	return (0);
}
