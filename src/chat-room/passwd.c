#include<openssl/aes.h>
#include<openssl/evp.h>

unsigned char serectry[]="1234567890";
unsigned char* Encrypt(unsigned char* input,int len)
{
   AES_KEY key;
   EVP_CIPHER_CTX *ctx;
   //init
   ctx=EVP_CIPHER_CTX_new();

}

int main()
{
    return 0;
}