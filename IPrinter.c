#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>

int main() {
    char website[100];
    printf("Enter the website URL: ");
    scanf("%s", website);

    struct hostent *host_info;
    struct in_addr **address_list;
    int i;

    host_info = gethostbyname(website);

    if (host_info == NULL) {
        printf("Couldn't resolve '%s'\n", website);
    } else {
        address_list = (struct in_addr **)host_info->h_addr_list;

        printf("IP addresses for %s:\n", website);
        for (i = 0; address_list[i] != NULL; i++) {
            printf("%s\n", inet_ntoa(*address_list[i]));
        }
    }

    return 0;
}
