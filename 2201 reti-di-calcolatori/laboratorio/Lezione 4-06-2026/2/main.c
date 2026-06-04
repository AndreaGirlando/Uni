#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>
// HTONL serve per unificare le endianess tra nodi che comunicano
int main() {
	int x = 0x1234567;
	uint8_t buffer[256];
	memcpy(buffer, &x, sizeof(x));
	for (int i = 0; i < sizeof(x); i++) {
		printf("%02hhx ", buffer[i]);
	}
	printf("\n");

	uint32_t network_order = htonl(x); //Converte il byte da quello usato nella macchina al network byte order (littleEndian->bigEndian)
	uint8_t buffer2[256];
	memcpy(buffer2, &network_order, sizeof(network_order));
	for (int i = 0; i < sizeof(network_order); i++) {
		printf("%02hhx ", buffer2[i]);
	}
	printf("\n");

	char text[] = "Hello";
	uint8_t buffer3[256];
	memcpy(buffer3, text, sizeof(text));
	for (int i = 0; i < sizeof(text); i++) {
		printf("%02hhx (%c) ", buffer3[i], buffer3[i]);
	}
	printf("\n");
}