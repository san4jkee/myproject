encrypt.o: encrypt.c
	gcc -c encrypt.c -o encrypt.o
checksum.o: checksum.c
	gcc -c checksum.c -o checksum.o
libftsecurity.a: encrypt.o checksum.o
	ar -rcs libftsecurity.a encrypt.o checksum.o
bank_vault: bank_vault.c libftsecurity.a
	gcc bank_vault.c -I. -L. -lftsecurity - bank_vault
