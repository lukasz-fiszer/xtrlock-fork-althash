#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <crypt.h>
#include <openssl/rand.h>

const int HASH_ID = 6;
const int SALT_LENGTH = 8;
const char* ALTHASH_FILENAME = "althash.txt";


int main(int argc, char** argv)
{
	if(argc != 2)
	{
		puts("Usage: generate-althash [passphrase]");
		return 1;
	}

	char* passphrase = argv[1];
	char salt[SALT_LENGTH+1];
	salt[SALT_LENGTH] = '\0';

	for(int i = 0; i < SALT_LENGTH; i++)
	{
		unsigned char randbyte;
		RAND_bytes(&randbyte, 1);
		while(isalnum(randbyte) == false)
		{
			RAND_bytes(&randbyte, 1);
		}
		salt[i] = randbyte;
	}

	char crypt_param[32];
	sprintf(crypt_param, "$%d$%s$", HASH_ID, salt);

	char* hash = crypt(passphrase, crypt_param);

	FILE* fp = fopen(ALTHASH_FILENAME, "w");
	if(fp == NULL)
	{
		puts("Error opening file");
		exit(1);
	}

	fputs(hash, fp);
	fclose(fp);

	return 0;
}