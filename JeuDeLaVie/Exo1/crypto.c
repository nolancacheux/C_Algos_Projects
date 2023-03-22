/*#include <stdio.h>
#include <windows.h>
#include <Wincrypt.h>
#include "GameOfLife.h"

#define BUFSIZE 1024
#define MD5LEN  16



DWORD createmd5(char * life, char fingerprint[FingerprintSize], int lifeNbline, int lifeNbCol)
{
	DWORD dwStatus = 0;
	BOOL bResult = FALSE;
	HCRYPTPROV hProv = 0;
	HCRYPTHASH hHash = 0;
	DWORD cbRead = lifeNbline * lifeNbCol;
	BYTE rgbHash[MD5LEN] = { 0 };
	DWORD cbHash = 0;
	CHAR rgbDigits[] = "0123456789abcdef";

	
	

	// Get handle to the crypto provider
	if (!CryptAcquireContext(&hProv,
		NULL,
		NULL,
		PROV_RSA_FULL,
		CRYPT_VERIFYCONTEXT))
	{
		dwStatus = GetLastError();
		printf("CryptAcquireContext failed: %d\n", dwStatus);
		return dwStatus;
	}

	if (!CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash))
	{
		dwStatus = GetLastError();
		printf("CryptAcquireContext failed: %d\n", dwStatus);
		CryptReleaseContext(hProv, 0);
		return dwStatus;
	}

	

		if (!CryptHashData(hHash, (BYTE *)life, cbRead, 0))
		{
			dwStatus = GetLastError();
			printf("CryptHashData failed: %d\n", dwStatus);
			CryptReleaseContext(hProv, 0);
			CryptDestroyHash(hHash);
			return dwStatus;
		}
	

	
	cbHash = MD5LEN;
	if (CryptGetHashParam(hHash, HP_HASHVAL, rgbHash, &cbHash, 0))
	{
		//printf("MD5 hash of life  is: ");
		for (DWORD i = 0; i < cbHash-1; i++)
		{
			fingerprint[i] = rgbDigits[rgbHash[i] >> 4];
			fingerprint[i+16] = rgbDigits[rgbHash[i] >> 4];
			fingerprint[i+1] = rgbDigits[rgbHash[i] & 0xf];
			fingerprint[i + 1 + 16] = rgbDigits[rgbHash[i] & 0xf];
		}
		//printf("\n");
	}
	else
	{
		dwStatus = GetLastError();
		printf("CryptGetHashParam failed: %d\n", dwStatus);
	}

	CryptDestroyHash(hHash);
	CryptReleaseContext(hProv, 0);
	

return dwStatus;
}*/