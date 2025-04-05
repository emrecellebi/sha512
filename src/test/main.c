#include "sha512.h"
#include <string.h>

int main(int argc, char** argv)
{	
	if(argc <= 1)
	{
		printf("sha512 : No command specified. Use 'sha512 -h or --help' for a detailed command list");
		return 1;
	}
	
	if(argc == 3 && (strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "--hex") == 0))
	{
		unsigned char res[SHA512_DIGEST_SIZE];
		struct sha512_ctx ctx;
		int i;
		
		FILE* fs;
		const char* data = argv[2];
		if((fs = fopen(data, "rb")) != NULL)
		{
			sha512_stream(fs, res);
			for(i = 0; i < SHA512_DIGEST_SIZE; i++)
				printf("%02x", res[i]);
			fclose(fs);
			return 1;
		}
		
		sha512_init_ctx(&ctx);
		sha512_process_bytes(data, strlen(data), &ctx);
		sha512_finish_ctx(&ctx, res);
		for(i = 0; i < SHA512_DIGEST_SIZE; i++)
			printf("%02x", res[i]);
		
		return 1;
	}
	
	if(argc == 3 && strcmp(argv[1], "--384") == 0)
	{
		unsigned char res[SHA384_DIGEST_SIZE];
		struct sha512_ctx ctx;
		int i;
		
		FILE* fs;
		const char* data = argv[2];
		if((fs = fopen(data, "rb")) != NULL)
		{
			sha384_stream(fs, res);
			for(i = 0; i < SHA384_DIGEST_SIZE; i++)
				printf("%02x", res[i]);
			fclose(fs);
			return 1;
		}
		
		sha384_init_ctx(&ctx);
		sha512_process_bytes(data, strlen(data), &ctx);
		sha384_finish_ctx(&ctx, res);
		for(i = 0; i < SHA384_DIGEST_SIZE; i++)
			printf("%02x", res[i]);
		
		return 1;
	}
	
	if(argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")))
	{
		printf("\nCopyright (c) 2012-2025 Emre Celebi\n\n");
		printf("Usage: sha512 [-options] <parameters>\n");
		printf("      --384 <str>\n");
		printf("  -i, --hex <str>\n");
		printf("  -v, --version\n");
		printf("  -h, --help\n");
		return 1;
	}
	
	if(argc == 2 && (!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version")))
	{
		printf("\nsha512 version: 0.0.2 Pre-Alpha\n");
		printf("Last revised: 05th Apr 2025\n");
		printf("The last version is always avaible\n");
		printf("Created By Emre Celebi\n");
		return 1;
	}
	
	return 0;
}